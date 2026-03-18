#include <iostream>
using namespace std;

/*
[Lab01] friend 적용 방식 비교
------------------------------------------------------------
문제 설명
1) Rect의 private 멤버에 접근하는 friend 방식 3가지를 비교한다.
2) 외부 함수 friend / 특정 멤버 friend / 클래스 전체 friend의 차이를 관찰한다.
------------------------------------------------------------
핵심 요약
- friend는 private 접근 권한을 외부에 부여한다.
- 멤버 함수 friend는 "그 함수만" 접근 가능하다.
- 클래스 friend는 "모든 멤버"가 접근 가능하다.
------------------------------------------------------------
주의/포인트
- 최소 권한 원칙: 꼭 필요한 함수만 friend로 지정하는 것이 안전하다.
------------------------------------------------------------
*/

class Rect;                  // 전방 선언
bool equals(Rect r, Rect s); // 외부 함수 원형

class RectManager {
public:
    bool equals(Rect r, Rect s);
    void copy(Rect& dest, Rect& src);
};

class Rect {
    int width, height;
public:
    Rect(int w, int h) : width(w), height(h) {}

    // (1) 외부 함수 friend
    friend bool ::equals(Rect r, Rect s);

    // (2) 다른 클래스의 특정 멤버 함수 friend
    friend bool RectManager::equals(Rect r, Rect s);

    // (3) 다른 클래스 전체 friend
    friend class RectManager;
};

bool equals(Rect r, Rect s) {
    // 외부 함수지만 friend라서 private 접근 가능
    return (r.width == s.width && r.height == s.height);
}

bool RectManager::equals(Rect r, Rect s) {
    // 특정 멤버만 friend로 지정된 경우
    return (r.width == s.width && r.height == s.height);
}

void RectManager::copy(Rect& dest, Rect& src) {
    // 클래스 전체가 friend면 모든 멤버 접근 가능
    dest.width = src.width;
    dest.height = src.height;
}

int main() {
    Rect a(3,4), b(4,5), c(3,4);
    RectManager man;

    cout << (equals(a,b) ? "equal\n" : "not equal\n");
    cout << (man.equals(a,c) ? "equal\n" : "not equal\n");

    man.copy(b, a);
    cout << (man.equals(a,b) ? "equal\n" : "not equal\n");
    return 0;
}
