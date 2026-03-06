#include <iostream>
using namespace std;

/*
[Lab04] sum() 오버로딩: 구간합 vs 0부터 합
-----------------------------------------
핵심
- sum(a,b): a부터 b까지 합
- sum(a)  : 0부터 a까지 합

주의
- 이런 오버로딩은 "의미"가 분명할 때만 쓰는 게 좋다.
- 학생들이 헷갈리면 함수 이름을 분리하는 편이 더 안전할 수 있다.
-----------------------------------------
*/

int sum(int a, int b) {
    int s = 0;
    for (int i = a; i <= b; i++) s += i;
    return s;
}

int sum(int a) {
    int s = 0;
    for (int i = 0; i <= a; i++) s += i;
    return s;
}

int main() {
    cout << sum(3, 5) << "\n"; // 12
    cout << sum(3) << "\n";    // 6
    cout << sum(100) << "\n";  // 5050
    return 0;
}
