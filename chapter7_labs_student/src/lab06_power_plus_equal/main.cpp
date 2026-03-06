#include <iostream>
using namespace std;

/*
[Lab06] += 오버로딩: 참조 리턴이 핵심
---------------------------------------------------
핵심
- a += b 는 a 자체를 바꾼다(변경 연산자).
- 그래서 결과를 *this(자기 자신) 참조로 리턴하는 것이 관례.
  -> 체이닝: a += b += c 같은 형태 가능(설계에 따라).

실습 포인트
- operator+=는 보통 non-const.
- 인자는 const&로 받기.
---------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    Power& operator+=(const Power& op2) {
        kick += op2.kick;
        punch += op2.punch;
        return *this;
    }
};

int main() {
    Power a(3,5), b(4,6), c;
    c = (a += b);
    a.show();
    c.show();
    return 0;
}
