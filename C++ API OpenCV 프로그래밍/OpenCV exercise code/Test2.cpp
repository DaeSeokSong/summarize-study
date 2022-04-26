#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
	cv::VideoCapture walkPeople;
	walkPeople.open("D:\\example\\dataset\\YT_Protector\\Video\\Fast_walk1.mp4");
	if (!walkPeople.isOpened())
	{
		cout << "■□■□■□ 검사할 영상을 다시 업로드 해주세요. ■□■□■□" << endl;
		return -1;
	}

	cv::HOGDescriptor HOGdtc;
	HOGdtc.setSVMDetector(cv::HOGDescriptor::getDefaultPeopleDetector());

	cv::Mat frame;
	cv::Mat grayFrame;
	vector<cv::Rect> detected;

	vector<cv::Mat> ROIimgs;

	while (true)
	{
		walkPeople >> frame;
		if (frame.empty()) break;
		else cv::resize(frame, frame, cv::Size(640, 480));

		cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);

		HOGdtc.detectMultiScale(grayFrame, detected);
		ROIimgs.clear();
		for (cv::Rect r : detected)
		{
			cv::Scalar color(rand() % 256, rand() % 256, rand() % 256);
			cv::rectangle(frame, r, color, 3);

			ROIimgs.push_back(frame(r));
		}
		cout << "ROIimgs.size() = " << ROIimgs.size() << endl;

		cv::imshow("frame", frame);

		char inputKey = cv::waitKey(1);
		if (inputKey == 27) break;
	}

	return 0;
}