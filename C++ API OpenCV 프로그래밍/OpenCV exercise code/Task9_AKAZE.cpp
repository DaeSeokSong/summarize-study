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
	float thAKAZE = 0.0025;
	vector<KeyPoint> keypointsTmpAKAZE, keypointsSrcAKAZE;
	Mat descriptorTmpAKAZE, descriptorSrcAKAZE;
	Ptr<AKAZE> kazeF = AKAZE::create(AKAZE::DESCRIPTOR_KAZE, 0, 3, thAKAZE, 4, 4);

	// Matcher
	vector<DMatch> matchesAKAZE;
	Ptr<DescriptorMatcher> matcherAKAZE = DescriptorMatcher::create("FlannBased");

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
			kazeF->compute(roiF, keypointsTmpAKAZE, descriptorTmpAKAZE);
			kazeF->detectAndCompute(frame, noArray(), keypointsSrcAKAZE, descriptorSrcAKAZE);

			cout << "AKAZE's keypointsSrcAKAZE.size() = " << keypointsSrcAKAZE.size() << endl;

			matcherAKAZE->match(descriptorTmpAKAZE, descriptorSrcAKAZE, matchesAKAZE);
			if (matchesAKAZE.size() < 4) continue;

			double minDist;
			minDist = matchesAKAZE[0].distance;
			for (int i = 1; i < matchesAKAZE.size(); i++)
			{
				double dist = matchesAKAZE[i].distance;
				if (dist < minDist) minDist = dist;
			}

			Mat imgMatches;
			vector<DMatch> goodMatches;
			double fTh = 8 * minDist;
			for (int i = 0; i < matchesAKAZE.size(); i++)
			{
				if (matchesAKAZE[i].distance <= max(fTh, 0.02))
					goodMatches.push_back(matchesAKAZE[i]);
			}
			if (goodMatches.size() < 4) continue;

			vector<Point2f> obj;
			vector<Point2f> scene;
			for (int i = 0; i < goodMatches.size(); i++)
			{
				obj.push_back(keypointsTmpAKAZE[goodMatches[i].queryIdx].pt);
				scene.push_back(keypointsSrcAKAZE[goodMatches[i].trainIdx].pt);
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

				drawMatches(roiF, keypointsTmpAKAZE, frame, keypointsSrcAKAZE, goodMatches, imgMatches,
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

			imshow("Display <AKAZE>", imgMatches);
		}
		else
		{
			imshow("Display <AKAZE>", frame);
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

			kazeF->detect(roiF, keypointsTmpAKAZE);
		}
	}

	return 0;
}