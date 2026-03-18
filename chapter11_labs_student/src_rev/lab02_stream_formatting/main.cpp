#include <iostream>
#include <iomanip>
using namespace std;

/*
[Lab02] 포맷 플래그 + 조작자
------------------------------------------------------------
문제 설명
1) setf/unsetf로 출력 포맷을 바꾼다.
2) width/fill/precision의 동작(1회성/지속성)을 확인한다.
3) iomanip 조작자를 이용해 동일 작업을 수행한다.
------------------------------------------------------------
핵심 요약
- setf는 상태를 바꾸며, 출력에 계속 영향
- width는 1회성, fill/precision은 상태 유지
- 조작자(hex, setw 등)는 가독성이 좋다
------------------------------------------------------------
주의 포인트
- setf/unsetf는 이후 출력에도 영향을 주므로 초기화 필요할 수 있다.
- width는 다음 출력 1회에만 적용된다.
------------------------------------------------------------
*/

void demo_setf() {
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
    cout << 23.5 << "\n\n";
}

void demo_width_fill_precision() {
    cout.width(10);
    cout << "Hello" << "\n";

    cout.width(5);
    cout << 12 << "\n";

    cout << '%';
    cout.width(10);
    cout << "Korea/" << "Seoul/" << "City" << "\n";

    cout.fill('^');
    cout.width(10);
    cout << "Hello" << "\n";

    cout.precision(5);
    cout << 11.0/3.0 << "\n\n";
}

void demo_iomanip() {
    cout << hex << showbase << 30 << "\n";
    cout << dec << showpos << 100 << "\n";

    cout << true << ' ' << false << "\n";
    cout << boolalpha << true << ' ' << false << "\n";

    cout << setw(10) << setfill('^') << "Hello" << "\n";
}

int main() {
    demo_setf();
    demo_width_fill_precision();
    demo_iomanip();
}
