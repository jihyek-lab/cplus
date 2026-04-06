#include <iostream>
#include <string>
using namespace std;

/*
[Lab03] 다운캐스팅: Base* -> Derived* (주의!)
------------------------------------------------------------
핵심
1) 다운캐스팅은 자동 변환이 아니다. 명시적 캐스팅이 필요.
2) "실제로 가리키는 객체"가 파생 클래스일 때만 안전.
   - Base 객체를 Derived*로 잘못 캐스팅하면 UB(정의되지 않은 동작).
3) 안전한 런타임 체크(dynamic_cast)는 "가상 함수(9장)" 이후 권장.
4) 다운캐스팅은 "기반 타입으로 보관하던 객체를 다시 파생 타입 기능까지 쓰기 위해" 필요하다.
------------------------------------------------------------
*/

class Point {
    int x, y;
public:
    void set(int x, int y) { this->x=x; this->y=y; }
    void showPoint() const { cout << "(" << x << "," << y << ")\n"; }
};
class ColorPoint : public Point {
    string color;
public:
    void setColor(string c) { color=c; }
    void showColorPoint() const { cout << color << ":"; showPoint(); }
};

int main() {
    ColorPoint cp;

    // 먼저 기반 클래스 포인터로 받는다.
    // 이렇게 받아 두면 공통 기능(showPoint 등)은 통일해서 처리할 수 있다.
    Point* pBase = &cp; // 업캐스팅

    pBase->set(3,4);
    pBase->showPoint();

    // 강의 코멘트:
    // 그런데 이제는 ColorPoint만의 기능(setColor, showColorPoint)이 필요해졌다.
    // 이럴 때 기반 클래스 포인터를 다시 파생 클래스 포인터로 바꾸는 것이 다운캐스팅이다.
    ColorPoint* pDer = (ColorPoint*)pBase; // 다운캐스팅(강제)
    pDer->setColor("Red");
    pDer->showColorPoint();

    // 강의 코멘트:
    // 지금은 pBase가 실제로 ColorPoint 객체 cp를 가리키므로 안전하다.
    // 하지만 실제 객체가 그냥 Point였다면 이 캐스팅은 매우 위험하다.
}
