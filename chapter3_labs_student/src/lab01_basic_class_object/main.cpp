#include <iostream>
using namespace std;

/*
[Lab01] 클래스/객체 기본
------------------------------------------------------------
이 코드로 알아야 할 것(핵심 체크)
1) class = 설계도, object(instance) = 메모리에 생성된 실체
2) 멤버 변수 = 상태(state), 멤버 함수 = 행동(behavior)
3) 클래스 밖에서 멤버 함수를 구현할 때는 ClassName::func 형태(::) 사용
4) 객체는 '.' 연산자로 멤버에 접근/호출한다.
------------------------------------------------------------
*/

class Circle {
public:
    int radius;            // (상태) 멤버 변수: 원의 반지름
    double getArea();      // (행동) 멤버 함수 선언(원형)
};

// (중요) 멤버 함수 정의: Circle 클래스 소속임을 ::로 표시
double Circle::getArea() {
    // (공식) 원의 넓이 = πr^2 (여기서는 π≈3.14 사용)
    return 3.14 * radius * radius;
}

int main() {
    Circle donut;          // (객체 생성) Circle 타입의 인스턴스 donut 생성
    donut.radius = 1;      // (상태 변경) donut 객체의 radius를 1로 설정
    cout << "donut area = " << donut.getArea() << "\n"; // 멤버 함수 호출

    Circle pizza;          // 또 다른 객체 생성 (서로 다른 상태를 가질 수 있음)
    pizza.radius = 30;
    cout << "pizza area = " << pizza.getArea() << "\n";

    return 0;
}
