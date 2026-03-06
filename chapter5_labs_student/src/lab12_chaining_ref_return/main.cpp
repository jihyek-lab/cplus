#include <iostream>
using namespace std;

/*
[Lab12] 객체 참조 리턴 + 메서드 체이닝
------------------------------------------------------------
핵심
1) 멤버 함수가 Circle& 를 리턴하고, return *this; 를 하면
   "현재 객체 자신"을 참조로 돌려준다.
2) 그러면 a.plus(1).plus(2) 처럼 연쇄 호출(체이닝)이 가능하다.
------------------------------------------------------------
*/

class Circle {
    int radius;
public:
    Circle(int r) : radius(r) {}

    Circle& plus(int n) { // 참조 리턴
        radius += n;
        return *this;     // 현재 객체 참조
    }

    int getRadius() const { return radius; }
};

int main() {
    Circle a(5);
    a.plus(1).plus(2).plus(3);
    cout << a.getRadius() << "\n"; // 11
    return 0;
}
