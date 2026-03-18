#include <iostream>
using namespace std;

/*
[Lab03] int와의 혼합 연산자(+)
------------------------------------------------------------
문제 설명
1) a + 2 형태의 연산을 멤버 함수로 구현한다.
2) 2 + a 형태를 friend 외부 함수로 구현한다.
------------------------------------------------------------
핵심 요약
- 멤버 연산자는 왼쪽 피연산자가 클래스 타입이어야 한다.
- 왼쪽이 기본 타입이면 friend(외부 함수)로 구현해야 한다.
------------------------------------------------------------
주의/포인트
- a + 2 와 2 + a 를 모두 지원하려면 멤버 + friend가 필요하다.
------------------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    Power operator+(int op2) const {
        // a + 2
        return Power(kick + op2, punch + op2);
    }

    friend Power operator+(int op1, const Power& op2);
};

Power operator+(int op1, const Power& op2) {
    // 2 + a
    return Power(op1 + op2.kick, op1 + op2.punch);
}

int main() {
    Power a(3,5), b, c;
    b = a + 2; // 멤버
    c = 2 + a; // friend

    a.show(); b.show(); c.show();
    return 0;
}
