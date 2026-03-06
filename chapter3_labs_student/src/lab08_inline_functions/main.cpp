#include <iostream>
using namespace std;

/*
[Lab08] 인라인 함수(inline) + 자동 인라인 후보
------------------------------------------------------------
이 코드로 알아야 할 것(핵심 체크)
1) inline은 컴파일러에게 "함수 호출 대신 본문을 복사해 넣어도 좋다"는 힌트(강제 X).
2) 장점: 호출 오버헤드 감소 / 단점: 코드 크기 증가 가능
3) 클래스 선언부 안에 구현한 멤버 함수는 보통 인라인 후보(컴파일러가 본문을 쉽게 봄).
------------------------------------------------------------
*/

inline int odd(int x) { return x % 2; } // 짧고 자주 호출되는 함수

class Circle {
private:
    int radius;

public:
    Circle(int r) : radius(r) {}

    // (중요) 선언부 내부 구현 -> 자동 인라인 후보
    double getArea() const { return 3.14 * radius * radius; }
};

int main() {
    long long sum = 0;
    for (int i = 1; i <= 10000; i++) {
        if (odd(i)) sum += i;
    }
    cout << "sum of odds = " << sum << "\n";

    Circle c(3);
    cout << "area = " << c.getArea() << "\n";
    return 0;
}
