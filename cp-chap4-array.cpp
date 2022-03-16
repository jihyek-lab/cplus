// ���� 4?1 ��ü ������ ���� �� Ȱ��
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

	// ��ü �̸����� ��� ����
	cout << donut.getArea() << endl;

	// ��ü �����ͷ� ��� ����
	Circle *p;
	p = &donut;
	cout << p->getArea() << endl; // donut�� getArea() ȣ��
	cout << (*p).getArea() <<endl; // donut�� getArea() ȣ��

	p = &pizza; 
	cout << p->getArea() << endl; // pizza�� getArea() ȣ��
	cout << (*p).getArea() << endl; // pizza�� getArea() ȣ��
}
*/

// ���� 4? 2 Circle Ŭ������ �迭 ���� �� Ȱ��
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
	Circle circleArray[3]; 										// (1) Circle ��ü �迭 ����

	// �迭�� �� ���� ��ü�� ��� ����
	circleArray[0].setRadius(10); 							// (2)
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);

	for(int i=0; i<3; i++) // �迭�� �� ���� ��ü�� ��� ����
		cout << "Circle " << i << " size " << circleArray[i].getArea() << endl;

	Circle *p; 															// (3)
	p = circleArray; 												// (4)
	for(int i=0; i<3; i++) { 	// ��ü �����ͷ� �迭 ����
		cout << "Circle " << i << " size " << p->getArea() << endl;
		p++; 															// (5)
	}
}
*/

// ���� 4?3 ��ü �迭 �ʱ�ȭ
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
	Circle circleArray[3] = { Circle(10), Circle(20), Circle() }; // Circle �迭 �ʱ�ȭ

	for(int i=0; i<3; i++) 
		cout << "Circle " << i << " size " << circleArray[i].getArea() << endl;
}
*/

// ���� 4-4 Circle Ŭ������ 2���� �迭 ���� �� Ȱ��
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

	for(int i=0; i<2; i++)  	// �迭�� �� ���� ��ü�� ��� ����
		for(int j=0; j<3; j++) {
			cout << "Circle [" << i << "," << j 	<< "] size is ";
			cout << circles[i][j].getArea() <<endl;
		}
}
*/

// ���� 4-5 ������ ������ ���� �Ҵ� �� ��ȯ ��
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

	*p = 5; // �Ҵ� ���� ���� ������ 5 ����
	int n = *p;
	cout << "*p = " << *p << '\n';
	cout << "n = " << n << '\n';

	delete p;
}
*/
// ���� 4-6 ������ �迭�� ���� �Ҵ� �� ��ȯ
/*
#include <iostream>
using namespace std;

int main() {
	cout << "# of input? ";
	int n;
	cin >> n; // ������ ���� �Է�
	if(n <= 0) return 0;
	int *p = new int[n]; // n ���� ���� �迭 ���� �Ҵ�
	if(!p) { 
		cout << "memory allocation error!";
		return 0;
	}

	for(int i=0; i<n; i++) {
		cout << i+1 << "th number : "; // ������Ʈ ���
		cin >> p[i]; // Ű����κ��� ���� �Է�
	}

	int sum = 0;
	for(int i=0; i<n; i++)
		sum += p[i];
	cout << "avg = " << sum/n << endl;

	delete [] p; // �迭 �޸� ��ȯ
}
*/
// ���� 4?8 Circle ��ü�� ���� ������ ��ȯ ����
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
		if(radius < 0) break; // ������ �ԷµǾ� �����Ѵ�.
		Circle *p = new Circle(radius); // ���� ��ü ����
		cout << "The circle size is " << p->getArea() << endl;
		delete p; // ��ü ��ȯ
	}
}
*/
// ���� 4-9 Circle �迭�� ���� ���� �� ��ȯ
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
	Circle *pArray = new Circle [3]; // ��ü �迭 ����

	pArray[0].setRadius(10);
	pArray[1].setRadius(20);
	pArray[2].setRadius(30);

	for(int i=0; i<3; i++) {
		cout << pArray[i].getArea() << '\n';
	}
	Circle *p = pArray; // ������ p�� �迭�� �ּҰ����� ����
	for(int i=0; i<3; i++) {
		cout << p->getArea() << '\n';
		p++; // ���� ������ �ּҷ� ����
	}

	delete [] pArray; // ��ü �迭 �Ҹ�
}
*/

// ���� 4-10 ��ü �迭�� ���� ������ ��ȯ ����

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
	cin >> n; // ���� ���� �Է�

	Circle *pArray = new Circle [n]; // n ���� Circle �迭 ����
	for(int i=0; i<n; i++) {
		cout << "circle" << i+1 << ": "; // ������Ʈ ���
		cin >> radius; // ������ �Է�
		pArray[i].setRadius(radius); // �� Circle ��ü�� ���������� �ʱ�ȭ
	}

	int count =0; // ī��Ʈ ����
	Circle* p = pArray;
	for(int i=0; i<n; i++) {
		cout << p->getArea() << ' '; // ���� ���� ���
		if(p->getArea() >= 100 && p->getArea() <= 200) 
			count++;
		p++;
	}
	cout << endl << "the number of circles in size between 100 and 200 is " 
			<< count << endl;

	delete [] pArray; // ��ü �迭 �Ҹ�
}





