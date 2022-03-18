/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

class Prtcls {
private:
	int clsNum;

public:
	void printMsg();

	Prtcls(int num) {
		this->clsNum = num;
		cout << "Create Prtcls\n" << endl;
	}
	~Prtcls() {
		cout << "Delete Prtcls\n" << endl;
	}

};
void Prtcls::printMsg() {
	cout << "Print Message, Accept request" << endl;
	cout << "Class Number = " << clsNum << "\n" << endl;
}

int main() {
	cv::Ptr<Prtcls> pPrt = new Prtcls(0);
	cout << "ㅡㅡㅡㅡㅡThis is pPrt1ㅡㅡㅡㅡㅡ\n" << endl;
	pPrt->printMsg();

	cv::Ptr<Prtcls> pPrt2 = pPrt;
	cout << "ㅡㅡㅡㅡㅡThis is pPrt2ㅡㅡㅡㅡㅡ\n" << endl;
	while (true) {
		pPrt->printMsg();
		if (cin.get() == 's') break;
	}

	cv::Ptr<Prtcls> pPrt3 = pPrt;
	cout << "ㅡㅡㅡㅡㅡThis is pPrt3ㅡㅡㅡㅡㅡ\n" << endl;
	pPrt3->printMsg();

	// new 로 메모리 할당하게 되면 delete 해주기 전에는 메모리에 계속 남아있다.
	// 즉 소멸자가 호출이 안 된다.
	Prtcls* pPrt = new Prtcls(0);
	pPrt->printMsg();
}
*/