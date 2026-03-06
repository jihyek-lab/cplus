#include <iostream>
using namespace std;

/*
[Lab04] 상속이 여러 단계일 때 virtual 선택
------------------------------------------------------------
핵심
- virtual 함수는 가장 아래(가장 구체적인) 클래스의 구현이 선택된다.
- 같은 객체를 Base*, Derived*, GrandDerived*로 가리켜도
  호출 결과는 "최종 오버라이딩"으로 동일할 수 있다.
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

    bp->f();
    dp->f();
    gp->f();
}
