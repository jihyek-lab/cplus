#include <iostream>
using namespace std;

/*
[Lab08] 동적 배열: new T[n] 와 delete[]
------------------------------------------------------------
핵심
1) int* p = new int[n];    => 힙에 int n개(배열) 할당
2) 배열은 p[i]로 접근
3) 배열 반환은 delete[] p;  (대괄호 필수!)
------------------------------------------------------------
실습 포인트
- 입력 받은 n개 정수의 평균을 계산한다.
*/

int main() {
    cout << "How many integers? ";
    int n;
    cin >> n;
    if (n <= 0) return 0;

    int* p = new int[n]; // (1) 배열 동적 할당

    for (int i = 0; i < n; i++) {
        cout << (i + 1) << "th: ";
        cin >> p[i];
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) sum += p[i];

    cout << "avg = " << (sum / n) << "\n";

    delete[] p; // (2) 배열 반환은 delete[]
    return 0;
}
