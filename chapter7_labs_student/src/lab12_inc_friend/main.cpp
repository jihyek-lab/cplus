#include <iostream>
using namespace std;

/*
[Lab12] 전위/후위 ++ 를 friend로 구현
---------------------------------------------------
핵심
- friend로 구현하면 왼쪽 피연산자도 매개변수로 받는다.
- 전위: operator++(Power&) -> 참조 리턴
- 후위: operator++(Power&, int) -> 값 리턴(증가 전)

실습 포인트
- friend는 private 접근을 위해 필요하지만,
  getter를 제공하면 friend 없이도 구현 가능(설계 선택).
---------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    friend Power& operator++(Power& op);
    friend Power operator++(Power& op, int);
};

Power& operator++(Power& op) {
    op.kick++; op.punch++;
    return op;
}
Power operator++(Power& op, int) {
    Power tmp = op;
    op.kick++; op.punch++;
    return tmp;
}

int main() {
    Power a(3,5), b;
    b = ++a; a.show(); b.show();
    b = a++; a.show(); b.show();
    return 0;
}
