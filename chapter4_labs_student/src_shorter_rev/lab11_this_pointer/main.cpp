#include <iostream>
using namespace std;

/*
[Lab11] this 포인터: 이름 충돌 해결 + 자기 자신 반환
------------------------------------------------------------
핵심
1) this는 "현재 멤버 함수를 실행 중인 객체 자신"을 가리키는 포인터다.
2) 매개변수 이름과 멤버 이름이 같을 때:
   this->radius = radius;  (멤버 radius에 매개변수 radius를 대입)
3) return this; 패턴은 메서드 체이닝 등에서 사용 가능.
------------------------------------------------------------
*/

class Circle {
    int radius;
public:
    Circle() { this->radius = 1; }

    // 매개변수 radius와 멤버 radius가 같은 이름일 때 this로 구분
    Circle(int radius) { this->radius = radius; }

    void setRadius(int radius) { this->radius = radius; }

    Circle* self() { return this; } // 자기 자신 포인터 반환

    double getArea() const { return 3.14 * radius * radius; }
};

int main() {
    Circle c1;
    Circle c2(2);

    c1.setRadius(4);
    c2.setRadius(5);

    cout << c1.getArea() << "\n";
    cout << c2.getArea() << "\n";

    cout << (c1.self() == &c1 ? "same\n" : "diff\n");
    return 0;
}
