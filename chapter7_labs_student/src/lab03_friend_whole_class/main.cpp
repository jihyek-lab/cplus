#include <iostream>
using namespace std;

/*
[Lab03] 다른 클래스 전체를 friend로(강력하지만 위험)
---------------------------------------------------
핵심
- friend class RectManager; 로 RectManager의 모든 멤버 함수가
  Rect의 private 멤버에 접근 가능.

장점
- RectManager가 Rect를 조작하는 유틸리티 역할을 할 때 편함.

단점(중요)
- 캡슐화가 크게 약해진다.
- 최소 권한 원칙: 필요한 함수만 friend로 주는 것을 우선 고려.
---------------------------------------------------
*/

class Rect; // 전방 선언

class RectManager {
public:
    bool equals(Rect r, Rect s);
    void copy(Rect& dest, Rect& src);
};

class Rect {
    int width, height;
public:
    Rect(int w, int h) : width(w), height(h) {}
    friend class RectManager; // 전체 friend
};

bool RectManager::equals(Rect r, Rect s) {
    return (r.width == s.width && r.height == s.height);
}
void RectManager::copy(Rect& dest, Rect& src) {
    dest.width = src.width;
    dest.height = src.height;
}

int main() {
    Rect a(3,4), b(5,6);
    RectManager man;
    man.copy(b, a);
    cout << (man.equals(a,b) ? "equal\n" : "not equal\n");
    return 0;
}
