#include <iostream>
using namespace std;

/*
[Lab09] 참조 매개변수 오버로딩의 함정: 호출만으로 구분 불가
-----------------------------------------
핵심
- add(int,int) 과 add(int,int&) 을 같이 두면
  add(s,t) 호출에서 t가 값인지 참조인지 "호출 문법상" 구분이 안 된다.
- 그래서 모호성 에러가 발생할 수 있다.

실무 팁
- 이런 형태는 오버로딩으로 해결하려 하지 말고
  함수 이름을 분리하거나, 의도를 명확히 하자.
-----------------------------------------
*/

int add(int a, int b) { return a + b; }
int add(int a, int& b) { b = b + a; return b; }

int main() {
    int s = 10, t = 20;
    // cout << add(s, t) << "\n"; // (에러 확인) 모호
    return 0;
}
