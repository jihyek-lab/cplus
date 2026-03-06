#include <iostream>
#include <string>
using namespace std;

/*
[Lab01] 상속 선언: Point -> ColorPoint
------------------------------------------------------------
핵심
1) class ColorPoint : public Point  (public 상속)
2) 파생 클래스 객체는 "기본 클래스 부분 + 파생 클래스 부분"을 함께 가진다.
3) 기본 클래스의 private 멤버(x,y)는 파생 클래스에서도 직접 접근 불가.
   - 접근하려면 public/protected 멤버 함수로 다룬다.
4) 파생 클래스는 기본 클래스의 public 멤버 함수를 그대로 사용할 수 있다.
------------------------------------------------------------
*/

class Point {
    int x, y; // private
public:
    void set(int x, int y) { this->x = x; this->y = y; }
    void showPoint() const { cout << "(" << x << "," << y << ")\n"; }
};

class ColorPoint : public Point {
    string color;
public:
    void setColor(string color) { this->color = color; }
    void showColorPoint() const { cout << color << ":"; showPoint(); }
};

int main() {
    ColorPoint cp;
    cp.set(3,4);           // base public
    cp.setColor("Red");    // derived
    cp.showColorPoint();
}
