//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//void printMat(InputArray _mat)
//{
//	Mat mat = _mat.getMat();
//	cout << mat << endl;
//}
//
//void InputArrayOp()
//{
//	uchar data1[] = { 1, 2, 3, 4, 5, 6 };
//	Mat mat1(2, 3, CV_8U, data1);
//	printMat(mat1);
//
//	vector<float> vec1 = { 1.2f, 3.4f, -2.1f };
//	printMat(vec1);
//}
//int main()
//{
//	//// [Point]
//	//Point pt1;
//	//pt1.x = 10;
//	//pt1.y = 5;
//	//cout << "pt1 = " << pt1 << endl;
//
//	//Point pt2(10, 30);
//	//cout << "pt2 = " << pt2 << endl;
//
//	//Point pt3 = pt1 + pt2;
//	//cout << "pt3 = " << pt3 << endl;
//
//	//Point pt4 = pt1 * 2;
//	//cout << "pt4 = " << pt4 << endl;
//
//	//int d1 = pt1.dot(pt2);
//	//cout << "d1 = " << d1 << endl;
//
//	//bool b1 = (pt1 == pt2);
//	//cout << "b1 = " << b1 << endl;
//
//
//
//	//// [Size]
//	//Size sz1, sz2(10, 20);
//	//sz1.width = 5;
//	//sz1.height = 10;
//	//cout << "sz1 = " << sz1 << endl;
//	//cout << "sz2 = " << sz2 << endl;
//
//	//Size sz3 = sz1 + sz2;
//	//cout << "sz3 = " << sz3 << endl;
//
//	//Size sz4 = sz1 * 4;
//	//cout << "sz4 = " << sz4 << endl;
//
//	//int area = sz4.area();
//	//cout << "area = " << area << endl;
//
//
//
//	//// [Rect]
//	//Rect rc1;
//	//cout << "rc1 = " << rc1 << endl;
//
//	//Rect rc2(10, 10, 60, 40);
//	//cout << "rc2 = " << rc2 << endl;
//
//	//Rect rc3 = rc1 + Size(50, 40);
//	//cout << "rc3 = " << rc3 << endl;
//
//	//Rect rc4 = rc2 + Point(10, 10);
//	//cout << "rc4 = " << rc4 << endl;
//
//	//// 두 사각형이 교차하는 사각형 영역을 반환
//	//Rect rc5 = rc3 & rc4;
//	//cout << "rc5 = " << rc5 << endl;
//
//	//// 두 사각형을 모두 포함하는 최소 크기의 사각형을 반환
//	//Rect rc6 = rc3 | rc4;
//	//cout << "rc6 = " << rc6 << endl;
//
//
//
//	// [RotatedRect]
//	RotatedRect rr1(Point2f(200, 200), Size2f(200, 100), 30.f);
//
//	// 사각형의 좌측 하단 꼭지점부터 시계 방향으로 꼭지점 좌표를 추출
//	Point2f pts[4];
//	rr1.points(pts);
//
//	Rect br = rr1.boundingRect();
//
//	Mat background(640, 480, CV_8UC3, Scalar(0));
//	for (int i = 0; i < 4; i++)
//	{
//		line(background, pts[i], pts[(i + 1) % 4], Scalar(0, 0, 255), 2);
//	}
//	rectangle(background, rr1.boundingRect(), Scalar(255, 0, 0), 2);
//
//	imshow("Draw rotated rect", background);
//	waitKey(0);
//
//
//
//	//// [Range]
//	//Range r1(0, 10);
//	//cout << "r1 = " << r1 << endl;
//
//
//
//	//// [String]
//	//String str1 = "Hello";
//	//String str2 = "World";
//	//String str3 = str1 + " " + str2;
//
//	//bool ret = (str2 == "WORLD");
//
//	// 특정한 형식의 문자열
//	//for (int i = 0; i < 3; i++)
//	//{
//	//	String filename = format("test%02d.bmp", i + 1);
//	//	cout << filename << endl;
//	//}
//
//	// Mat
//	//Mat img1 = imread("lena.jpg", IMREAD_GRAYSCALE);

//	//Mat img1f;
//	//img1.convertTo(img1f, CV_32FC1);

//	//uchar data1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ,11, 12, 13 };
//	//Mat mat1(3, 4, CV_8UC1, data1);
//	//Mat mat2 = mat1.reshape(0, 1);

//	//cout << "mat1 = " << mat1 << endl;
//	//cout << "mat2 = " << mat2 << endl;

//	//Mat mat3 = Mat::ones(1, 4, CV_8UC1) * 255;
//	//mat1.push_back(mat3);
//	//cout << "mat1 = " << mat1 << endl;

//	//mat1.resize(6, 100);
//	//cout << "mat1 = " << mat1 << endl;
// 
//	// InputArray
//	InputArrayOp();
// 
//	return 0;
//}