#include <iostream>
using namespace std;

/*
[Lab08] 2 + a 를 가능하게: friend 외부 operator+
---------------------------------------------------
핵심
- 멤버 operator+는 왼쪽이 반드시 클래스 타입이어야 한다(this 필요).
- 2 + a 는 왼쪽이 int -> 멤버로 구현 불가.
- 해결: operator+(int, Power)를 "외부 함수"로 만들고 Power에 friend로 선언.

실습 포인트
- friend로 선언하면 외부 함수가 private에 접근 가능.
- 또는 getter를 제공해 friend 없이도 구현 가능(캡슐화 관점).
---------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    friend Power operator+(int op1, const Power& op2);
};

Power operator+(int op1, const Power& op2) {
    return Power(op1 + op2.kick, op1 + op2.punch);
}

int main() {
    Power a(3,5), b;
    b = 2 + a;
    a.show();
    b.show();
    return 0;
}
