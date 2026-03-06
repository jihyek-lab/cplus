#include <iostream>
using namespace std;

/*
[Lab09] 상속 접근 지정자: public/protected/private 상속
------------------------------------------------------------
핵심
- public 상속: Base의 public이 Derived에서도 public (가장 흔함)
- protected 상속: Base의 public이 Derived에서 protected로 내려감
- private 상속: Base의 public/protected가 Derived에서 private로 내려감

결과
- 외부에서 Derived 객체로 Base의 pub()에 접근 가능한지 달라진다.
------------------------------------------------------------
*/

class Base {
public:
    void pub() { cout << "Base::pub\n"; }
protected:
    void prot() { cout << "Base::prot\n"; }
};

class D1 : public Base {
public:
    void test() { pub(); prot(); }
};
class D2 : protected Base {
public:
    void test() { pub(); prot(); }
};
class D3 : private Base {
public:
    void test() { pub(); prot(); }
};

int main() {
    D1 a; a.pub(); // OK
    // D2 b; b.pub(); // (에러) protected로 내려감
    // D3 c; c.pub(); // (에러) private로 내려감
}
