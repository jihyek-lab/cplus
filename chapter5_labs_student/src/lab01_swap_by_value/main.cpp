#include <iostream>
using namespace std;

/*
[Lab01] call by value (값에 의한 호출) - swap 실패
------------------------------------------------------------
핵심
1) 함수 매개변수 a,b는 호출한 쪽(m,n)의 "복사본"이다.
2) 함수 안에서 a,b를 바꿔도 원본 m,n은 바뀌지 않는다.
------------------------------------------------------------
*/

void swapByValue(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int m = 2, n = 9;
    swapByValue(m, n);
    cout << "m=" << m << " n=" << n << "\n"; // 2,9 그대로
    return 0;
}
