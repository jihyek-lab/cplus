#include <iostream>
using namespace std;

/*
[Lab04] 상속 접근 지정자: public / protected / private 상속
------------------------------------------------------------
문제 설명
1) 상속 방식에 따라 Base의 public 멤버가 어떻게 바뀌는지 확인한다.
2) 외부에서 접근 가능한 범위가 달라짐을 관찰한다.
------------------------------------------------------------
핵심 요약
- public 상속: Base public -> Derived public
- protected 상속: Base public -> Derived protected
- private 상속: Base public/protected -> Derived private
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
    // 강의 코멘트:
    // 파생 클래스 내부에서는 pub, prot 둘 다 사용 가능하다.
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
    // 강의 코멘트:
    // 차이는 "파생 클래스 안에서 쓸 수 있느냐"가 아니라
    // "외부에서 그 멤버가 어떤 접근 수준으로 보이느냐"에 있다.
    D1 a; a.pub(); // OK
    // D2 b; b.pub(); // (에러) protected로 내려감
    // D3 c; c.pub(); // (에러) private로 내려감
}
