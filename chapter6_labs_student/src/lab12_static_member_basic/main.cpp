#include <iostream>
using namespace std;

/*
[Lab12] static 멤버 변수/함수 기본
-----------------------------------------
비유
- non-static 멤버: 각 객체의 "개인 돈"
- static 멤버: 클래스 전체가 공유하는 "공금"

핵심
1) static 멤버 변수는 클래스당 1개만 존재(객체 수와 무관).
2) 반드시 클래스 밖에서 1번 정의해야 링크 오류가 안 난다.
   예) int Person::sharedMoney = 10;

여기서 확인할 것
- han.sharedMoney와 lee.sharedMoney는 같은 값을 공유한다.
-----------------------------------------
*/

class Person {
public:
    int money;
    void addMoney(int money) { this->money += money; }

    static int sharedMoney;
    static void addShared(int n) { sharedMoney += n; }
};

// (중요) static 변수 정의(없으면 linker error)
int Person::sharedMoney = 10;

int main() {
    Person han;
    han.money = 100;
    han.sharedMoney = 200;

    Person lee;
    lee.money = 150;
    lee.addMoney(200);
    lee.addShared(200);

    cout << han.money << " " << lee.money << "\n";
    cout << han.sharedMoney << " " << lee.sharedMoney << "\n";
    return 0;
}
