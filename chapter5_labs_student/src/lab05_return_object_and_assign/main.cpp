#include <iostream>
using namespace std;

/*
[Lab05] 객체 리턴 + 객체 치환(대입)
------------------------------------------------------------
핵심
1) c = getCircle(); 는 "대입 연산자"로 멤버를 복사한다(기본은 멤버 단위 복사).
2) 함수가 객체를 리턴하면 복사가 생길 수 있지만, 컴파일러 최적화(NRVO/RVO)로 생략될 수 있다.
3) 이 lab에서는 "동작 개념"을 이해하는 것이 목표다.
------------------------------------------------------------
*/

class Circle {
    int radius;
public:
    Circle() : radius(1) {}
    Circle(int r) : radius(r) {}
    void setRadius(int r) { radius = r; }
    double getArea() const { return 3.14 * radius * radius; }
};

Circle getCircle() {
    Circle tmp(30);
    return tmp;
}

int main() {
    Circle c;
    cout << c.getArea() << "\n";
    c = getCircle();
    cout << c.getArea() << "\n";
    return 0;
}
