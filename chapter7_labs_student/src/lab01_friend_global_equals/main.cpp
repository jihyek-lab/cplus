#include <iostream>
using namespace std;

/*
[Lab01] friend 함수(외부 함수)로 private 접근 허용
---------------------------------------------------
핵심
- friend 함수는 클래스 멤버가 아닌 "외부 함수"인데,
  private 멤버에 접근할 수 있도록 특별 권한을 받는다.
- 외부 함수가 클래스 타입을 쓰면, 클래스 정의 전에
  전방 선언(class Rect;)이 필요할 수 있다.

여기서 확인할 것
- equals()는 Rect의 멤버 함수가 아니다.
- 그런데 Rect::width/height에 접근 가능하다(friend 덕분).
---------------------------------------------------
*/

class Rect;                  // (1) 전방 선언
bool equals(Rect r, Rect s); // (2) 외부 함수 원형

class Rect {
    int width, height;       // private(디폴트)
public:
    Rect(int w, int h) : width(w), height(h) {}
    friend bool equals(Rect r, Rect s); // (3) friend 선언
};

bool equals(Rect r, Rect s) {
    return (r.width == s.width && r.height == s.height);
}

int main() {
    Rect a(3,4), b(4,5);
    cout << (equals(a,b) ? "equal\n" : "not equal\n");
    return 0;
}
