#include <iostream>
using namespace std;

/*
[Lab08] 형 변환으로 인한 모호성: int -> float/double ?
-----------------------------------------
핵심
- square(float)와 square(double)이 있을 때,
  square(3)에서 3(int)은 float로도, double로도 변환 가능.
- 어떤 쪽이 더 좋은지(더 우선인지) 애매하면 모호성 에러.

실습
- square(3) 주석을 풀고 컴파일 에러를 확인해보자.
- 해결 방법 예:
  square(3.0) 또는 square((float)3) 처럼 명시적 변환.
-----------------------------------------
*/

float square(float a) { return a * a; }
double square(double a) { return a * a; }

int main() {
    cout << square(3.0) << "\n"; // double 버전
    // cout << square(3) << "\n"; // (에러 확인) 모호
    return 0;
}
