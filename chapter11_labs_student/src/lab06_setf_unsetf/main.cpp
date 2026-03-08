#include <iostream>
using namespace std;

/*
[Lab06] setf/unsetf: 포맷 플래그
------------------------------------------------------------
핵심
- cout.setf(ios::hex) 등으로 출력 형식 설정
- 플래그는 cout의 상태로 유지 -> 다음 출력에도 영향을 줌.
- unsetf로 특정 플래그 해제 가능

관찰
- 30을 10진/16진/0x표기/대문자/과학표기/부호표기 등으로 출력
------------------------------------------------------------
*/

int main() {
    cout << 30 << "\n";
    cout.unsetf(ios::dec);
    cout.setf(ios::hex);
    cout << 30 << "\n";

    cout.setf(ios::showbase);
    cout << 30 << "\n";

    cout.setf(ios::uppercase);
    cout << 30 << "\n";

    cout.setf(ios::dec | ios::showpoint);
    cout << 23.5 << "\n";

    cout.setf(ios::scientific);
    cout << 23.5 << "\n";

    cout.setf(ios::showpos);
    cout << 23.5 << "\n";
}
