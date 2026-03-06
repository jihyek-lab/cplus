#include <iostream>
using namespace std;

/*
[Lab02] 템플릿 함수 myswap<T>
------------------------------------------------------------
핵심
- template <class T> : T는 "타입 변수"
- 호출할 때 컴파일러가 T를 결정하고, 해당 타입 버전 함수를 생성(구체화).

관찰
- myswap(a,b)에서 a,b가 int -> T=int로 구체화
- myswap(c,d)에서 c,d가 double -> T=double로 구체화
------------------------------------------------------------
*/

template <class T>
void myswap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a=4, b=5;
    myswap(a,b);
    cout << a << '\t' << b << "\n";

    double c=0.3, d=12.5;
    myswap(c,d);
    cout << c << '\t' << d << "\n";
}
