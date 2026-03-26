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
문법 설명
- 멤버 연산자 함수는 `왼쪽객체.operator+(오른쪽값)` 형태로 해석된다.
- 그래서 `a + 2` 는 `a.operator+(2)`로 처리할 수 있다.
- 하지만 `2 + a` 는 왼쪽이 int라서 `int` 클래스에 멤버 함수를 추가할 수 없다.
- 이런 경우는 외부 함수 `operator+(int, const Power&)` 형태가 필요하다.
- 외부 함수가 private 멤버를 읽어야 하므로 friend를 사용한다.
------------------------------------------------------------
주의/포인트
- a + 2 와 2 + a 를 모두 지원하려면 멤버 + friend가 필요하다.
------------------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    // 기본값이 있어 Power(), Power(3,5) 둘 다 가능하다.
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    // 멤버 연산자이므로 왼쪽 피연산자는 현재 객체(*this)다.
    // 즉 a + 2 는 a.operator+(2)처럼 해석된다.
    Power operator+(int op2) const {
        // a + 2
        return Power(kick + op2, punch + op2);
    }

    // 2 + a 를 처리하려면 전역 함수 형태가 필요하다.
    // 이 함수는 Power의 private 멤버를 읽어야 하므로 friend로 선언한다.
    friend Power operator+(int op1, const Power& op2);
};

// 외부 함수 문법:
// 반환형 operator연산자기호(왼쪽피연산자, 오른쪽피연산자)
//
// 여기서는 2 + a 를 operator+(2, a)처럼 처리한다.
Power operator+(int op1, const Power& op2) {
    // 2 + a
    return Power(op1 + op2.kick, op1 + op2.punch);
}

int main() {
    Power a(3,5), b, c;
    // a + 2 : 왼쪽이 Power 객체이므로 멤버 함수 호출 가능
    b = a + 2; // 멤버
    // 2 + a : 왼쪽이 int이므로 외부 friend 함수가 필요
    c = 2 + a; // friend

    a.show(); b.show(); c.show();
    return 0;
}
