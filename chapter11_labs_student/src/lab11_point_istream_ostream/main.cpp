#include <iostream>
using namespace std;

/*
[Lab11] operator>> 오버로딩: Point 입력
------------------------------------------------------------
핵심
- cin >> p 가 되려면 operator>>(istream&, Point&) 제공 필요.
- 입력 대상은 변경되므로 Point&로 받는다.
- 체이닝을 위해 istream& 를 리턴한다.
------------------------------------------------------------
*/

class Point {
    int x, y;
public:
    Point(int x=0, int y=0) : x(x), y(y) {}
    friend istream& operator>>(istream& ins, Point& a);
    friend ostream& operator<<(ostream& os, const Point& a);
};

istream& operator>>(istream& ins, Point& a) {
    cout << "x 좌표>>";
    ins >> a.x;
    cout << "y 좌표>>";
    ins >> a.y;
    return ins;
}

ostream& operator<<(ostream& os, const Point& a) {
    os << "(" << a.x << "," << a.y << ")";
    return os;
}

int main() {
    Point p;
    cin >> p;
    cout << p << "\n";
}
