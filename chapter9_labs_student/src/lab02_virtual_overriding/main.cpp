#include <iostream>
using namespace std;

/*
[Lab02] virtual이 있을 때: 오버라이딩 + 동적 바인딩(dynamic binding)
------------------------------------------------------------
핵심
- Base::f()를 virtual로 선언하면,
  Base*로 호출해도 "실제 객체 타입"에 맞는 함수가 실행된다.
- 즉 Base*가 Derived 객체를 가리키면 Derived::f()가 실행.

override 키워드
- 오버라이딩이 맞는지 컴파일러가 검사해줌(오타/시그니처 실수 방지).

이론 연결
- 동적 바인딩은 "실행 시점"에 실제 객체 타입을 보고 함수를 고른다.
- 부모 포인터로 자식 객체를 다루는 다형성의 출발점이 바로 virtual이다.
- override는 선택 사항이지만, 실수 방지용으로 사실상 필수에 가깝다.
------------------------------------------------------------
*/

class Base {
public:
    virtual void f() { cout << "Base::f() called\n"; }
};

class Derived : public Base {
public:
    void f() override { cout << "Derived::f() called\n"; }
};

int main() {
    Derived d;
    Base* pBase = &d;
    // pBase의 타입은 Base*지만, 실제 객체는 Derived다.
    // Base::f()가 virtual이므로 호출 대상은 Derived::f()로 결정된다.
    pBase->f(); // Derived (동적 바인딩)
}
