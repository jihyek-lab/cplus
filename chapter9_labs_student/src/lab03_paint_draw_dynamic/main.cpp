#include <iostream>
using namespace std;

/*
[Lab03] Base 멤버 함수 안에서 virtual 호출이 일어나는 구조
------------------------------------------------------------
핵심
- paint()는 Base의 함수지만 내부에서 draw()를 호출한다.
- draw()가 virtual이면, 실제 객체 타입에 따라 draw()가 바뀐다.

관찰 포인트
- Shape* p = new Shape();  p->paint() -> Shape::draw
- Shape* p = new Circle(); p->paint() -> Circle::draw
------------------------------------------------------------
*/

class Shape {
public:
    void paint() { draw(); }
    virtual void draw() { cout << "Shape::draw() called\n"; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Circle::draw() called\n"; }
};

int main() {
    Shape* p1 = new Shape();
    p1->paint();
    delete p1;

    Shape* p2 = new Circle();
    p2->paint();
    delete p2;
}
