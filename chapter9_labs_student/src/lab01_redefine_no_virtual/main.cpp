#include <iostream>
using namespace std;

/*
[Lab01] virtual이 없을 때: 함수 재정의(redefine)만 발생
------------------------------------------------------------
핵심
- Derived가 Base와 같은 이름 f()를 만들면 "재정의"가 된다.
- 하지만 Base 포인터로 호출하면 정적 바인딩(static binding):
  -> 컴파일 타임에 "포인터 타입"으로 어떤 함수를 부를지 결정
- 즉 Base*로 부르면 Base::f()가 실행된다.

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

    Base* pBase = pDer; // 업캐스팅
    pBase->f();         // Base (virtual이 아니면 정적 바인딩)
}
