#include <iostream>
using namespace std;

/*
[Lab07] a + 2 는 멤버 operator+(int)로 가능
---------------------------------------------------
핵심
- a + 2  => a.operator+(2)
- 왼쪽이 Power 객체이므로 멤버 함수로 구현 가능.

중요
- 2 + a 는 왼쪽이 int라서 멤버 함수 방식으로는 불가능.
  -> friend(외부 연산자 함수)로 해결해야 함.
---------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    Power operator+(int op2) const {
        return Power(kick + op2, punch + op2);
    }
};

int main() {
    Power a(3,5), b;
    b = a + 2;
    a.show();
    b.show();
    return 0;
}
