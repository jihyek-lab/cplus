#include <iostream>
using namespace std;

/*
[Lab04] 객체 주소 전달: 복사 없이 원본 변경
------------------------------------------------------------
핵심
1) void increase(Circle* p) : 포인터는 객체의 주소만 전달(복사본 없음)
2) p->setRadius(...) 로 원본 객체를 직접 변경할 수 있다.
------------------------------------------------------------
*/

class Circle {
    int radius;
public:
    Circle(int r) : radius(r) {}
    int getRadius() const { return radius; }
    void setRadius(int r) { radius = r; }
};

void increase(Circle* p) {
    p->setRadius(p->getRadius() + 1);
}

int main() {
    Circle waffle(30);
    increase(&waffle);
    cout << waffle.getRadius() << "\n"; // 31
    return 0;
}
