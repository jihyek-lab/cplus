#include <iostream>
#include <string>
using namespace std;

/*
[Lab07] 오버로딩 + 디폴트 매개변수 => 호출 모호성
-----------------------------------------
핵심
- msg(int) 와 msg(int,string="") 를 동시에 두면,
  msg(6) 호출이 두 함수 모두에 "가능"해져서 모호해진다.
- 컴파일러는 하나를 선택할 근거가 없어서 컴파일 에러.

실습
- msg(6) 주석을 풀면 에러가 나는지 확인.
-----------------------------------------
*/

void msg(int id) { cout << id << "\n"; }
void msg(int id, string s = "") { cout << id << ":" << s << "\n"; }

int main() {
    msg(5, "Good Morning");
    // msg(6); // (에러 확인) 호출 모호
    return 0;
}
