#include <iostream>
using namespace std;

/*
[Lab01] 함수 템플릿 기초 (myswap / bigger / add)
------------------------------------------------------------
문제 설명
1) 타입만 다른 중복 함수를 템플릿으로 일반화한다.
2) 템플릿은 \"요구되는 연산\"이 가능해야 한다.
------------------------------------------------------------
핵심 요약
- template<class T>는 \"타입 변수\"를 의미한다.
- T가 지원하는 연산(>, += 등)이 없으면 컴파일 오류가 난다.
- 기본 타입뿐 아니라 사용자 정의 타입에도 적용 가능(복사/대입 필요).
------------------------------------------------------------
주의 포인트
- 템플릿은 컴파일 시점에 코드가 생성된다(구체화).
------------------------------------------------------------
*/

template <class T>
void myswap(T& a, T& b) {
    T tmp = a; a = b; b = tmp;
}

template <class T>
T bigger(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
T add(T data[], int n) {
    T sum = T(); // T의 기본값
    for(int i=0; i<n; i++) sum += data[i];
    return sum;
}

class Circle {
    int radius;
public:
    Circle(int r=1) : radius(r) {}
    int getRadius() const { return radius; }
    bool operator>(const Circle& other) const { return radius > other.radius; }
    Circle operator+=(const Circle& other) { radius += other.radius; return *this; }
};

int main() {
    int a=4, b=5; myswap(a,b);
    cout << a << '\t' << b << "\n";

    double c=0.3, d=12.5; myswap(c,d);
    cout << c << '\t' << d << "\n";

    cout << bigger(20, 50) << "\n";
    cout << bigger('a','z') << "\n";

    int x[] = {1,2,3,4,5};
    double y[] = {1.2,2.3,3.4,4.5,5.6,6.7};
    cout << add(x,5) << "\n";
    cout << add(y,6) << "\n";

    Circle c1(5), c2(2);
    cout << bigger(c1, c2).getRadius() << "\n";

    return 0;
}
