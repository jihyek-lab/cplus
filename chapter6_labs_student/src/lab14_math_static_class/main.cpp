#include <iostream>
using namespace std;

/*
[Lab14] static 함수로 전역 함수 캡슐화(Math 클래스)
-----------------------------------------
문제
- abs, max, min 같은 전역 함수가 많아지면 이름 충돌/관리 어려움.

해결
- Math라는 클래스로 묶고, 객체 없이 쓸 수 있게 static으로 선언한다.
- 사용: Math::abs(-5)

핵심
- "관련 기능 묶기" + "전역 오염 감소"
-----------------------------------------
*/

class Math {
public:
    static int abs(int a) { return (a > 0) ? a : -a; }
    static int max(int a, int b) { return (a > b) ? a : b; }
    static int min(int a, int b) { return (a > b) ? b : a; }
};

int main() {
    cout << Math::abs(-5) << "\n";
    cout << Math::max(10, 8) << "\n";
    cout << Math::min(-3, -8) << "\n";
    return 0;
}
