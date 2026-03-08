#include <iostream>
using namespace std;

/*
[Lab09] operator<< 오버로딩: Point 출력
------------------------------------------------------------
핵심
- cout << p 가 되려면 operator<<(ostream&, const Point&) 제공 필요.
- 체이닝을 위해 ostream& 를 리턴한다.
- private 접근이 필요하면 friend 선언.

관찰
- cout << q << r << "\\n"; 처럼 연속 출력 가능
------------------------------------------------------------
*/

class Point {
    int x, y;
public:
    Point(int x=0, int y=0) : x(x), y(y) {}
    friend ostream& operator<<(ostream& os, const Point& a);
};

ostream& operator<<(ostream& os, const Point& a) {
    os << "(" << a.x << "," << a.y << ")";
    return os;
}

int main() {
    Point p(3,4);
    cout << p << "\n";
    Point q(1,100), r(2,200);
    cout << q << r << "\n";
}
