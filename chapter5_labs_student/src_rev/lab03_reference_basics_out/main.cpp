#include <iostream>
using namespace std;

/*
[Lab03] 참조 기본 + out 파라미터
------------------------------------------------------------
목표
- 참조가 "별명"임을 확인하고, 결과 전달(out) 패턴을 익힌다.

핵심
1) 참조는 반드시 초기화해야 하며, 원본과 주소가 같다.
2) 함수에서 결과를 참조 매개변수로 전달할 수 있다.
------------------------------------------------------------
*/

bool average(const int a[], int size, int& avg) {
    if (size <= 0) return false;
    int sum = 0;
    for (int i = 0; i < size; i++) sum += a[i];
    avg = sum / size;
    return true;
}

int main() {
    int n = 2;
    int& refn = n;
    refn = 4;
    refn++;
    cout << "n=" << n << " refn=" << refn << "\n";

    int* p = &refn; // 결국 n의 주소
    *p = 20;
    cout << "n=" << n << " refn=" << refn << "\n\n";

    int x[] = {0, 1, 2, 3, 4, 5};
    int avg;

    if (average(x, 6, avg)) cout << "avg=" << avg << "\n";
    else cout << "error\n";

    if (average(x, -2, avg)) cout << "avg=" << avg << "\n";
    else cout << "error\n";

    return 0;
}
