#include <iostream>
using namespace std;

/*
[Lab01] 함수 중복(Overloading) 기본
-----------------------------------------
핵심 규칙
- 같은 이름의 함수가 여러 개 있어도 된다.
- 단, "매개변수 리스트(타입/개수)"가 달라야 한다.
- 리턴 타입은 오버로딩 구분 기준이 아니다.

여기서 확인할 것
- sum(2,6)은 int,int 버전 호출
- sum(2,5,33)은 int,int,int 버전 호출
- sum(12.5,33.6)은 double,double 버전 호출
-----------------------------------------
*/

int sum(int a, int b) { return a + b; }
int sum(int a, int b, int c) { return a + b + c; }
double sum(double a, double b) { return a + b; }

int main() {
    cout << sum(2, 6) << "\n";
    cout << sum(2, 5, 33) << "\n";
    cout << sum(12.5, 33.6) << "\n";
    return 0;
}
