#include <stdio.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

Mat src, origin_src;
Point2f srcQuad[4], dstQuad[4];
 
void on_mouse(int event, int x, int y, int flags, void* userdata);

int main()
{
	src = imread("card.bmp");

	if (src.empty())
	{
		cerr << "Image load failed" << endl;
		return -1;
	}
	src.copyTo(origin_src);

	namedWindow("src");
	setMouseCallback("src", on_mouse);

	imshow("src", src);
	waitKey(0);

	return 0;
}

void on_mouse(int event, int x, int y, int flags, void* userdata)
{
	static int cnt = 0;

	if (event == EVENT_LBUTTONDOWN)
	{
		if (cnt < 4)
		{
			srcQuad[cnt++] = Point2f(x, y);

			circle(src, Point(x, y), 5, Scalar(0, 0, 255), -1);
			imshow("src", src);

			if (cnt == 4)
			{
				int w = 200;
				int h = 300;

				dstQuad[0] = Point2f(0, 0);
				dstQuad[1] = Point2f(w - 1, 0);
				dstQuad[2] = Point2f(w - 1, h - 1);
				dstQuad[3] = Point2f(0, h - 1);

				Mat pers = getPerspectiveTransform(srcQuad, dstQuad);

				Mat dst;
				warpPerspective(origin_src, dst, pers, Size(w, h));

				cnt = 0;
				origin_src.copyTo(src);

				imshow("src", src);
				imshow("dst", dst);
			}
		}
	}
}