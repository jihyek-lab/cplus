#include <iostream>
using namespace std;

/*
[Lab04] 객체 배열 초기화: 원소별 생성자 지정
------------------------------------------------------------
핵심
1) 배열을 선언하면서 { Circle(10), Circle(20), Circle() }처럼
   각 원소를 어떤 생성자로 만들지 지정할 수 있다.
2) 이 방식이면 기본 생성자가 없어도 되는가?
   - 여기서는 Circle()도 쓰므로 기본 생성자가 있어야 한다.
   - 만약 모두 Circle(int)로만 채우면 기본 생성자가 없어도 된다.
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
    Circle circleArray[3] = { Circle(10), Circle(20), Circle() };

    for (int i = 0; i < 3; i++)
        cout << "Circle " << i << " area = " << circleArray[i].getArea() << "\n";

    return 0;
}
