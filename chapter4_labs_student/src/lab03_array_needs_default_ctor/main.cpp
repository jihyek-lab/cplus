#include <iostream>
using namespace std;

/*
[Lab03] 객체 배열에는 왜 기본 생성자가 필요할까?
------------------------------------------------------------
핵심
1) Circle arr[3]; 을 만들 때, 각 원소를 "매개변수 없이" 만들어야 한다.
2) 즉, 컴파일러는 각 원소에 대해 Circle()을 호출하려고 한다.
3) 그런데 Circle()이 없다면(=기본 생성자 없음), 배열을 만들 수 없어 컴파일 에러가 난다.
------------------------------------------------------------
실습: 주석을 풀면 왜 에러인지 확인해보기
*/

class Circle {
    int radius;
public:
    Circle(int r) : radius(r) {} // 기본 생성자 없음!
    double getArea() const { return 3.14 * radius * radius; }
};

int main() {
    Circle waffle(15);  // OK (Circle(int) 호출)

    // Circle circleArray[3]; // (에러) Circle()이 없어 배열 생성 불가

    cout << waffle.getArea() << "\n";
    return 0;
}
