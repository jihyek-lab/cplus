#include <iostream>
using namespace std;

/*
[Lab07] width/fill/precision: 포맷 함수
------------------------------------------------------------
핵심
- width(n): "다음 출력 1회"만 적용(1회성)
- fill(ch): 이후 출력에도 유지될 수 있음(상태 유지)
- precision(p): 이후 출력에도 유지(상태 유지)

관찰
- showWidth()를 2번 호출(중간에 fill 변경)
------------------------------------------------------------
*/

void showWidth() {
    cout.width(10);
    cout << "Hello" << "\n";

    cout.width(5);
    cout << 12 << "\n";

    cout << '%';
    cout.width(10);
    cout << "Korea/" << "Seoul/" << "City" << "\n";
}

int main() {
    showWidth();
    cout << "\n";

    cout.fill('^');
    showWidth();
    cout << "\n";

    cout.precision(5);
    cout << 11.0/3.0 << "\n";
}
