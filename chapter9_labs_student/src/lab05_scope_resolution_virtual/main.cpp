#include <iostream>
using namespace std;

/*
[Lab05] 범위 지정(::)으로 Base의 virtual 함수를 강제로 호출
------------------------------------------------------------
핵심
- p->draw() 는 동적 바인딩 -> 실제 객체 타입의 draw()
- p->Shape::draw() 는 정적 바인딩 -> Base의 draw()를 강제 실행

실습 포인트
- 파생 클래스 draw()에서 Shape::draw()를 먼저 호출해
  "부모 기능 + 추가 기능" 형태로 확장 가능.

이론 연결
- virtual이라고 해서 항상 자식 함수만 호출되는 것은 아니다.
- 범위 지정 연산자(::)를 쓰면 동적 바인딩을 우회하고 원하는 클래스 버전을 직접 부를 수 있다.
- 오버라이딩은 "대체"만이 아니라 "확장" 방식으로도 사용할 수 있다.
------------------------------------------------------------
*/

class Shape {
public:
    virtual void draw() { cout << "--Shape--"; }
};

class Circle : public Shape {
public:
    void draw() override {
        Shape::draw();   // 부모 버전을 명시적으로 호출
        cout << "Circle\n";
    }
};

int main() {
    Circle circle;
    Shape* p = &circle;

    p->draw();          // 동적 바인딩
    p->Shape::draw();   // 범위 지정으로 부모 버전 강제 호출
    cout << "\n";
}
