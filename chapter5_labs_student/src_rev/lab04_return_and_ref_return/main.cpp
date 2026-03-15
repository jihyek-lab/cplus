#include <iostream>
using namespace std;

/*
[Lab04] 객체 리턴 + 참조 리턴 응용
------------------------------------------------------------
파트 A) 객체 리턴과 대입
- c = getCircle(); 는 대입 연산자로 멤버 복사(기본은 멤버 단위 복사)
- 함수 리턴 시 복사가 생길 수 있으나 RVO/NRVO로 생략될 수 있음

파트 B) 참조 리턴
- 참조 리턴은 "값"이 아니라 "공간(변수)"을 리턴한다.
- 전역/배열 원소/자기 자신을 리턴하는 패턴을 확인한다.
------------------------------------------------------------
*/

class Circle {
    int radius;
public:
    Circle() : radius(1) {}
    Circle(int r) : radius(r) {}
    void setRadius(int r) { radius = r; }
    double getArea() const { return 3.14 * radius * radius; }

    Circle& plus(int n) { radius += n; return *this; }
    int getRadius() const { return radius; }
};

Circle getCircle() {
    Circle tmp(30);
    return tmp;
}

char g = 'a';
char& findGlobal() { return g; }

char& findAt(char s[], int index) {
    return s[index];
}

int main() {
    // (A) 객체 리턴 + 대입
    Circle c;
    cout << c.getArea() << "\n";
    c = getCircle();
    cout << c.getArea() << "\n\n";

    // (B-1) 전역 변수 참조 리턴
    char a = g;
    cout << "a=" << a << "\n";
    findGlobal() = 'b';
    cout << "g=" << g << "\n\n";

    // (B-2) 배열 원소 참조 리턴
    char name[] = "Mike";
    cout << name << "\n";
    findAt(name, 0) = 'S';
    cout << name << "\n";
    char& ref = findAt(name, 2);
    ref = 't';
    cout << name << "\n\n";

    // (B-3) 객체 자신 참조 리턴(체이닝)
    Circle aCircle(5);
    aCircle.plus(1).plus(2).plus(3);
    cout << aCircle.getRadius() << "\n";

    return 0;
}
