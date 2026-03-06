#include <iostream>
using namespace std;

/*
[Lab01] 중복 함수의 문제: 타입만 다르고 내용은 동일
------------------------------------------------------------
- myswap(int&,int&) 와 myswap(double&,double&)는 코드가 똑같고 타입만 다름.
- 이런 복붙은 유지보수 비용 증가(버그 수정 시 2군데 수정).
- 해결: 템플릿(다음 lab)
------------------------------------------------------------
*/

void myswap(int& a, int& b) {
    int tmp = a; a = b; b = tmp;
}
void myswap(double& a, double& b) {
    double tmp = a; a = b; b = tmp;
}

int main() {
    int a=4, b=5;
    myswap(a,b);
    cout << a << '\t' << b << "\n";

    double c=0.3, d=12.5;
    myswap(c,d);
    cout << c << '\t' << d << "\n";
}
