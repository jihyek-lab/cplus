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

이론 연결
- 순수 가상 함수는 "기능 이름은 정하지만 구현은 자식에게 맡긴다"는 선언이다.
- 추상 클래스는 객체를 만드는 용도가 아니라 공통 인터페이스를 제공하는 용도다.
- 즉 이 단계부터는 상속이 "코드 재사용"보다 "규약 강제" 역할을 강하게 띤다.
------------------------------------------------------------
*/

class Shape {
public:
    virtual void draw() = 0;
    // 구현은 없지만, 공통 흐름은 일반 멤버 함수로 제공할 수 있다.
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
    // 부모 포인터는 가능하다. 실제 객체는 Circle이다.
    p->paint();
    delete p;
}
