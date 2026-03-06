#include <iostream>
using namespace std;

/*
[Lab09] 객체를 참조로 전달: 복사 없이 원본 변경
------------------------------------------------------------
핵심
1) void f(Circle& c) : c는 원본 객체의 별명(복사본 없음)
2) 따라서 함수 안에서 c를 바꾸면 원본이 바뀐다.
3) 값 전달과 가장 큰 차이는 "복사 생성"이 일어나지 않는다는 것.
------------------------------------------------------------
*/

class Circle {
    int radius;
public:
    Circle(int r) : radius(r) { cout << "[Ctor] " << radius << "\n"; }
    ~Circle() { cout << "[Dtor] " << radius << "\n"; }
    int getRadius() const { return radius; }
    void setRadius(int r) { radius = r; }
};

void increaseCircle(Circle& c) {
    c.setRadius(c.getRadius() + 1);
}

int main() {
    Circle waffle(30);
    increaseCircle(waffle);
    cout << waffle.getRadius() << "\n";
    return 0;
}
