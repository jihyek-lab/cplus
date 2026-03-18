#include <iostream>
using namespace std;

/*
[Lab01] virtual 기본: 정적/동적 바인딩 비교
------------------------------------------------------------
문제 설명
1) virtual이 없을 때 재정의 함수가 어떻게 호출되는지 확인한다.
2) virtual이 있을 때 실제 객체 기준으로 호출되는지 확인한다.
------------------------------------------------------------
핵심 요약
- virtual 없음: Base*로 호출하면 Base::f() (정적 바인딩)
- virtual 있음: Base*로 호출하면 Derived::f() (동적 바인딩)
------------------------------------------------------------
주의 포인트
- 포인터 타입이 아니라 실제 객체 타입이 선택 기준이 되도록 virtual 필요
------------------------------------------------------------
*/

class BaseNoVirtual {
public:
    void f() { cout << "BaseNoVirtual::f()\n"; }
};

class DerivedNoVirtual : public BaseNoVirtual {
public:
    void f() { cout << "DerivedNoVirtual::f()\n"; }
};

class BaseVirtual {
public:
    virtual void f() { cout << "BaseVirtual::f()\n"; }
};

class DerivedVirtual : public BaseVirtual {
public:
    void f() override { cout << "DerivedVirtual::f()\n"; }
};

int main() {
    DerivedNoVirtual d1;
    BaseNoVirtual* p1 = &d1;
    p1->f(); // BaseNoVirtual::f()

    DerivedVirtual d2;
    BaseVirtual* p2 = &d2;
    p2->f(); // DerivedVirtual::f()
}
