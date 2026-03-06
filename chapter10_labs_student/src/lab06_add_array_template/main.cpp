#include <iostream>
using namespace std;

/*
[Lab06] add<T>(data[], n): 누적 합
------------------------------------------------------------
요구 조건(암묵적 제약)
- T sum = 0;  (0으로 초기화 가능해야 함)
- sum += data[i]; (+= 연산 가능해야 함)

주의
- 사용자 정의 타입에 쓰려면 "0" 의미, += 의미를 정의해야 한다.
  (또는 sum 초기화를 T()로 바꾸는 방식이 더 일반적)
------------------------------------------------------------
*/

template <class T>
T add(T data[], int n) {
    T sum = 0;
    for(int i=0; i<n; i++) sum += data[i];
    return sum;
}

int main() {
    int x[] = {1,2,3,4,5};
    double d[] = {1.2,2.3,3.4,4.5,5.6,6.7};
    cout << add(x,5) << "\n";
    cout << add(d,6) << "\n";
}
