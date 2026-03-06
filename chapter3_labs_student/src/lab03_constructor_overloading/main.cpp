#include <iostream>
using namespace std;

/*
[Lab03] 생성자 오버로딩: 기본 생성자 vs 매개변수 생성자
------------------------------------------------------------
이 코드로 알아야 할 것(핵심 체크)
1) 생성자: 객체 생성 시 자동 호출되어 초기화를 담당한다.
2) 생성자 이름은 클래스 이름과 동일, 리턴 타입이 없다(심지어 void도 X).
3) 생성자 오버로딩: 매개변수 형태가 다르면 여러 생성자를 둘 수 있다.
4) 어떤 생성자가 호출되는지 출력으로 확인한다.
------------------------------------------------------------
*/

class Circle {
private:
    int radius;

public:
    // 기본 생성자: 매개변수 없음
    Circle() {
        radius = 1;
        cout << "[Ctor] radius = " << radius << "\n";
    }

    // 매개변수 생성자: 외부에서 초기값을 전달
    Circle(int r) {
        radius = r;
        cout << "[Ctor] radius = " << radius << "\n";
    }

    double getArea() const { return 3.14 * radius * radius; }
};

int main() {
    Circle donut;      // Circle() 호출
    cout << "donut area = " << donut.getArea() << "\n";

    Circle pizza(30);  // Circle(int) 호출
    cout << "pizza area = " << pizza.getArea() << "\n";

    return 0;
}
