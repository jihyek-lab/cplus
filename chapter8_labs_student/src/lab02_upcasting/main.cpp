#include <iostream>
#include <string>
using namespace std;

/*
[Lab02] 업캐스팅: Derived* -> Base*
------------------------------------------------------------
핵심
1) 업캐스팅은 자동 변환 가능: Point* p = (ColorPoint*)&cp; 같은 캐스팅 불필요
2) Base*로 접근할 때는 Base에 존재하는 멤버만 호출 가능
   - 파생 클래스만 가진 멤버는 호출 불가(컴파일 에러)
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
    ColorPoint* pDer = &cp;
    Point* pBase = pDer; // 자동 업캐스팅

    pDer->set(3,4);
    pBase->showPoint(); // OK

    pDer->setColor("Red");
    pDer->showColorPoint();

    // pBase->showColorPoint(); // (에러) Base에는 없음
}
