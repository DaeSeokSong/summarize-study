#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

vector<Point2f> FindLocalMaxima(Mat& src);

int main()
{
	Mat srcImg = imread("D:\\example\\dataset\\life\\bookcover.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	int blockSize = 5;
	int ksize = 3;
	double k = 0.01;

	Mat R;
	cornerHarris(srcImg, R, blockSize, ksize, k);
	threshold(R, R, 0.01, 0, THRESH_TOZERO);

	vector<Point2f> cornerPoints = FindLocalMaxima(R);

	// cornerSubPix
	// 입력영상에서 검출된 코너점을 입력으로 하여, 코너점의 위치를 서브픽셀(부화소) 단위로 계산하여 다시 코너를 저장하여 반환한다.
	// 즉, 부화소 단위로 코너점을 검출하는 함수이다.
	// winSize는 탐색 영역의 크기, (3*3 -> (3*2 + 1) * (3*2 + 1)이 탐색 영역,
	// zeroSize는 winSize 영역 내에서 해당 영역을 마스크 처리하여 탐색 영역에서 계산하지 않는다.
	Size winSize(3, 3);
	Size zeroSize(-1, -1);
	TermCriteria criteria(TermCriteria::COUNT + TermCriteria::EPS, 10, 0.01);
	cornerSubPix(srcImg, cornerPoints, winSize, zeroSize, criteria);

	Mat dstImg(srcImg.size(), CV_8UC3);
	cvtColor(srcImg, dstImg, COLOR_GRAY2BGR);

	vector<Point2f>::const_iterator it;
	for (it = cornerPoints.begin(); it != cornerPoints.end(); ++it)
	{
		circle(dstImg, *it, 5, Scalar(127, 0, 127), 2);
		int x = (*it).x;
		int y = (*it).y;
		float fValue = R.at<float>(y, x);
	}
	imshow("dstImg", dstImg);

	waitKey(0);
	return 0;
}

vector<Point2f> FindLocalMaxima(Mat& src)
{
	Mat dilated;
	Mat localMax;
	Size size(11, 11);
	Mat rectKernel = getStructuringElement(MORPH_RECT, size);

	dilate(src, dilated, rectKernel);
	localMax = (src == dilated);

	Mat eroded;
	Mat localMin;

	erode(src, eroded, rectKernel);
	localMin = (src > eroded);

	localMax = (localMax & localMin);

	vector<Point2f> points;
	for (int y = 0; y < localMax.rows; y++)
	{
		for (int x = 0; x < localMax.cols; x++)
		{
			uchar uValue = localMax.at<uchar>(y, x);
			if (uValue) points.push_back(Point2f(x, y));
		}
	}

	return points;
}