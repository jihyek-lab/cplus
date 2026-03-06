#include <iostream>
using namespace std;

/*
[Lab06] 가상 소멸자: Base*로 delete 할 가능성이 있으면 필수
------------------------------------------------------------
핵심
- Base* bp = new Derived();
- delete bp; 를 할 수 있다면, Base 소멸자는 반드시 virtual이어야 함.
- 그렇지 않으면 Derived 소멸자가 호출되지 않아 자원 해제 누락 가능.

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

    delete dp;
    delete bp;
}
