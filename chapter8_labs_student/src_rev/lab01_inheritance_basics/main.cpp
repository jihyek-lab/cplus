#include <iostream>
#include <string>
using namespace std;


/*
[Lab01] 상속 기본 + 업/다운캐스팅 + protected
## 1. 상속이란?
- 상속은 기존 클래스의 멤버를 물려받아 새 클래스를 만드는 방법이다.
- 기반 클래스(base class, 부모 클래스)의 기능을 재사용하고, 파생 클래스(derived class, 자식 클래스)에서 새 기능을 추가할 수 있다.
- `public` 상속은 "기존 인터페이스를 유지한 채 확장한다"는 의미로 가장 자주 사용된다.

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
    // private가 아니라 protected로 두면, 파생 클래스는 좌표를 직접 사용할 수 있다.
    int x, y;
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
        // 강의 코멘트:
        // 여기서 x, y를 직접 읽을 수 있다는 점이 protected의 핵심이다.
        // 외부에서는 막히지만, "파생 클래스의 멤버 함수 안"에서는 허용된다.
        return (x == p.x && y == p.y && color == p.color);
    }
};

int main() {
    // (1) 상속 기본
    // 강의 코멘트:
    // ColorPoint 객체는 자기 멤버(color)도 가지고, Point 부분객체도 함께 가진다.
    ColorPoint cp;
    cp.set(3,4);           // base public
    cp.setColor("Red");    // derived
    cp.showColorPoint();

    // (2) 업캐스팅
    // 강의 코멘트:
    // 파생 객체를 기반 클래스 포인터로 보는 것은 자동으로 허용된다.
    // 대신 기반 클래스 인터페이스만 보인다.
    ColorPoint* pDer = &cp;
    Point* pBase = pDer; // 자동 업캐스팅
    pBase->showPoint();  // Base 멤버만 접근 가능

    // (3) 다운캐스팅 (주의)
    // 강의 코멘트:
    // 다운캐스팅은 문법상 가능해 보여도, 실제 객체 타입이 맞을 때만 안전하다.
    // 지금은 pBase2가 실제로 cp를 가리키므로 동작한다.
    Point* pBase2 = &cp;
    ColorPoint* pDer2 = (ColorPoint*)pBase2; // 실제 객체가 ColorPoint일 때만 안전
    pDer2->setColor("Blue");
    pDer2->showColorPoint();

    // (4) protected 접근 확인
    // 강의 코멘트:
    // 같은 파생 클래스 객체끼리는 멤버 함수 안에서 protected 멤버를 비교할 수 있다.
    ColorPoint a; a.set(3,4); a.setColor("Red");
    ColorPoint b; b.set(3,4); b.setColor("Red");
    cout << (a.equals(b) ? "true\n" : "false\n");

    // a.x = 10; // (에러) 외부에서 protected 접근 불가
    return 0;
}
