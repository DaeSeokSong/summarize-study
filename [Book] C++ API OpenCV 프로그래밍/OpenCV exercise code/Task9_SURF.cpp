#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

#define ROI_WIDTH 325
#define ROI_HEIGHT 450

using namespace std;
using namespace cv;

int main() {
	VideoCapture camera;
	camera.open(0);
	if (!camera.isOpened()) {
		cout << "■□■□■□ 카메라 인식 실패 ■□■□■□" << endl;
		return -1;
	}

	// Descriptor
	double thSURF = 3000;
	vector<KeyPoint> keypointsTmpSURF, keypointsSrcSURF;
	Mat descriptorTmpSURF, descriptorSrcSURF;
	Ptr<xfeatures2d::SURF> surF = xfeatures2d::SURF::create(thSURF, 4, 3);

	// Matcher
	vector<DMatch> matchesSURF;
	Ptr<DescriptorMatcher> matcherSURF = DescriptorMatcher::create("FlannBased");

	// BGR
	Mat frame;

	// ROI
	Rect roi((camera.get(cv::CAP_PROP_FRAME_WIDTH) / 2) - (ROI_WIDTH / 2), (camera.get(cv::CAP_PROP_FRAME_HEIGHT) / 2) - (ROI_HEIGHT / 2), ROI_WIDTH, ROI_HEIGHT);
	Mat roiF;

	// ETC
	char inputKey = 0;

	while (true) {
		camera >> frame;
		if (frame.empty()) break;

		// ROI project
		cv::rectangle(frame, roi, cv::Scalar(0, 0, 255), 2);

		if (!roiF.empty())
		{
			surF->compute(roiF, keypointsTmpSURF, descriptorTmpSURF);
			surF->detectAndCompute(frame, noArray(), keypointsSrcSURF, descriptorSrcSURF);

			cout << "SURF's keypointsSrc.size() = " << keypointsSrcSURF.size() << endl;

			matcherSURF->match(descriptorTmpSURF, descriptorSrcSURF, matchesSURF);
			if (matchesSURF.size() < 4) continue;

			double minDist;
			minDist = matchesSURF[0].distance;
			for (int i = 1; i < matchesSURF.size(); i++)
			{
				double dist = matchesSURF[i].distance;
				if (dist < minDist) minDist = dist;
			}

			Mat imgMatches;
			vector<DMatch> goodMatches;
			double fTh = 8 * minDist;
			for (int i = 0; i < matchesSURF.size(); i++)
			{
				if (matchesSURF[i].distance <= max(fTh, 0.02))
					goodMatches.push_back(matchesSURF[i]);
			}
			if (goodMatches.size() < 4) continue;

			vector<Point2f> obj;
			vector<Point2f> scene;
			for (int i = 0; i < goodMatches.size(); i++)
			{
				obj.push_back(keypointsTmpSURF[goodMatches[i].queryIdx].pt);
				scene.push_back(keypointsSrcSURF[goodMatches[i].trainIdx].pt);
			}
			Mat H = findHomography(obj, scene, RANSAC);

			vector<Point2f> objP(4);
			objP[0] = Point(0, 0);
			objP[1] = Point(roiF.cols, 0);
			objP[2] = Point(roiF.cols, roiF.rows);
			objP[3] = Point(0, roiF.rows);

			vector<Point2f> sceneP(4);
			try
			{
				perspectiveTransform(objP, sceneP, H);

				drawMatches(roiF, keypointsTmpSURF, frame, keypointsSrcSURF, goodMatches, imgMatches,
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

			imshow("Display <SURF>", imgMatches);
		}
		else
		{
			imshow("Display <SURF>", frame);
		}

		inputKey = cv::waitKey(1);
		if (inputKey == 27) break;
		else if (inputKey == 99 || inputKey == 67)
		{
			frame(roi).copyTo(roiF);

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

			surF->detect(roiF, keypointsTmpSURF);
		}
	}

	return 0;
}