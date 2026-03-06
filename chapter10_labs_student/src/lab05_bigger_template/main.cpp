#include <iostream>
using namespace std;

/*
[Lab05] bigger<T>: 비교 연산(>)이 가능한 타입만 사용 가능
------------------------------------------------------------
- 템플릿 내부에서 a > b를 쓰면,
  T 타입이 operator>를 지원해야 한다.
- 기본 타입은 OK.
- 사용자 정의 타입이면 7장의 operator> 오버로딩이 필요할 수 있다.
------------------------------------------------------------
*/

template <class T>
T bigger(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int a=20, b=50;
    char c='a', d='z';
    cout << bigger(a,b) << "\n";
    cout << bigger(c,d) << "\n";
}
