/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 템플릿 매칭
// 참조 영상에서 템플릿 영상과 매칭되는 위치를 탐색하는 방법이다. 템플릿 매칭은 물체 인식, 스테레오 영상에서 대응점 검출 등에 사용될 수 있다.
// 참조 영상의 (0, 0) 위치에 템플릿 영상의 (0, 0)을 맞추고 래스터 주사 순서로 왼쪽부터 오른쪽, 위부터 아래를 시작 엣지부터 끝 엣지까지 옮길 때 마다 템플릿 영상과 템플릿 영상의 해당 위치에 있는 참조 영상의 화소값을 비교하여 연산한다.
int main() {
	Mat srcImg = imread("D:\\example\\dataset\\alphabets\\alphabet_full.png", IMREAD_GRAYSCALE);
	if (srcImg.empty()) return -1;

	Mat tImg1 = imread("D:\\example\\dataset\\alphabets\\A.png", IMREAD_GRAYSCALE);
	Mat tImg2 = imread("D:\\example\\dataset\\alphabets\\S.png", IMREAD_GRAYSCALE);
	Mat tImg3 = imread("D:\\example\\dataset\\alphabets\\p.png", IMREAD_GRAYSCALE);
	Mat tImg4 = imread("D:\\example\\dataset\\alphabets\\vwx.png", IMREAD_GRAYSCALE);
	Mat tImg5 = imread("D:\\example\\dataset\\alphabets\\I.png", IMREAD_GRAYSCALE);
	Mat tImg6 = imread("D:\\example\\dataset\\alphabets\\smallX.png", IMREAD_GRAYSCALE);
	Mat tImg7 = imread("D:\\example\\dataset\\alphabets\\largeX.png", IMREAD_GRAYSCALE);
	Mat tImg8 = imread("D:\\example\\dataset\\alphabets\\smallO.png", IMREAD_GRAYSCALE);
	Mat tImg9 = imread("D:\\example\\dataset\\alphabets\\largeO.png", IMREAD_GRAYSCALE);
	Mat tImg10 = imread("D:\\example\\dataset\\alphabets\\smallL.png", IMREAD_GRAYSCALE);
	if (tImg1.empty() || tImg2.empty() || tImg3.empty() || tImg4.empty()) return -1;

	Mat dstImg;
	cvtColor(srcImg, dstImg, COLOR_GRAY2BGR);

	double minVal, maxVal;
	Point minLoc, maxLoc;
	Mat result;

	// matchTemplate
	// 참조 영상에서 두 번째 매개변수를  method 방법(네 번째 매개변수)에 따라 템플릿 매칭을 계산하여 result(세 번째 매개변수)에 반환한다.
	// 템플릿 매칭 위치를 찾기 위해서는 result에 minMaxLoc 함수를 사용하여 찾을 수 있다. 최소값은 TM_SQDIFF, 최대값은 TM_CCORR, TM_CCOEFF
	// 같은 값의 최대/최소값이 있다면 처음 위치만 찾는다.

	// TM_SQDIFF, 매칭되는 위치에서 작은 값을 갖는다.
	matchTemplate(srcImg, tImg1, result, TM_SQDIFF);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImg, minLoc, Point(minLoc.x + tImg1.cols, minLoc.y + tImg1.rows), Scalar(255, 0, 0), 2);

	// TM_SQDIFF_NORMED, TM_SQDIFF 결과를 특정 식으로 나눈 뒤 정규화한다.
	matchTemplate(srcImg, tImg2, result, TM_SQDIFF_NORMED);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImg, minLoc, Point(minLoc.x + tImg2.cols, minLoc.y + tImg2.rows), Scalar(0, 255, 0), 2);

	// TM_CCORR_NORMED, TM_CCORR 결과를 특정 식으로 나눈 뒤 정규화한다.
	matchTemplate(srcImg, tImg3, result, TM_CCORR_NORMED);
	minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc);
	rectangle(dstImg, maxLoc, Point(maxLoc.x + tImg3.cols, maxLoc.y + tImg3.rows), Scalar(0, 0, 255), 2);

	// TM_CCOEFF_NORMED, TM_CCOEFF 결과를 특정 식으로 나눈 뒤 정규화한다.
	matchTemplate(srcImg, tImg4, result, TM_CCOEFF_NORMED);
	minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc);
	rectangle(dstImg, maxLoc, Point(maxLoc.x + tImg4.cols, maxLoc.y + tImg4.rows), Scalar(255, 0, 255), 2);

	// 비슷하게 생긴 알파벳이 있을 때
	matchTemplate(srcImg, tImg5, result, TM_SQDIFF);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImg, minLoc, Point(minLoc.x + tImg5.cols, minLoc.y + tImg5.rows), Scalar(0, 255, 255), 2);

	// 대문자 소문자 구분
	matchTemplate(srcImg, tImg6, result, TM_SQDIFF);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImg, minLoc, Point(minLoc.x + tImg6.cols, minLoc.y + tImg6.rows), Scalar(255, 255, 0), 2);
	matchTemplate(srcImg, tImg7, result, TM_SQDIFF);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImg, minLoc, Point(minLoc.x + tImg7.cols, minLoc.y + tImg7.rows), Scalar(255, 255, 0), 2);
	matchTemplate(srcImg, tImg8, result, TM_SQDIFF);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImg, minLoc, Point(minLoc.x + tImg8.cols, minLoc.y + tImg8.rows), Scalar(255, 255, 0), 2);
	matchTemplate(srcImg, tImg9, result, TM_SQDIFF);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImg, minLoc, Point(minLoc.x + tImg9.cols, minLoc.y + tImg9.rows), Scalar(255, 255, 0), 2);

	// 템플릿 매치 방법 별 위치 비교
	matchTemplate(srcImg, tImg10, result, TM_SQDIFF);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImg, minLoc, Point(minLoc.x + tImg10.cols, minLoc.y + tImg10.rows), Scalar(127, 0, 0), 2);
	matchTemplate(srcImg, tImg10, result, TM_SQDIFF_NORMED);
	minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
	rectangle(dstImg, minLoc, Point(minLoc.x + tImg10.cols, minLoc.y + tImg10.rows), Scalar(0, 127, 0), 2);
	matchTemplate(srcImg, tImg10, result, TM_CCORR_NORMED);
	minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc);
	rectangle(dstImg, maxLoc, Point(maxLoc.x + tImg10.cols, maxLoc.y + tImg10.rows), Scalar(0, 0, 127), 2);
	matchTemplate(srcImg, tImg10, result, TM_CCOEFF_NORMED);
	minMaxLoc(result, NULL, &maxVal, NULL, &maxLoc);
	rectangle(dstImg, maxLoc, Point(maxLoc.x + tImg10.cols, maxLoc.y + tImg10.rows), Scalar(127, 127, 127), 2);

	imshow("dstImg", dstImg);
	waitKey(0);
	return 0;
}
*/