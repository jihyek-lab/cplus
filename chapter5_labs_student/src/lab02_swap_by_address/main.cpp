#include <iostream>
using namespace std;

/*
[Lab02] call by address (주소에 의한 호출) - 포인터로 swap 성공
------------------------------------------------------------
핵심
1) int* a, int* b는 원본의 "주소"를 받는다.
2) *a, *b는 원본 변수 공간을 직접 가리킨다.
3) 따라서 함수 안에서 *a, *b를 바꾸면 원본 m,n이 바뀐다.
------------------------------------------------------------
*/

void swapByAddress(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int m = 2, n = 9;
    swapByAddress(&m, &n); // &로 주소 전달
    cout << "m=" << m << " n=" << n << "\n"; // 9,2
    return 0;
}
