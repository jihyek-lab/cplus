#include <iostream>
using namespace std;

/*
[Lab07] 순수 가상 함수와 추상 클래스
------------------------------------------------------------
핵심
- virtual void draw() = 0;  => 순수 가상 함수
- 순수 가상 함수를 가진 클래스는 "추상 클래스" => 객체 생성 불가
- 하지만 포인터/참조는 만들 수 있고, 파생 클래스에서 구현하면 사용 가능.

주의
- 추상 클래스 소멸자도 virtual로 두는 것이 안전한 관례.
------------------------------------------------------------
*/

class Shape {
public:
    virtual void draw() = 0;
    void paint() { draw(); }
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override { cout << "Circle\n"; }
};

int main() {
    // Shape s; // (에러) 추상 클래스 객체 생성 불가
    Shape* p = new Circle();
    p->paint();
    delete p;
}
