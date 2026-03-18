#include <iostream>
#include <string>
using namespace std;

/*
[Lab01] 상속 기본 + 업/다운캐스팅 + protected
------------------------------------------------------------
문제 설명
1) Point -> ColorPoint 상속에서 기본 개념을 확인한다.
2) 업캐스팅/다운캐스팅의 가능 범위와 위험성을 비교한다.
3) protected 멤버의 접근 규칙을 확인한다.
------------------------------------------------------------
핵심 요약
- public 상속: 기반 클래스 public 멤버를 그대로 사용 가능
- 업캐스팅(파생 -> 기반)은 자동, 다운캐스팅은 위험(실제 타입 확인 필요)
- protected는 "파생 클래스 내부"에서만 접근 가능
------------------------------------------------------------
*/

class Point {
protected:
    int x, y; // protected: 파생 클래스 내부에서 접근 가능
public:
    void set(int x, int y) { this->x = x; this->y = y; }
    void showPoint() const { cout << "(" << x << "," << y << ")\n"; }
};

class ColorPoint : public Point {
    string color;
public:
    void setColor(string color) { this->color = color; }
    void showColorPoint() const { cout << color << ":"; showPoint(); }

    bool equals(const ColorPoint& p) const {
        // protected 멤버는 파생 클래스 내부에서 직접 접근 가능
        return (x == p.x && y == p.y && color == p.color);
    }
};

int main() {
    // (1) 상속 기본
    ColorPoint cp;
    cp.set(3,4);           // base public
    cp.setColor("Red");    // derived
    cp.showColorPoint();

    // (2) 업캐스팅
    ColorPoint* pDer = &cp;
    Point* pBase = pDer; // 자동 업캐스팅
    pBase->showPoint();  // Base 멤버만 접근 가능

    // (3) 다운캐스팅 (주의)
    Point* pBase2 = &cp;
    ColorPoint* pDer2 = (ColorPoint*)pBase2; // 실제 객체가 ColorPoint일 때만 안전
    pDer2->setColor("Blue");
    pDer2->showColorPoint();

    // (4) protected 접근 확인
    ColorPoint a; a.set(3,4); a.setColor("Red");
    ColorPoint b; b.set(3,4); b.setColor("Red");
    cout << (a.equals(b) ? "true\n" : "false\n");

    // a.x = 10; // (에러) 외부에서 protected 접근 불가
    return 0;
}
