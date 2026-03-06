#include <iostream>
using namespace std;

/*
[Lab01] 객체 포인터: -> 와 (*p).
------------------------------------------------------------
이 코드로 알아야 할 것(핵심)
1) 객체 포인터는 "객체의 주소"를 저장한다.  (Circle* p)
2) 포인터로 멤버 접근:
   - p->getArea()  (가장 흔한 문법)
   - (*p).getArea() (동일 의미, 괄호 필수)
3) 같은 포인터 변수 p가 어떤 객체를 가리키는지에 따라 호출 결과가 달라진다.
------------------------------------------------------------
*/

class Circle {
    int radius;
public:
    Circle() : radius(1) {}
    Circle(int r) : radius(r) {}
    double getArea() const { return 3.14 * radius * radius; }
};

int main() {
    Circle donut;
    Circle pizza(30);

    cout << "[obj] donut area = " << donut.getArea() << "\n";

    Circle* p = &donut; // (1) donut의 주소를 저장
    cout << "[ptr] donut area = " << p->getArea() << "\n";     // (2) -> 사용
    cout << "[ptr] donut area = " << (*p).getArea() << "\n";   // (3) (*p). 사용

    p = &pizza;         // (4) 이제 pizza를 가리킴
    cout << "[ptr] pizza area = " << p->getArea() << "\n";

    return 0;
}
