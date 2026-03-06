#include <iostream>
using namespace std;

/*
[Lab02] 다른 클래스의 "특정 멤버 함수"만 friend로
---------------------------------------------------
핵심
- RectManager 클래스의 equals() 멤버 함수만 Rect의 friend로 초대한다.
- 문법: friend bool RectManager::equals(Rect, Rect);

주의
- RectManager를 먼저 정의해야 RectManager::equals를 friend로 지정 가능.
- Rect 타입이 필요하므로 class Rect; 전방 선언이 필요하다.
---------------------------------------------------
*/

class Rect; // 전방 선언

class RectManager {
public:
    bool equals(Rect r, Rect s);
};

class Rect {
    int width, height;
public:
    Rect(int w, int h) : width(w), height(h) {}
    friend bool RectManager::equals(Rect r, Rect s);
};

bool RectManager::equals(Rect r, Rect s) {
    return (r.width == s.width && r.height == s.height);
}

int main() {
    Rect a(3,4), b(3,4);
    RectManager man;
    cout << (man.equals(a,b) ? "equal\n" : "not equal\n");
    return 0;
}
