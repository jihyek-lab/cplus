#include <iostream>
using namespace std;

/*
[Lab02] 가상 함수 호출 경로 + 다단계 오버라이딩
------------------------------------------------------------
문제 설명
1) Base의 일반 함수가 virtual 함수를 호출할 때 실제 타입이 반영되는지 확인한다.
2) 상속이 여러 단계일 때 가장 아래 클래스의 구현이 선택되는지 확인한다.
------------------------------------------------------------
핵심 요약
- Base 함수 안에서 virtual 호출 -> 실제 객체 타입의 함수 실행
- 다단계 상속에서도 최종 오버라이딩이 선택됨
------------------------------------------------------------
주의 포인트
- Base 함수 내부에서도 virtual은 동적 바인딩이 적용된다.
------------------------------------------------------------
*/

class Shape {
public:
    void paint() { draw(); }
    virtual void draw() { cout << "Shape::draw()\n"; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Circle::draw()\n"; }
};

class Base {
public:
    virtual void f() { cout << "Base::f()\n"; }
};
class Derived : public Base {
public:
    void f() override { cout << "Derived::f()\n"; }
};
class GrandDerived : public Derived {
public:
    void f() override { cout << "GrandDerived::f()\n"; }
};

int main() {
    Shape* p1 = new Shape();
    p1->paint();
    delete p1;

    Shape* p2 = new Circle();
    p2->paint();
    delete p2;

    GrandDerived g;
    Base* bp = &g;
    Derived* dp = &g;
    bp->f();
    dp->f();
}
