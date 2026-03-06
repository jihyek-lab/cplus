#include <iostream>
#include <string>
using namespace std;

/*
[Lab05] 디폴트 매개변수(Default Parameter) 기본
-----------------------------------------
핵심
- 매개변수에 기본값을 주면, 호출할 때 해당 인수를 생략할 수 있다.
- 보통 "선언(원형)"에서 디폴트 값을 주는 게 관례.
  (헤더/구현 분리 시 중복 선언을 피하기 쉬움)

여기서 확인할 것
- star();        -> star(5)
- star(10);      -> star(10)
- msg(10);       -> msg(10,"")
- msg(10,"Hi");  -> msg(10,"Hi")
-----------------------------------------
*/

void star(int a = 5);
void msg(int id, string text = "");

void star(int a) {
    for (int i = 0; i < a; i++) cout << '*';
    cout << "\n";
}

void msg(int id, string text) {
    cout << id << " " << text << "\n";
}

int main() {
    star();
    star(10);
    msg(10);
    msg(10, "Hello");
    return 0;
}
