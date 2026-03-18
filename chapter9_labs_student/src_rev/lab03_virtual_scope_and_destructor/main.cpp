#include <iostream>
using namespace std;

/*
[Lab03] 범위 지정 호출 + 가상 소멸자
------------------------------------------------------------
문제 설명
1) 파생 클래스에서 Base::draw()를 강제 호출하는 방법을 확인한다.
2) Base*로 delete할 때 가상 소멸자의 필요성을 확인한다.
------------------------------------------------------------
핵심 요약
- p->Base::f(): 가상 무시, Base 구현 강제 호출
- Base 소멸자는 Base*로 delete할 가능성이 있으면 반드시 virtual
------------------------------------------------------------
주의 포인트
- 가상 소멸자가 없으면 파생 소멸자가 호출되지 않을 수 있다.
------------------------------------------------------------
*/

class Shape {
public:
    virtual void draw() { cout << "--Shape--"; }
    virtual ~Shape() { cout << "~Shape()\n"; }
};

class Circle : public Shape {
public:
    void draw() override {
        Shape::draw(); // 부모 기능 호출
        cout << "Circle\n";
    }
    ~Circle() override { cout << "~Circle()\n"; }
};

int main() {
    Circle circle;
    Shape* p = &circle;

    p->draw();        // Circle::draw()
    p->Shape::draw(); // Shape::draw()
    cout << "\n";

    Shape* bp = new Circle();
    delete bp; // 가상 소멸자라 안전
}
