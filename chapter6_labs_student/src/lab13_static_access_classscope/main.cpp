#include <iostream>
using namespace std;

/*
[Lab13] static 멤버 접근: 객체 / 클래스명::
-----------------------------------------
핵심
- static은 "객체 없이도 존재"하므로 ClassName::member 로 접근 가능.
- non-static은 객체가 있어야 하므로 ClassName:: 접근 불가.

실습
- Person::sharedMoney 처럼 클래스명으로 접근해보기.
-----------------------------------------
*/

class Person {
public:
    double money;
    static int sharedMoney;
    static void addShared(int n) { sharedMoney += n; }
};
int Person::sharedMoney = 10;

int main() {
    Person::addShared(50);
    cout << Person::sharedMoney << "\n";

    Person han;
    han.money = 100;
    han.sharedMoney = 200; // 공유값 변경

    Person::sharedMoney = 300;
    Person::addShared(100);

    cout << han.money << " " << Person::sharedMoney << "\n";

    // Person::money = 100; // (에러) non-static은 클래스명으로 접근 불가
    return 0;
}
