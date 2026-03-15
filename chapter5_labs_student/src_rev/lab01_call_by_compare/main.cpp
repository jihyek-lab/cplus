#include <iostream>
using namespace std;

/*
[Lab01] 호출 방식 비교 (값 / 주소 / 참조)
------------------------------------------------------------
목표
- 같은 swap을 3가지 방식으로 구현해 차이를 비교한다.

핵심
1) 값 전달: 복사본이라 원본이 바뀌지 않는다.
2) 주소 전달: 포인터로 원본을 직접 수정한다.
3) 참조 전달: 별명으로 원본을 직접 수정한다.
------------------------------------------------------------
*/

void swapByValue(int a, int b) {
    int tmp = a; a = b; b = tmp;
}

void swapByAddress(int* a, int* b) {
    int tmp = *a; *a = *b; *b = tmp;
}

void swapByRef(int& a, int& b) {
    int tmp = a; a = b; b = tmp;
}

int main() {
    int m = 2, n = 9;

    swapByValue(m, n);
    cout << "value : m=" << m << " n=" << n << "\n";

    swapByAddress(&m, &n);
    cout << "addr  : m=" << m << " n=" << n << "\n";

    swapByRef(m, n);
    cout << "ref   : m=" << m << " n=" << n << "\n";

    return 0;
}
