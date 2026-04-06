#include <iostream>
using namespace std;

/*
[Lab04] 상속이 여러 단계일 때 virtual 선택
------------------------------------------------------------
핵심
- virtual 함수는 가장 아래(가장 구체적인) 클래스의 구현이 선택된다.
- 같은 객체를 Base*, Derived*, GrandDerived*로 가리켜도
  호출 결과는 "최종 오버라이딩"으로 동일할 수 있다.

이론 연결
- virtual 함수 테이블 관점에서 보면, 가장 마지막에 재정의된 함수가 연결된다.
- 포인터 타입이 여러 단계로 달라도 실제 객체가 하나라면 최종 구현은 같다.
- 이게 다형성이 "한 단계 상속"에만 한정되지 않는 이유다.
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
class GrandDerived : public Derived {
public:
    void f() override { cout << "GrandDerived::f() called\n"; }
};

int main() {
    GrandDerived g;
    Base* bp = &g;
    Derived* dp = &g;
    GrandDerived* gp = &g;

    // 셋 다 같은 객체 g를 가리킨다.
    // 따라서 세 호출 모두 GrandDerived::f()로 귀결된다.
    bp->f();
    dp->f();
    gp->f();
}
