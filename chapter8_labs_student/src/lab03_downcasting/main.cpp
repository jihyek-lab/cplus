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
    Point* pBase = &cp; // 업캐스팅

    pBase->set(3,4);
    pBase->showPoint();

    ColorPoint* pDer = (ColorPoint*)pBase; // 다운캐스팅(강제)
    pDer->setColor("Red");
    pDer->showColorPoint();
}
