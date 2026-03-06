#include <iostream>
using namespace std;

/*
[Lab11] 후위 ++ 오버로딩(멤버)
---------------------------------------------------
핵심
- a++  => a.operator++(int)
- 후위 구분을 위해 의미 없는 int 매개변수를 둔다.
- 후위는 "증가 전 값"을 값으로 리턴하는 것이 관례.

실습 포인트
- 전위/후위를 출력으로 확실히 비교해보기.
---------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    Power operator++(int) {
        Power tmp = *this;
        kick++; punch++;
        return tmp;
    }
};

int main() {
    Power a(3,5), b;
    b = a++;
    a.show(); // 증가 후
    b.show(); // 증가 전
    return 0;
}
