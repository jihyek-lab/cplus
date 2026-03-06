/******** ex3-1 Circle 클래스의 객체 생성 및 활용
#include <iostream> 
using namespace std; 

class Circle {
public:
	int radius; 
	double getArea(); 
}; 

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle donut; 
	donut.radius = 1; // donut 객체의 반지름을 1로 설정
	double area = donut.getArea(); // donut 객체의 면적 알아내기
	cout << "donut 면적은 " << area << endl;

	Circle pizza; 
	pizza.radius = 30; // pizza 객체의 반지름을 30으로 설정
	area = pizza.getArea(); // pizza 객체의 면적 알아내기
	cout << "pizza 면적은 " << area << endl;
}
*/

//******** 예제 3-2(실습) – Rectangle 클래스 만들기
/* 
#include <iostream> 
using namespace std; 

class Rectangle { // Rectangle 클래스 선언부
public:
	int width; 
	int height;
	int getArea(); // 면적을 계산하여 리턴하는 함수
};

int Rectangle::getArea() { // Rectangle 클래스 구현부
	return width*height;
}

int main() {
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "사각형의 면적은 " << rect.getArea() << endl;
}
*/

// 예제 3–3 2 개의 생성자를 가진 Circle 클래스
/*
#include <iostream> 
using namespace std; 

class Circle {
public:
	int radius;
	Circle(); // 매개 변수 없는 생성자
	Circle(int r); // 매개 변수 있는 생성자
	double getArea();
}; 

Circle::Circle() {
	radius = 1;
	cout << "반지름 " << radius << " 원 생성" << endl;
}


Circle::Circle(int r) {
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

double Circle::getArea() {
	return 3.14*radius*radius;
}
int main() {
	Circle donut; // 매개 변수 없는 생성자 호출
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle pizza(30); // 매개 변수 있는 생성자 호출
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}

*/

// 예제 3-6(실습) – Rectangle 클래스 만들기
// 다음 main() 함수가 잘 작동하도록 Rectangle 클래스를 작성하고 프로그램을 완성하라.
// Rectangle 클래스는 width와 height의 두 멤버 변수와 3 개의 생성자, 그리고 isSquare() 함수를 가진다.
/*
#include <iostream> 
using namespace std; 

class Rectangle { 
public:
	int width, height; 

	Rectangle();
	Rectangle(int w, int h);
	Rectangle(int length);
	bool isSquare();
};

Rectangle::Rectangle() {
	width = height = 1;
}

Rectangle::Rectangle(int w, int h) {
	width = w; height = h;
}

Rectangle::Rectangle(int length) {
	width = height = length;
}

// 정사각형이면 true를 리턴하는 멤버 함수
bool Rectangle::isSquare() { 
	if(width == height) return true;
	else return false;
}
int main() {
	Rectangle rect1; 
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if(rect1.isSquare()) cout << "rect1은 정사각형이다." << endl ;
	if(rect2.isSquare()) cout << "rect2는 정사각형이다." << endl;
	if(rect3.isSquare()) cout << "rect3는 정사각형이다." << endl;
}
*/

// 예제 3-7 Circle 클래스에 소멸자 작성 및 실행
#include <iostream> 
using namespace std; 

class Circle {
public:
	int radius; 

	Circle(); 
	Circle(int r); 
	~Circle(); // 소멸자
	double getArea();
}; 


Circle::Circle() {
	radius = 1;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

Circle::~Circle() {
	cout << "반지름 " << radius << " 원 소멸" << endl;
}
double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle donut; 
	Circle pizza(30); 
	return 0;
}

// 예제 3-8 지역 객체와 전역 객체의 생성 및 소멸 순서
/*
Circle globalDonut(1000);
Circle globalPizza(2000);

void f() {
	Circle fDonut(100);
	Circle fPizza(200);
}

int main() {
	Circle mainDonut;
	Circle mainPizza(30);
	f();
} */
