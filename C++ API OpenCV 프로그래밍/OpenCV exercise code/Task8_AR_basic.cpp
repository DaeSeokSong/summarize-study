#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

#define ROI_WIDTH 325
#define ROI_HEIGHT 450

using namespace std;
using namespace cv;

void ROI_ExtractKeypoints(int mode, Mat ROI, vector<KeyPoint>* keypoints);
void alphaBlend(Mat& foreground, Mat& background, Mat& alpha, Mat& outImage);

// Descriptor
const Ptr<xfeatures2d::SURF> surF = xfeatures2d::SURF::create(500, 4, 4);	// mode, 49
const Ptr<SIFT> siftF = SIFT::create(15);									// mode, 50

int main() {
	// Init camera
	VideoCapture camera;
	camera.open(0);
	if (!camera.isOpened()) {
		cout << "■□■□■□ 카메라 인식 실패 ■□■□■□" << endl;
		return -1;
	}

	// AR image
	Mat arImg = imread("D:\\example\\dataset\\pikachu.png");
	if (arImg.empty()) {
		cout << "■□■□■□ 이미지 불러오기 실패 ■□■□■□" << endl;
		return -1;
	}

	// BGR
	Mat frame;

	// HSV
	vector<cv::Mat> planes;

	// ROI
	Rect roi((camera.get(cv::CAP_PROP_FRAME_WIDTH) / 2) - (ROI_WIDTH / 2), (camera.get(cv::CAP_PROP_FRAME_HEIGHT) / 2) - (ROI_HEIGHT / 2), ROI_WIDTH, ROI_HEIGHT);
	Mat roiF;

	// Histogram
	int histSize = 256;
	float hValue[] = { 0, 256 };
	const float* ranges[] = { hValue };
	int channels = 0;
	int dims = 1;
	Mat histAR;
	Mat backProject;
	calcHist(&arImg, 1, &channels, cv::Mat(), histAR, dims, &histSize, ranges);

	// Descriptor
	vector<KeyPoint> keypointsMtc, keypointsSrc;
	Mat descriptorMtc, descriptorSrc;
	int modeFlag = 49;

	// Matcher
	vector<DMatch> matches;
	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("FlannBased");

	// ETC
	char inputKey = 0;

	while (true) {
		// Get frame
		camera >> frame;
		if (frame.empty()) break;

		// ROI project
		cv::rectangle(frame, roi, cv::Scalar(0, 0, 255), 2);

		if (!roiF.empty())
		{
			switch (modeFlag)
			{
			case 49:
				surF->compute(roiF, keypointsMtc, descriptorMtc);
				surF->detectAndCompute(frame, noArray(), keypointsSrc, descriptorSrc);
				break;
			case 50:
				siftF->compute(roiF, keypointsMtc, descriptorMtc);
				siftF->detectAndCompute(frame, noArray(), keypointsSrc, descriptorSrc);
				break;
			}

			matcher->match(descriptorMtc, descriptorSrc, matches);
			if (matches.size() < 4) continue;

			// NORM_L2 최단거리 구하기
			double minDist;
			minDist = matches[0].distance;
			for (int i = 1; i < matches.size(); i++)
			{
				double dist = matches[i].distance;
				if (dist < minDist) minDist = dist;
			}

			Mat imgMatches;
			vector<DMatch> goodMatches;
			double fTh = 8 * minDist;
			for (int i = 0; i < matches.size(); i++)
			{
				if (matches[i].distance <= max(fTh, 0.02))
					goodMatches.push_back(matches[i]);
			}
			if (goodMatches.size() < 4) continue;

			vector<Point2f> obj;
			vector<Point2f> scene;
			for (int i = 0; i < goodMatches.size(); i++)
			{
				obj.push_back(keypointsMtc[goodMatches[i].queryIdx].pt);
				scene.push_back(keypointsSrc[goodMatches[i].trainIdx].pt);
			}
			Mat H = findHomography(obj, scene, RANSAC);

			vector<Point2f> objP(4);
			objP[0] = Point(0, 0);
			objP[1] = Point(roiF.cols, 0);
			objP[2] = Point(roiF.cols, roiF.rows);
			objP[3] = Point(0, roiF.rows);

			vector<Point2f> sceneP(4);
			vector<Point2f> AR_sceneP(4);
			try
			{
				perspectiveTransform(objP, sceneP, H);
				AR_sceneP = sceneP;

				drawMatches(roiF, keypointsMtc, frame, keypointsSrc, goodMatches, imgMatches,
					Scalar::all(-1), Scalar::all(-1), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

				for (int i = 0; i < 4; i++) sceneP[i] += Point2f(roiF.cols, 0);
				for (int i = 0; i < 4; i++)
				{
					if (i == 0) line(imgMatches, sceneP[i], sceneP[(i + 1) % 4], Scalar(0, 255, 0), 4);
					else line(imgMatches, sceneP[i], sceneP[(i + 1) % 4], Scalar(255, 0, 0), 4);
				}
			}
			catch (const exception& e)
			{
				continue;
			}

			// AR
			Mat persArImg;
			warpPerspective(arImg, persArImg, H, Size(frame.cols + roiF.cols, frame.rows));
			resize(persArImg, persArImg, Size(persArImg.cols - 40, persArImg.rows - 40));
			copyMakeBorder(persArImg, persArImg, 20, 20, 20, 20, BORDER_CONSTANT, 0);

			Mat affinedArImg;
			float tx = float(roiF.cols);
			float ty = 0.f;
			float warp_values[] = { 1.0, 0.0, tx, 0.0, 1.0, ty };
			Mat translation_matrix = Mat(2, 3, CV_32F, warp_values);
			warpAffine(persArImg, affinedArImg, translation_matrix, persArImg.size());

			Mat binMaskImg;
			Mat maskImg(affinedArImg.size(), affinedArImg.type(), Scalar(0, 255, 0));
			multiply(Scalar::all(1) - affinedArImg, maskImg, maskImg);
			add(affinedArImg, maskImg, maskImg);

			Mat hsvMaskImg;
			Mat hueMaskImg;
			cvtColor(maskImg, hsvMaskImg, cv::COLOR_BGR2HSV);
			split(hsvMaskImg, planes);
			planes[0].copyTo(hueMaskImg);
			calcBackProject(&hueMaskImg, 1, &channels, histAR, backProject, ranges);
			normalize(backProject, backProject, 0, 255, cv::NORM_MINMAX, CV_8U);
			bitwise_and(maskImg, maskImg, binMaskImg, backProject);
			imshow("Display <binMaskImg>", binMaskImg);

			multiply(maskImg, affinedArImg, affinedArImg);
			multiply(Scalar::all(1) - imgMatches, maskImg, maskImg);

			Mat resArImgMul = Mat::zeros(affinedArImg.size(), affinedArImg.type());
			//Mat resArImgFunc = Mat::zeros(affinedArImg.size(), affinedArImg.type());
			add(affinedArImg, imgMatches, resArImgMul);
			//alphaBlend(affinedArImg, imgMatches, binArImg, resArImgFunc);

			imshow("Display <RESULT>", resArImgMul);
			//imshow("Display <RESULT_FUNC>", resArImgFunc);
		}
		else
		{
			imshow("Display <RESULT>", frame);
		}

		inputKey = cv::waitKey(1);
		if (inputKey == 27) break;
		else if (inputKey == 99 || inputKey == 67)
		{
			frame(roi).copyTo(roiF);

			resize(arImg, arImg, Size(roiF.cols, roiF.rows));

			vector<Point2f> objP(4);
			objP[0] = Point(0, 0);
			objP[1] = Point(roiF.cols, 0);
			objP[2] = Point(roiF.cols, roiF.rows);
			objP[3] = Point(0, roiF.rows);

			for (int i = 0; i < 4; i++)
			{
				if (i == 0) line(roiF, objP[i], objP[(i + 1) % 4], Scalar(0, 255, 0), 4);
				else line(roiF, objP[i], objP[(i + 1) % 4], Scalar(255, 0, 0), 4);
			}

			ROI_ExtractKeypoints(modeFlag, roiF, &keypointsMtc);
		}
		else if (inputKey == 49 || inputKey == 50)
		{
			modeFlag = inputKey;
			if (!roiF.empty())
			{
				ROI_ExtractKeypoints(modeFlag, roiF, &keypointsMtc);
			}
		}
	}

	return 0;
}

void ROI_ExtractKeypoints(int mode, Mat ROI, vector<KeyPoint>* keypoints)
{
	switch (mode)
	{
	case 49:
		surF->detect(ROI, *keypoints);
		break;
	case 50:
		siftF->detect(ROI, *keypoints);
		break;
	}
}

void alphaBlend(Mat& foreground, Mat& background, Mat& alpha, Mat& outImage)
{
	// Find number of pixels.
	int numberOfPixels = foreground.rows * foreground.cols * foreground.channels();

	// Get floating point pointers to the data matrices
	float* fptr = reinterpret_cast<float*>(foreground.data);
	float* bptr = reinterpret_cast<float*>(background.data);
	float* aptr = reinterpret_cast<float*>(alpha.data);
	float* outImagePtr = reinterpret_cast<float*>(outImage.data);

	// Loop over all pixesl ONCE
	for (int i = 0; i < numberOfPixels; i++, outImagePtr++, fptr++, aptr++, bptr++)
	{
		*outImagePtr = (*fptr) * (*aptr) + (*bptr) * (1 - *aptr);
	}
}