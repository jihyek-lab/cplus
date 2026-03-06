#include <iostream>
using namespace std;

/*
[Lab07] mcopy<T1,T2>: 서로 다른 타입 배열 복사
------------------------------------------------------------
핵심
- 템플릿 타입을 2개 사용한다.
  T1: source 타입, T2: destination 타입
- dest[i] = (T2)src[i] 로 캐스팅

주의
- 정밀도 손실/범위 초과 가능(예: double -> int)
- 안전한 변환이 필요하면 static_cast<T2>(...) 사용 + 정책 결정
------------------------------------------------------------
*/

template <class T1, class T2>
void mcopy(T1 src[], T2 dest[], int n) {
    for(int i=0; i<n; i++)
        dest[i] = (T2)src[i];
}

int main() {
    int x[] = {1,2,3,4,5};
    double d[5];

    char c[5] = {'H','e','l','l','o'}, e[5];

    mcopy(x, d, 5);
    mcopy(c, e, 5);

    for(int i=0;i<5;i++) cout << d[i] << ' ';
    cout << "\n";
    for(int i=0;i<5;i++) cout << e[i] << ' ';
    cout << "\n";
}
