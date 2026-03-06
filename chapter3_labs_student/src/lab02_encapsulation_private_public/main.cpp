#include <iostream>
using namespace std;

/*
[Lab02] 캡슐화: private 멤버 변수 + public 인터페이스
------------------------------------------------------------
이 코드로 알아야 할 것(핵심 체크)
1) 멤버 변수를 private로 숨기면, 외부에서 마음대로 값을 바꿀 수 없다.
2) 대신 public 함수(getter/setter 또는 의미 있는 함수)로만 상태를 다룬다.
3) setter에서 유효성 검사(예: r>0)를 넣어 객체 상태(불변식)를 보호할 수 있다.
------------------------------------------------------------
*/

class Circle {
private:
    int radius;  // (보호할 상태) 외부에서 직접 접근 불가

public:
    // 생성자: 객체 생성 순간 반지름 초기화
    Circle(int r) { radius = r; }

    // getter: radius를 읽는 인터페이스
    int getRadius() const { return radius; }

    // setter: radius를 바꾸는 인터페이스 (유효성 검사 가능)
    void setRadius(int r) {
        if (r > 0) radius = r;
        // (확장) r<=0일 때 메시지 출력은 미니과제에서!
    }

    // 의미 있는 기능 제공: 넓이 계산
    double getArea() const { return 3.14 * radius * radius; }
};

int main() {
    Circle c(5);

    // c.radius = 10; // (컴파일 에러) radius는 private

    cout << "r = " << c.getRadius() << ", area = " << c.getArea() << "\n";
    c.setRadius(10);
    cout << "r = " << c.getRadius() << ", area = " << c.getArea() << "\n";

    return 0;
}
