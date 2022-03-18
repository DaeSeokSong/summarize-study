/*
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
	cv::DataType<int> i;
	cout << "channels, 값의 개수 = " << i.channels << endl;
	cout << "depth, OpenCV가 사용하는 데이터 타입 식별자 = " << i.depth << endl;
	cout << "fmt, 포맷의 단일 문자 표현값 = " << i.fmt << endl;
	cout << "generic_type, core.hpp에 정의된 모든 타입이 0을 가지므로 = " << i.generic_type << endl;
	cout << "type = " << i.type << endl;
	cout << '\n';

	cv::DataType<float> f;
	cout << "channels, 값의 개수 = " << f.channels << endl;
	cout << "depth, OpenCV가 사용하는 데이터 타입 식별자 = " << f.depth << endl;
	cout << "fmt, 포맷의 단일 문자 표현값 = " << f.fmt << endl;
	cout << "generic_type, core.hpp에 정의된 모든 타입이 0을 가지므로 = " << f.generic_type << endl;
	cout << "type = " << f.type << endl;
	cout << '\n';

	cv::DataType<char> c; // string은 안됌
	cout << "channels, 값의 개수 = " << c.channels << endl;
	cout << "depth, OpenCV가 사용하는 데이터 타입 식별자 = " << c.depth << endl;
	cout << "fmt, 포맷의 단일 문자 표현값 = " << c.fmt << endl;
	cout << "generic_type, core.hpp에 정의된 모든 타입이 0을 가지므로 = " << c.generic_type << endl;
	cout << "type = " << c.type << endl;
	cout << '\n';

	// OpenCV에서 정의된 데이터형은 depth와 type 값이 없다.
	cv::DataType<cv::Rect> r;
	cout << "channels, 값의 개수 = " << r.channels << endl;
	cout << "fmt, 포맷의 단일 문자 표현값 = " << r.fmt << endl;
	cout << "generic_type, core.hpp에 정의된 모든 타입이 0을 가지므로 = " << r.generic_type << endl;
	cout << '\n';

	cv::DataType<cv::Size> s;
	cout << "channels, 값의 개수 = " << s.channels << endl;
	cout << "fmt, 포맷의 단일 문자 표현값 = " << s.fmt << endl;
	cout << "generic_type, core.hpp에 정의된 모든 타입이 0을 가지므로 = " << s.generic_type << endl;
}
*/