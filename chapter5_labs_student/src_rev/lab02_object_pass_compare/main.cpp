#include <iostream>
using namespace std;

/*
[Lab02] 객체 전달 방식 비교 (값 / 주소 / 참조)
------------------------------------------------------------
목표
- 객체를 값/주소/참조로 넘겼을 때 복사와 원본 변경 차이를 확인한다.

핵심
1) 값 전달: 복사본 생성(복사 생성자 호출)
2) 주소 전달: 포인터로 원본 수정
3) 참조 전달: 별명으로 원본 수정
------------------------------------------------------------
*/

class Circle {
    int radius;
public:
    // 생성자/복사생성자/소멸자에서 로그를 찍어
    // "복사 발생 여부"와 "생성/소멸 시점"을 눈으로 확인한다.
    Circle(int r) : radius(r) { cout << "[Ctor] " << radius << "\n"; }
    Circle(const Circle& c) : radius(c.radius) { cout << "[CopyCtor] " << radius << "\n"; }
    ~Circle() { cout << "[Dtor] " << radius << "\n"; }

    int getRadius() const { return radius; }
    void setRadius(int r) { radius = r; }
};

// 값 전달: 복사본이 만들어지고, 원본은 바뀌지 않는다.
void incByValue(Circle c) {
    c.setRadius(c.getRadius() + 1);
}

// 주소 전달: 포인터가 원본을 가리키므로 원본이 바뀐다.
void incByAddress(Circle* p) {
    p->setRadius(p->getRadius() + 1);
}

// 참조 전달: 별명으로 원본을 직접 수정한다.
void incByRef(Circle& c) {
    c.setRadius(c.getRadius() + 1);
}

int main() {
    Circle waffle(30); // 원본 객체

    incByValue(waffle); // 복사본만 +1
    cout << "after value : " << waffle.getRadius() << "\n\n";

    incByAddress(&waffle); // 원본 +1
    cout << "after addr  : " << waffle.getRadius() << "\n\n";

    incByRef(waffle); // 원본 +1
    cout << "after ref   : " << waffle.getRadius() << "\n";

    return 0;
}
