// 예제 4?1 객체 포인터 선언 및 활용
/*
#include <iostream>
using namespace std;

class Circle {
	int radius; 
public:
	Circle() {	radius = 1; }
	Circle(int r)  { radius = r; }
	double getArea(); 
}; 

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle donut;
	Circle pizza(30);

	// 객체 이름으로 멤버 접근
	cout << donut.getArea() << endl;

	// 객체 포인터로 멤버 접근
	Circle *p;
	p = &donut;
	cout << p->getArea() << endl; // donut의 getArea() 호출
	cout << (*p).getArea() <<endl; // donut의 getArea() 호출

	p = &pizza; 
	cout << p->getArea() << endl; // pizza의 getArea() 호출
	cout << (*p).getArea() << endl; // pizza의 getArea() 호출
}
*/

// 예제 4? 2 Circle 클래스의 배열 선언 및 활용
/* #include <iostream>
using namespace std;

class Circle {
	int radius; 
public:
	Circle() {	radius = 1; }
	Circle(int r)  { radius = r; }
	void setRadius(int r)  { radius = r; } 
	double getArea(); 
}; 

double Circle::getArea() {
	return 3.14*radius*radius;
}
int main() {
	Circle circleArray[3]; 										// (1) Circle 객체 배열 생성

	// 배열의 각 원소 객체의 멤버 접근
	circleArray[0].setRadius(10); 							// (2)
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);

	for(int i=0; i<3; i++) // 배열의 각 원소 객체의 멤버 접근
		cout << "Circle " << i << " size " << circleArray[i].getArea() << endl;

	Circle *p; 															// (3)
	p = circleArray; 												// (4)
	for(int i=0; i<3; i++) { 	// 객체 포인터로 배열 접근
		cout << "Circle " << i << " size " << p->getArea() << endl;
		p++; 															// (5)
	}
}
*/

// 예제 4?3 객체 배열 초기화
/* 
#include <iostream>
using namespace std;

class Circle {
	int radius; 
public:
	Circle() {	radius = 1; }
	Circle(int r)  { radius = r; }
	void setRadius(int r)  { radius = r; } 
	double getArea(); 
}; 

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle circleArray[3] = { Circle(10), Circle(20), Circle() }; // Circle 배열 초기화

	for(int i=0; i<3; i++) 
		cout << "Circle " << i << " size " << circleArray[i].getArea() << endl;
}
*/

// 예제 4-4 Circle 클래스의 2차원 배열 선언 및 활용
/*
#include <iostream>
using namespace std;

class Circle {
	int radius; 
public:
	Circle() {	radius = 1; }
	Circle(int r)  { radius = r; }
	void setRadius(int r)  { radius = r; } 
	double getArea(); 
}; 

double Circle::getArea() {
	return 3.14*radius*radius;
}

int main() {
	Circle circles[2][3];

	circles[0][0].setRadius(1);
	circles[0][1].setRadius(2);
	circles[0][2].setRadius(3);
	circles[1][0].setRadius(4);
	circles[1][1].setRadius(5);
	circles[1][2].setRadius(6);

	for(int i=0; i<2; i++)  	// 배열의 각 원소 객체의 멤버 접근
		for(int j=0; j<3; j++) {
			cout << "Circle [" << i << "," << j 	<< "] size is ";
			cout << circles[i][j].getArea() <<endl;
		}
}
*/

// 예제 4-5 정수형 공간의 동적 할당 및 반환 예
/* 
#include <iostream>
using namespace std;

int main() {
	int *p;

	p = new int; 
	if(!p) {
		cout << "memory allocation fail!";
		return 0;
	}

	*p = 5; // 할당 받은 정수 공간에 5 삽입
	int n = *p;
	cout << "*p = " << *p << '\n';
	cout << "n = " << n << '\n';

	delete p;
}
*/
// 예제 4-6 정수형 배열의 동적 할당 및 반환
/*
#include <iostream>
using namespace std;

int main() {
	cout << "# of input? ";
	int n;
	cin >> n; // 정수의 개수 입력
	if(n <= 0) return 0;
	int *p = new int[n]; // n 개의 정수 배열 동적 할당
	if(!p) { 
		cout << "memory allocation error!";
		return 0;
	}

	for(int i=0; i<n; i++) {
		cout << i+1 << "th number : "; // 프롬프트 출력
		cin >> p[i]; // 키보드로부터 정수 입력
	}

	int sum = 0;
	for(int i=0; i<n; i++)
		sum += p[i];
	cout << "avg = " << sum/n << endl;

	delete [] p; // 배열 메모리 반환
}
*/
// 예제 4?8 Circle 객체의 동적 생성과 반환 응용
/*
#include <iostream>
using namespace std;

class Circle {
	int radius; 
public:
	Circle(); 
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14*radius*radius; }
}; 

Circle::Circle() {
	radius = 1;
	cout << "construct a circle with radius = " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "construct a circle with radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "delete a circle with radius = " << radius << endl;
}
int main() {
	int radius;
	while(true) {
		cout << "radius (quit:negative number) >> ";
		cin >> radius;
		if(radius < 0) break; // 음수가 입력되어 종료한다.
		Circle *p = new Circle(radius); // 동적 객체 생성
		cout << "The circle size is " << p->getArea() << endl;
		delete p; // 객체 반환
	}
}
*/
// 예제 4-9 Circle 배열의 동적 생성 및 반환
/*
#include <iostream>
using namespace std;

class Circle {
	int radius; 
public:
	Circle(); 
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14*radius*radius; }
}; 

Circle::Circle() {
	radius = 1;
	cout << "construct a circle with radius = " << radius << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "construct a circle with radius = " << radius << endl;
}

Circle::~Circle() {
	cout << "delete a circle with radius = " << radius << endl;
}
int main() {
	Circle *pArray = new Circle [3]; // 객체 배열 생성

	pArray[0].setRadius(10);
	pArray[1].setRadius(20);
	pArray[2].setRadius(30);

	for(int i=0; i<3; i++) {
		cout << pArray[i].getArea() << '\n';
	}
	Circle *p = pArray; // 포인터 p에 배열의 주소값으로 설정
	for(int i=0; i<3; i++) {
		cout << p->getArea() << '\n';
		p++; // 다음 원소의 주소로 증가
	}

	delete [] pArray; // 객체 배열 소멸
}
*/

// 예제 4-10 객체 배열의 동적 생성과 반환 응용

#include <iostream>
using namespace std;

class Circle {
	int radius; 
public:
	Circle(); 
	~Circle() { }
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14*radius*radius; }
}; 

Circle::Circle() {
	radius = 1;
}

int main() {
	cout << "# of circles? ";
	int n, radius;
	cin >> n; // 원의 개수 입력

	Circle *pArray = new Circle [n]; // n 개의 Circle 배열 생성
	for(int i=0; i<n; i++) {
		cout << "circle" << i+1 << ": "; // 프롬프트 출력
		cin >> radius; // 반지름 입력
		pArray[i].setRadius(radius); // 각 Circle 객체를 반지름으로 초기화
	}

	int count =0; // 카운트 변수
	Circle* p = pArray;
	for(int i=0; i<n; i++) {
		cout << p->getArea() << ' '; // 원의 면적 출력
		if(p->getArea() >= 100 && p->getArea() <= 200) 
			count++;
		p++;
	}
	cout << endl << "the number of circles in size between 100 and 200 is " 
			<< count << endl;

	delete [] pArray; // 객체 배열 소멸
}





