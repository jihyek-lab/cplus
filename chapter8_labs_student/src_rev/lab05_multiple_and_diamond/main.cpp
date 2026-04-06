#include <iostream>
using namespace std;

/*
[Lab05] 다중 상속 + 다이아몬드 상속(가상 상속)
------------------------------------------------------------
문제 설명
1) 다중 상속으로 기능을 합치는 예를 본다.
2) 다이아몬드 상속에서 중복된 베이스 문제를 확인한다.
3) virtual 상속으로 문제를 해결한다.
------------------------------------------------------------
핵심 요약
- 다중 상속: 여러 부모 기능 결합 가능하지만 복잡도 상승
- 다이아몬드 문제: 동일 베이스가 중복 포함됨
- virtual 상속: 베이스를 1개만 유지하도록 강제
------------------------------------------------------------
*/

class Adder {
protected:
    int add(int a, int b) { return a + b; }
};
class Subtractor {
protected:
    int minus(int a, int b) { return a - b; }
};

class Calculator : public Adder, public Subtractor {
public:
    // 강의 코멘트:
    // 다중 상속의 단순한 장점은 "기능 합치기"다.
    // 여기서는 더하기 기능과 빼기 기능을 한 객체가 모두 가진다.
    int calc(char op, int a, int b) {
        switch(op) {
        case '+': return add(a,b);
        case '-': return minus(a,b);
        default:  return 0;
        }
    }
};

class A {
public:
    int x;
    A() : x(1) {}
};

class B : public A {};
class C : public A {};
// 강의 코멘트:
// B에도 A가 있고 C에도 A가 있으므로, D_bad 안에는 A가 두 개 들어간다.
class D_bad : public B, public C {}; // A가 2번 포함

class Bv : virtual public A {};
class Cv : virtual public A {};
// 강의 코멘트:
// virtual 상속을 쓰면 "A를 공유해서 하나만 두자"는 뜻이 된다.
class D_good : public Bv, public Cv {}; // A가 1번

int main() {
    Calculator c;
    cout << "2 + 4 = " << c.calc('+',2,4) << "\n";
    cout << "100 - 8 = " << c.calc('-',100,8) << "\n";

    // 강의 코멘트:
    // D_good은 A를 하나만 가지므로 x가 모호하지 않다.
    D_good d;
    d.x = 10;
    cout << d.x << "\n";

    // D_bad e; e.x = 10; // (에러) 어떤 A::x ?
}
