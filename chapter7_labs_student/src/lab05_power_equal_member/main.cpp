#include <iostream>
using namespace std;

/*
[Lab05] 비교 연산자 == 오버로딩
---------------------------------------------------
핵심
- a == b  => a.operator==(b)
- 비교는 객체를 바꾸지 않으므로 const 멤버 함수가 자연스럽다.
- 인자는 const&로 받는 습관(복사 비용 감소).

실습 포인트
- == 와 != 는 보통 같이 제공하는 편(미니과제에서 추가).
---------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    bool operator==(const Power& op2) const {
        return (kick == op2.kick && punch == op2.punch);
    }
};

int main() {
    Power a(3,5), b(3,5);
    cout << (a==b ? "same\n" : "diff\n");
    return 0;
}
