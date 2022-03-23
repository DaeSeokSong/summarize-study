/*
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 히스토그램, 관찰 데이터의 빈도수를 막대그래프로 표시한 것, 데이터의 확률밀도 함수를 추정할 수 있다.
// EMD, 두 개의 분포 사이에서 최소임을 측정하는 방법으로 두 분포 사이의 거리를 계산할 수 있고 이는 분포 p를 q로 변경하는 데 소요되는 최소비용이다. (수송 문제에 활용)
// 칼라매칭 등 활용 가능
int main() {
	float dataP[] = { 0.4, 100, 40, 22,
					0.3, 211, 20, 2,
					0.2, 32, 190, 150,
					0.1, 2, 100, 100 };
	float dataQ[] = { 0.5, 0, 0, 0,
					0.3, 50, 100, 80,
					0.2, 255, 255, 255 };

	Mat S1(4, 4, CV_32F, dataP);
	Mat S2(3, 4, CV_32F, dataQ);
	cout << "S1 = " << S1 << endl;
	cout << "S2 = " << S2 << endl;

	float emdDIst = EMD(S1, S2, DIST_L2);
	cout << "emdDIst = " << emdDIst << endl;

	// lowerBound and EMD
	Mat flow2;
	float lowerBound = 100;
	float emdDist2 = EMD(S1, S2, DIST_L2, noArray(), &lowerBound, flow2);
	cout << "flow2 = " << flow2 << endl;
	cout << "lowerBound = " << lowerBound << endl;
	cout << "emdDist2 = " << emdDist2 << endl;

	// DIST_USER
	Mat cost(4, 3, CV_32F, Scalar(0));
	float x1, y1, z1;
	float x2, y2, z2;
	float dx, dy, dz;
	//double dist;
	//double maxValue;
	for (int i = 0; i < S1.rows; i++) {
		x1 = S1.at<float>(i, 1);
		y1 = S1.at<float>(i, 2);
		z1 = S1.at<float>(i, 3);

		for (int k = 0; k < S2.rows; k++) {
			x2 = S2.at<float>(k, 1);
			y2 = S2.at<float>(k, 2);
			z2 = S2.at<float>(k, 3);
			dx = x1 - x2;
			dy = y1 - y2;
			dz = z1 - z2;

			cost.at<float>(i, k) = sqrt(dx * dx + dy * dy + dz * dz);			// DIST_L2
			//cost.at<float>(i, k) = abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2);	// DIST_L1

			//maxValue = (abs(x1 - x2) > abs(y1 - y2)) ? abs(x1 - x2) : abs(y1 - y2);
			//maxValue = (abs(z1 - z2) > maxValue) ? abs(z1 - z2) : maxValue;
			//cost.at<float>(i, k) = maxValue;
		}
	}
	cout << "cost = " << cost << endl;

	Mat SS1 = S1.col(0).clone();
	Mat SS2 = S2.col(0).clone();
	cout << "SS1 = " << SS1 << endl;
	cout << "SS2 = " << SS2 << endl;

	Mat flow3;
	float emdDist3 = EMD(SS1, SS2, DIST_USER, cost, 0, flow3);
	cout << "flow3 = " << flow3 << endl;
	cout << "emdDist3 = " << emdDist3 << endl;

	return 0;
}
*/