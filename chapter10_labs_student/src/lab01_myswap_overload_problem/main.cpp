#include <iostream>
using namespace std;

/*
[Lab01] 중복 함수의 문제: 타입만 다르고 내용은 동일
------------------------------------------------------------
- myswap(int&,int&) 와 myswap(double&,double&)는 코드가 똑같고 타입만 다름.
- 이런 복붙은 유지보수 비용 증가(버그 수정 시 2군데 수정).
- 해결: 템플릿(다음 lab)

이론 연결
- 오버로딩은 "같은 이름으로 비슷한 기능 묶기"에는 좋다.
- 하지만 구현 내용까지 똑같다면 중복 제거에는 한계가 있다.
- 즉, 오버로딩은 호출 문법을 정리하고, 템플릿은 구현 중복을 줄인다.
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
