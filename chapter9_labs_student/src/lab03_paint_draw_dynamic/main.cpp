#include <iostream>
using namespace std;

/*
[Lab03] Base 멤버 함수 안에서 virtual 호출이 일어나는 구조
------------------------------------------------------------
핵심
- paint()는 Base의 함수지만 내부에서 draw()를 호출한다.
- draw()가 virtual이면, 실제 객체 타입에 따라 draw()가 바뀐다.

이론 연결
- 부모 함수 안에서 virtual 함수를 호출해도 동적 바인딩은 그대로 유지된다.
- 이 구조는 "공통 흐름은 부모가, 세부 동작은 자식이" 맡는 설계의 기본이다.
- 뒤쪽 템플릿 메서드 느낌의 예제(lab09)로 이어지는 중요한 중간 단계다.

관찰 포인트
- Shape* p = new Shape();  p->paint() -> Shape::draw
- Shape* p = new Circle(); p->paint() -> Circle::draw
------------------------------------------------------------
*/

class Shape {
public:
    // paint()는 공통 흐름을 담당한다.
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
    // paint()는 Shape의 함수지만, 내부 draw()는 Circle 버전이 선택된다.
    p2->paint();
    delete p2;
}
