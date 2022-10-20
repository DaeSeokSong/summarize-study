/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	// Init camera
	VideoCapture camera;
	camera.open(0);
	if (!camera.isOpened())
	{
		cout << "■□■□■□ 카메라 인식 실패 ■□■□■□" << endl;
		return -1;
	}

	// BGR
	Mat frame;

	// HSV
	Scalar lowerb(0, 40, 0);
	Scalar upperb(20, 180, 255);

	// Morphology
	Mat morphK = getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

	// Contour
	vector<vector<Point>> contours;

	while (true)
	{
		camera >> frame;
		if (frame.empty()) break;

		// Convert BGR to HSV
		Mat hsvFrame;
		cvtColor(frame, hsvFrame, COLOR_BGR2HSV);
		morphologyEx(hsvFrame, hsvFrame, MORPH_OPEN, morphK);
		imshow("hsvFrame", hsvFrame);

		// Compute inRange
		Mat binHand;
		inRange(hsvFrame, lowerb, upperb, binHand);
		imshow("binHand", binHand);

		// Find contours
		findContours(binHand, contours, noArray() , RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

		// If don't find contour, skip draw circle
		if (contours.size() >= 1)
		{
			// Find the biggest area in contours
			int maxK = 0;
			double maxArea = contourArea(contours[0]);
			for (int k = 1; k < contours.size(); k++)
			{
				double area = contourArea(contours[k]);
				if (area > maxArea)
				{
					maxK = k;
					maxArea = area;
				}
			}

			// If any contours's area are not bigger than 10000, skip draw circle
			if (maxArea > 10000)
			{
				// the biggest area is supposed hand
				vector<Point> handContour = contours[maxK];

				if (!handContour.empty())
				{
					// Find convex hull
					vector<int> hull;
					convexHull(handContour, hull);

					// Find convex hull of hand
					vector<Point> ptsHull;
					for (int k = 0; k < hull.size(); k++) ptsHull.push_back(handContour[hull[k]]);

					// Find convex hull's defects
					vector<Vec4i> defects;
					try
					{
						convexityDefects(handContour, hull, defects);
					}
					catch (const exception& e)
					{
						cout << "[SKIP] ERROR. About detect defects of hull" << endl;
						continue;
					}

					// Draw circle
					for (int k = 0; k < defects.size(); k++)
					{
						Vec4i v = defects[k];
						Point ptStart = handContour[v[0]];
						Point ptEnd = handContour[v[1]];
						Point ptFar = handContour[v[2]];
						float depth = v[3] / 256.0;
						if (depth > 10)
						{
							circle(frame, ptStart, 8, Scalar(255, 0, 0), 2);
							circle(frame, ptEnd, 8, Scalar(0, 255, 0), 2);
							circle(frame, ptFar, 8, Scalar(0, 0, 255), 2);
						}
					}
				}
			}
		}

		// Show result
		imshow("Display <ORIGIN>", frame);

		// Input key
		char inputKey = waitKey(1);
		if (inputKey == 27) break;
	}

	return 0;
}
*/