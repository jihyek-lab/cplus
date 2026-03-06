#include <iostream>
using namespace std;

/*
[Lab04] 구체화 실패: 서로 다른 타입을 한 템플릿에 넣으면?
------------------------------------------------------------
myswap(T&,T&)는 두 인자가 "같은 T"여야 한다.
- myswap(int&, double&)는 T를 하나로 결정할 수 없어서 컴파일 오류.

실습
- 아래 주석을 풀고 에러 메시지에서 어떤 이유로 실패했는지 확인.
------------------------------------------------------------
*/

template <class T>
void myswap(T& a, T& b) {
    T tmp = a; a = b; b = tmp;
}

int main() {
    int s = 4;
    double t = 5;
    // myswap(s, t); // (에러 확인) 타입 추론 실패
    cout << "OK\n";
}
