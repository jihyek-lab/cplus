#include <iostream>
#include <string>
using namespace std;

/*
[Lab04] protected 접근 지정자
------------------------------------------------------------
핵심
- protected 멤버:
  1) 클래스 내부 OK
  2) 파생 클래스 내부 OK
  3) 외부(함수/다른 클래스)에서는 접근 불가

주의
- "파생 클래스 객체"라고 해도 외부에서 a.x 처럼 접근은 안 된다.
  (접근 권한은 '코드 위치' 기준이지 '객체 타입' 기준이 아님)
------------------------------------------------------------
*/

class Point {
protected:
    int x, y;
public:
    void set(int x, int y) { this->x=x; this->y=y; }
    void showPoint() const { cout << "(" << x << "," << y << ")\n"; }
};

class ColorPoint : public Point {
    string color;
public:
    void setColor(string c) { color=c; }
    bool equals(const ColorPoint& p) const {
        // 파생 클래스 내부라 x,y 직접 접근 가능
        return (x == p.x && y == p.y && color == p.color);
    }
};

int main() {
    Point p;
    p.set(2,3);
    // p.x = 5; // (에러) 외부에서 protected 접근 불가

    ColorPoint a; a.set(3,4); a.setColor("Red");
    ColorPoint b; b.set(3,4); b.setColor("Red");
    cout << (a.equals(b) ? "true\n" : "false\n");

    // a.x = 10; // (에러) 외부에서 protected 접근 불가
}
