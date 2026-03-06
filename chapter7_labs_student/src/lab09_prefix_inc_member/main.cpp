#include <iostream>
using namespace std;

/*
[Lab09] 전위 ++ 오버로딩(멤버)
---------------------------------------------------
핵심
- ++a  => a.operator++()
- 전위는 보통 "증가 후 자기 자신"을 참조로 리턴한다.
  -> 체이닝 가능: ++(++a)

실습 포인트
- 변경 연산이므로 non-const.
---------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    Power& operator++() {
        kick++; punch++;
        return *this;
    }
};

int main() {
    Power a(3,5), b;
    b = ++a;
    a.show();
    b.show();
    return 0;
}
