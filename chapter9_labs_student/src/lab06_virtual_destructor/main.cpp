#include <iostream>
using namespace std;

/*
[Lab06] 가상 소멸자: Base*로 delete 할 가능성이 있으면 필수
------------------------------------------------------------
핵심
- Base* bp = new Derived();
- delete bp; 를 할 수 있다면, Base 소멸자는 반드시 virtual이어야 함.
- 그렇지 않으면 Derived 소멸자가 호출되지 않아 자원 해제 누락 가능.

이론 연결
- 생성자는 위에서 아래로, 소멸자는 아래에서 위로 호출된다.
- 부모 포인터로 삭제하는 순간 어떤 소멸자를 먼저 시작할지 결정해야 하므로 virtual이 필요하다.
- 실무에서는 "가상 함수를 하나라도 가진 부모 클래스"라면 소멸자도 virtual로 두는 경우가 많다.

관찰 포인트
- delete dp (Derived*)는 항상 안전(둘 다 호출됨)
- delete bp (Base*)도 virtual이면 안전(둘 다 호출됨)
------------------------------------------------------------
*/

class Base {
public:
    virtual ~Base() { cout << "~Base()\n"; }
};

class Derived : public Base {
public:
    ~Derived() override { cout << "~Derived()\n"; }
};

int main() {
    Derived* dp = new Derived();
    Base* bp = new Derived();

    // 실제 타입을 정확히 알고 지우는 경우
    delete dp;
    // 부모 타입으로 지우는 경우: Base 소멸자가 virtual이어야 안전
    delete bp;
}
