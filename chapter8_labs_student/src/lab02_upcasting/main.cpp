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
3) 업캐스팅은 "여러 파생 객체를 하나의 기반 타입으로 묶어 다루기 위해" 필요하다.
   - 즉, 공통 기능을 기준으로 처리할 때 쓰인다.
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

///////////// 추가
void printPoint(Point* p) {
    // 공통 기능만 필요하므로 Point*로 받는다.
    p->showPoint();
}
/////////////

int main() {
    ColorPoint cp;
    ColorPoint* pDer = &cp;

    // 강의 코멘트:
    // cp는 ColorPoint 객체이므로 Point 부분도 함께 가진다.
    // 그래서 파생 클래스 포인터를 기반 클래스 포인터로 보는 것은 자동으로 허용된다.
    Point* pBase = pDer; // 자동 업캐스팅

    // 강의 코멘트:
    // 업캐스팅이 필요한 이유는 "공통 기능 기준으로 처리"하기 위해서다.
    // 예를 들어 함수가 Point* 하나만 받아도 ColorPoint를 넘길 수 있다.
    pDer->set(3,4);
    pBase->showPoint(); // OK

    // ColorPoint 고유 기능은 여전히 원래 포인터로는 사용할 수 있다.
    pDer->setColor("Red");
    pDer->showColorPoint();

    // 강의 코멘트:
    // pBase는 Point로 보고 있으므로 Point에 없는 멤버는 호출할 수 없다.
    // 즉, 객체가 줄어든 것이 아니라 "보는 인터페이스"가 부모형으로 제한된 것이다.
    // pBase->showColorPoint(); // (에러) Base에는 없음

///////////// 추가
    Point p;
    p.set(1, 2);
    printPoint(&p); // Point 객체도 printPoint로 처리 가능
    printPoint(&cp); // ColorPoint 객체도 printPoint로 처리 가능

    return 0;

}
