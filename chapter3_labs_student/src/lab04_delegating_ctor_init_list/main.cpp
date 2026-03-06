#include <iostream>
using namespace std;

/*
[Lab04] 위임 생성자 + 멤버 초기화 리스트
------------------------------------------------------------
이 코드로 알아야 할 것(핵심 체크)
1) 멤버 초기화 리스트: 생성자 본문 전에 멤버를 초기화한다. (문법: : x(a), y(b))
2) 위임 생성자: 한 생성자가 다른 생성자를 호출해 초기화 코드를 "한 곳"에 모을 수 있다.
   예) Point() : Point(0,0) {}
------------------------------------------------------------
*/

class Point {
private:
    int x, y;

public:
    // 위임 생성자: 기본 생성자는 (0,0) 생성자에게 위임
    Point() : Point(0, 0) {
        // 추가 작업이 있다면 여기서 수행
    }

    // 실제 초기화 담당 생성자: 초기화 리스트 사용
    Point(int a, int b) : x(a), y(b) {
        // x=a, y=b 초기화가 여기서 완료된 상태로 본문이 실행됨
    }

    void show() const { cout << "(" << x << ", " << y << ")\n"; }
};

int main() {
    Point origin;          // Point() -> Point(0,0)
    Point target(10, 20);  // Point(int,int)
    origin.show();
    target.show();

    return 0;
}
