#include <iostream>
using namespace std;

/*
[Lab03] 템플릿은 사용자 정의 타입(클래스)에도 적용 가능
------------------------------------------------------------
조건
- T tmp = a;  (복사 생성/복사 대입 가능해야 함)
- a = b; b = tmp;  (대입 연산 가능)

여기서는 Circle이 단순한 값 타입이라 기본 복사로 가능.
(포인터 멤버가 있으면 5장의 Rule of 3 고려)
------------------------------------------------------------
*/

class Circle {
    int radius;
public:
    Circle(int radius=1) : radius(radius) {}
    int getRadius() const { return radius; }
};

template <class T>
void myswap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {
    Circle donut(5), pizza(20);
    myswap(donut, pizza);
    cout << donut.getRadius() << " " << pizza.getRadius() << "\n";
}
