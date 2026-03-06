#include <iostream>
using namespace std;

/*
[Lab10] ! 연산자 오버로딩(멤버)
---------------------------------------------------
핵심
- !a  => a.operator!()
- 보통 bool을 리턴해서 "조건 검사"에 자연스럽게 쓰이게 한다.

여기 예제 의미
- kick==0 && punch==0 이면 true(=zero 상태)

실습 포인트
- 이런 연산자 의미는 팀에서 오해 없이 통일해야 한다.
---------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}

    bool operator!() const {
        return (kick == 0 && punch == 0);
    }
};

int main() {
    Power a(0,0), b(5,5);
    cout << (!a ? "a is zero\n" : "a not zero\n");
    cout << (!b ? "b is zero\n" : "b not zero\n");
    return 0;
}
