#include <iostream>
using namespace std;

/*
[Lab16] static 멤버 함수의 제한: this / non-static 접근 불가
-----------------------------------------
핵심
- static 함수는 "객체 없이 호출" 가능 => this가 존재하지 않는다.
- 따라서 non-static 멤버(money 같은, 객체마다 다른 값)에 접근할 수 없다.

실습
- 아래 static getMoney() 주석을 풀면 컴파일 에러를 확인할 수 있다.
-----------------------------------------
*/

class PersonError {
    int money; // non-static
public:
    // static int getMoney() { return money; } // (에러 확인) static에서 non-static 접근 불가
    void setMoney(int money) { this->money = money; }
};

int main() {
    PersonError e;
    e.setMoney(100);
    cout << "OK\n";
    return 0;
}
