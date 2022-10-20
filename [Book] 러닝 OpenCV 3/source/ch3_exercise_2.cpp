/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	// 2-a. cv:Matx33f와 cv:Vec3f를 사용해 3x3행렬과 3행 벡터 객체 생성
	Matx33f m33(1, 2, 3,
		4, 5, 6,
		7, 8, 9);

	Vec3f v3(1, 2, 3);

	// 2-b. 두 객체를 직접 곱할 수 있는가? 못 하면 그 이유는?
	cout << "m33 * v3 = " << m33 * v3 << endl;
	
	* m33.dot(v3), 전달인자의 형변환 실패로 인한 에러발생
	* m33.mul(v3), 전달인자의 형변환 실패로 인한 에러발생
	*
	* 직접 오퍼레이터 연산자 오버로드를 통한 곱셈은 가능하나
	* 상호간 형변환이 자유롭지 못하여 내적이나 요소별 곱셈은 불가하다.
	
}*/