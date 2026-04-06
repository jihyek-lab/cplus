#include <iostream>
using namespace std;

/*
다형성(polymorphism)은 같은 부모 타입으로 여러 다른 자식 객체를 다루되, 실제 객체에 맞는 동작이 실행되는 성질입니다.

[Lab01] virtual이 없을 때: 함수 재정의(redefine)만 발생
------------------------------------------------------------
핵심
- Derived가 Base와 같은 이름 f()를 만들면 "재정의"가 된다.
- 하지만 Base 포인터로 호출하면 정적 바인딩(static binding):
  -> 컴파일 타임에 "포인터 타입"으로 어떤 함수를 부를지 결정
- 즉 Base*로 부르면 Base::f()가 실행된다.

이론 연결
- "이름이 같다"와 "다형성이 된다"는 다른 이야기다.
- 다형성을 만들려면 부모 쪽 선언이 virtual이어야 한다.
- 지금 예제는 상속은 했지만, 다형성은 아직 없는 상태다.

관찰 포인트
- Derived*로 호출하면 Derived::f()
- Base*로 업캐스팅한 뒤 호출하면 Base::f()
------------------------------------------------------------
*/

class Base {
public:
    void f() { cout << "Base::f() called\n"; }
};

class Derived : public Base {
public:
    void f() { cout << "Derived::f() called\n"; }
};

int main() {
    Derived d;
    Derived* pDer = &d;
    pDer->f();          // Derived

    Base* pBase = pDer; // 업캐스팅: Derived* -> Base*
    // 여기서 중요한 기준은 "실제 객체"가 아니라 "포인터 타입"이다.
    pBase->f();         // Base (virtual이 아니면 정적 바인딩)
}
