#include <iostream>
using namespace std;

/*
[Lab03] 객체를 값으로 전달하면 "복사"가 발생한다
------------------------------------------------------------
핵심
1) void increase(Circle c) 처럼 값으로 받으면, 매개변수 c는 원본의 "복사본"이다.
2) 따라서 c를 변경해도 원본은 변하지 않는다.
3) 복사본은 함수가 끝나면 소멸된다(소멸자 호출).
   -> 출력 메시지로 관찰하면 생성/소멸이 비대칭처럼 보일 수 있다.
------------------------------------------------------------
*/

class Circle {
    int radius;
public:
    Circle() : radius(1) { cout << "[Ctor] radius=" << radius << "\n"; }
    Circle(int r) : radius(r) { cout << "[Ctor] radius=" << radius << "\n"; }
    ~Circle() { cout << "[Dtor] radius=" << radius << "\n"; }

    int getRadius() const { return radius; }
    void setRadius(int r) { radius = r; }
};

void increase(Circle c) { // 값 전달 -> 복사본
    c.setRadius(c.getRadius() + 1);
}

int main() {
    Circle waffle(30);
    increase(waffle);
    cout << "waffle radius=" << waffle.getRadius() << "\n"; // 30 그대로
    return 0;
}
