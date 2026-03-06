#include <iostream>
using namespace std;

/*
[Lab06] 참조(reference) 기본: 별명(alias)
------------------------------------------------------------
핵심
1) int& ref = n;  => ref는 n의 "별명"이다. (새 메모리 공간 X)
2) 참조는 반드시 선언과 동시에 초기화해야 한다.
3) ref를 수정하면 n이 수정된다.
4) &ref == &n (주소도 동일)
------------------------------------------------------------
*/

int main() {
    int n = 2;
    int& refn = n;

    refn = 4;  // n도 4
    refn++;    // n도 증가
    cout << "n=" << n << " refn=" << refn << "\n";

    int* p = &refn; // 결국 n의 주소
    *p = 20;
    cout << "n=" << n << " refn=" << refn << "\n";

    return 0;
}
