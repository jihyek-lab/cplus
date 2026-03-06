#include <iostream>
using namespace std;

/*
[Lab11] 다이아몬드 상속 문제 + 가상 상속(virtual inheritance)
------------------------------------------------------------
다이아몬드 구조
        A
      /   \
     B     C
      \   /
        D

문제
- D가 B와 C를 상속하면 A가 "2번" 포함될 수 있다.
- 그래서 d.x 처럼 A 멤버 접근이 모호해진다.

해결
- B와 C가 A를 virtual public A로 상속하면,
  D 안에 A가 "1개만" 존재하도록 강제한다.
------------------------------------------------------------
*/

class A {
public:
    int x;
    A() : x(1) {}
};

class B : public A {};
class C : public A {};
class D_bad : public B, public C {}; // A가 2번

class Bv : virtual public A {};
class Cv : virtual public A {};
class D_good : public Bv, public Cv {}; // A가 1번

int main() {
    D_good d;
    d.x = 10;
    cout << d.x << "\n";

    // D_bad e;
    // e.x = 10; // (에러) 어떤 A::x ?
}
