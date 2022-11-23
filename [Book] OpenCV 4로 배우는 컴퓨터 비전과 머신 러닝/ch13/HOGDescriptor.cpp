#include <stdio.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap("vtest.avi");

	if (!cap.isOpened())
	{
		cerr << "Video load failed" << endl;
		return -1;
	}

	HOGDescriptor hog;
	hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

	Mat frame;
	int f_cnt = 0;
	while (true)
	{
		cap >> frame;
		if (frame.empty()) break;
		else f_cnt++;

		vector<Rect> detected;
		hog.detectMultiScale(frame, detected);

		for (Rect r : detected)
		{
			Scalar c = Scalar(rand() % 256, rand() % 256, rand() % 256);
			rectangle(frame, r, c, 3);
		}

		if (f_cnt == 46)
		{
			imwrite("HOGDescriptor_46frame.jpg", frame);
			cout << "46 frame is saved !" << endl;
		}
		imshow("frame", frame);

		int input_key = waitKey(10);
		if (input_key == 27) break;
	}

	return 0;
}