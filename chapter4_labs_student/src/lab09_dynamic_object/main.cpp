#include <iostream>
using namespace std;

/*
[Lab09] 동적 객체: new Circle(...) / delete
------------------------------------------------------------
핵심
1) new Circle(r): 힙에 객체 생성 + 생성자 실행
2) delete p: 소멸자 실행 + 메모리 반환
3) delete를 빼먹으면 메모리 누수.
------------------------------------------------------------
관찰 포인트
- 생성자/소멸자에서 메시지를 출력해 호출 시점을 확인한다.
*/

class Circle {
    int radius;
public:
    Circle() : radius(1) { cout << "[Ctor] radius=" << radius << "\n"; }
    Circle(int r) : radius(r) { cout << "[Ctor] radius=" << radius << "\n"; }
    ~Circle() { cout << "[Dtor] radius=" << radius << "\n"; }
    double getArea() const { return 3.14 * radius * radius; }
};

int main() {
    while (true) {
        cout << "radius(negative to quit) >> ";
        int r;
        cin >> r;
        if (r < 0) break;

        Circle* p = new Circle(r);  // (1) 동적 객체 생성
        cout << "area = " << p->getArea() << "\n";
        delete p;                   // (2) 반환(소멸자 호출)
    }
    return 0;
}
