#include <iostream>
using namespace std;

/*
[Lab04] 연산자 중복: 멤버 함수로 operator+
---------------------------------------------------
핵심
- a + b  =>  a.operator+(b)
- 멤버로 구현하면 "왼쪽 피연산자"는 this로 들어간다.
- 따라서 매개변수는 "오른쪽 피연산자"만 받는다.

실습 포인트
- operator+는 보통 원본을 바꾸지 않으므로 const 멤버 함수로 구현.
- 결과를 새 객체로 만들어 리턴.
---------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    Power operator+(Power op2) const {
        Power tmp;
        tmp.kick = kick + op2.kick;
        tmp.punch = punch + op2.punch;
        return tmp;
    }
};

int main() {
    Power a(3,5), b(4,6), c;
    c = a + b;
    a.show(); b.show(); c.show();
    return 0;
}
