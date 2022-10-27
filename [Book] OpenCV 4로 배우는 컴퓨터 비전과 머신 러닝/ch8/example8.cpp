//#include <stdio.h>
//#include "opencv2/opencv.hpp"
//
//using namespace std;
//using namespace cv;
//
//void affine_transform();
//void affine_translation();
//void affine_shear();
//void affine_scale();
//void affine_rotation();
//void affine_flip();
//
//int main()
//{
//	//// Ex1
//	//affine_transform();
//
//
//
//	//// Ex2
//	//affine_translation();
//
//
//
//	//// Ex3
//	//affine_shear();
//
//
//
//	//// Ex4
//	//affine_scale();
//
//
//
//	//// Ex5
//	//affine_rotation();
//
//
//
//	// Ex6
//	affine_flip();
//
//	return 0;
//}
//
//void affine_transform()
//{
//	Mat src = imread("tekapo.bmp");
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//
//	Point2f srcPts[3], dstPts[3];
//	srcPts[0] = Point2f(0, 0);
//	srcPts[1] = Point2f(src.cols - 1, 0);
//	srcPts[2] = Point2f(src.cols - 1, src.rows - 1);
//	dstPts[0] = Point2f(50, 50);
//	dstPts[1] = Point2f(src.cols - 100, 100);
//	dstPts[2] = Point2f(src.cols - 50, src.rows - 50);
//
//	Mat M = getAffineTransform(srcPts, dstPts);
//
//	Mat dst1, dst2;
//	warpAffine(src, dst1, M, Size());
//	warpAffine(src, dst2, M, Size(src.cols*2, src.rows*2), WARP_INVERSE_MAP, BORDER_CONSTANT, Scalar(50, 50, 100));
//
//	imshow("src", src);
//	imshow("dst1", dst1);
//	imshow("dst2", dst2);
//
//	waitKey(0);
//}
//
//void affine_translation()
//{
//	Mat src = imread("tekapo.bmp");
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//
//	// 1, 0 >> 가로 / 0, 1 >> 세로
//	Mat M = Mat_<double>({ 2, 3 }, { 1, 0, 150, 0, 1, 100 });
//
//	Mat dst;
//	warpAffine(src, dst, M, Size());
//
//	imshow("src", src);
//	imshow("dst", dst);
//
//	waitKey(0);
//}
//
//void affine_shear()
//{
//	Mat src = imread("tekapo.bmp");
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//
//	double mx = 0.3;
//	Mat xM = Mat_<double>({ 2, 3 }, { 1, mx, 0, 0, 1, 0 });
//	Mat yM = Mat_<double>({ 2, 3 }, { 1, 0, 0, mx, 1, 0 });
//
//	Mat dstX, dstY;
//	warpAffine(src, dstX, xM, Size(cvRound(src.cols + src.rows * mx), src.rows));
//	warpAffine(src, dstY, yM, Size(src.cols, cvRound(src.rows + src.cols * mx)));
//
//	imshow("src", src);
//	imshow("dst_X", dstX);
//	imshow("dst_Y", dstY);
//
//	waitKey(0);
//}
//
//void affine_scale()
//{
//	Mat src = imread("rose.bmp");
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//
//	Mat dst1, dst2, dst3, dst4;
//	resize(src, dst1, Size(), 4, 4, INTER_NEAREST);
//	resize(src, dst2, Size(1920, 1080));
//	resize(src, dst3, Size(1920, 1080), 0, 0, INTER_CUBIC);
//	resize(src, dst4, Size(1920, 1080), 0, 0, INTER_LANCZOS4);
//
//	imshow("src", src);
//	imshow("dst1", dst1(Rect(400, 500, 400, 400)));
//	imshow("dst2", dst2(Rect(400, 500, 400, 400)));
//	imshow("dst3", dst3(Rect(400, 500, 400, 400)));
//	imshow("dst4", dst4(Rect(400, 500, 400, 400)));
//
//	waitKey(0);
//}
//
//void affine_rotation()
//{
//	Mat src = imread("tekapo.bmp");
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//
//	Point2f cp(src.cols / 2.f, src.rows / 2.f);
//	Mat M = getRotationMatrix2D(cp, 20, 1);
//
//	Mat dst;
//	warpAffine(src, dst, M, Size());
//
//	imshow("src", src);
//	imshow("dst", dst);
//
//	waitKey(0);
//}
//
//void affine_flip()
//{
//	Mat src = imread("eastsea.bmp");
//
//	if (src.empty())
//	{
//		cerr << "Image load failed" << endl;
//		return;
//	}
//
//	imshow("src", src);
//
//	Mat dst;
//	int flipCode[] = {1, 0, -1};
//	for (int i = 0; i < 3; i++)
//	{
//		flip(src, dst, flipCode[i]);
//
//		String desc = format("flipCode: %d", flipCode[i]);
//		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 0, 0), 1, LINE_AA);
//
//		imshow("dst", dst);
//		waitKey(0);
//	}
//}