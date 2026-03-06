#include <iostream>
using namespace std;

/*
[Lab08] 참조 매개변수로 결과 전달(out parameter)
------------------------------------------------------------
목표
- 평균이 0인지 에러인지 구분이 어려운 문제를 해결한다.

핵심
1) 성공/실패는 bool 리턴
2) 결과(avg)는 참조 매개변수로 전달한다.
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
    int x[] = {0, 1, 2, 3, 4, 5};
    int avg;

    if (average(x, 6, avg)) cout << "avg=" << avg << "\n";
    else cout << "error\n";

    if (average(x, -2, avg)) cout << "avg=" << avg << "\n";
    else cout << "error\n";

    return 0;
}
