#include <iostream>
#include <iomanip>
using namespace std;

/*
[Lab08] 조작자(manipulator)
------------------------------------------------------------
매개변수 없는 조작자
- hex, dec, showbase, showpos, boolalpha 등

매개변수 있는 조작자 (<iomanip>)
- setw, setfill, setprecision 등

관찰
- 표 형태로 10진/8진/16진 출력
- setfill이 상태를 바꾸는지 확인
------------------------------------------------------------
*/

int main() {
    cout << hex << showbase << 30 << "\n";
    cout << dec << showpos << 100 << "\n";

    cout << true << ' ' << false << "\n";
    cout << boolalpha << true << ' ' << false << "\n";

    cout << setw(10) << setfill('^') << "Hello" << "\n";

    cout << showbase;
    cout << setw(8) << "Number" << setw(10) << "Octal" << setw(10) << "Hexa" << "\n";
    for (int i = 0; i < 50; i += 5) {
        cout << setw(8) << setfill('.') << dec << i;
        cout << setw(10) << setfill(' ') << oct << i;
        cout << setw(10) << setfill(' ') << hex << i << "\n";
    }
}
