#include <iostream>
using namespace std;

/*
[Lab07] call by reference (참조에 의한 호출) - swap 성공
------------------------------------------------------------
핵심
1) void swap(int& a, int& b) : a,b는 원본 변수의 "별명"
2) 포인터보다 문법이 깔끔하고, * / & 실수가 줄어든다.
------------------------------------------------------------
*/

void swapByRef(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int m = 2, n = 9;
    swapByRef(m, n);
    cout << "m=" << m << " n=" << n << "\n"; // 9,2
    return 0;
}
