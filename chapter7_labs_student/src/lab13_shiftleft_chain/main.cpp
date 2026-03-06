#include <iostream>
using namespace std;

/*
[Lab13] << 연산자를 이용한 체이닝(교육용 예제)
---------------------------------------------------
핵심
- a << 3 << 5 << 6 처럼 "연쇄 호출"을 만들려면
  operator<<가 Power& 를 리턴해야 한다(참조 리턴).

주의(매우 중요)
- 실제 C++에서 <<는 보통 스트림 출력 연산자라
  이런 재정의는 오해를 유발한다.
- 교육 목적: "참조 리턴이 체이닝을 만든다"를 보여주는 예제.
---------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    Power& operator<<(int n) {
        kick += n;
        punch += n;
        return *this;
    }
};

int main() {
    Power a(1,2);
    a << 3 << 5 << 6;
    a.show();
    return 0;
}
