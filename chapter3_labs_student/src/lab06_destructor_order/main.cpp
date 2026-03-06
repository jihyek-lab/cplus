#include <iostream>
using namespace std;

/*
[Lab06] 소멸자: 호출 시점과 순서(역순 소멸)
------------------------------------------------------------
이 코드로 알아야 할 것(핵심 체크)
1) 소멸자: ~ClassName() 형태, 반환 타입/매개변수 없음, 객체가 사라질 때 자동 호출
2) 지역 객체는 블록(함수/{} 스코프)이 끝날 때 소멸한다.
3) 소멸 순서는 생성의 역순(LIFO): 나중에 생성된 객체가 먼저 소멸한다.
------------------------------------------------------------
*/

class Trace {
private:
    int id;

public:
    Trace(int i) : id(i) { cout << "[Ctor] " << id << "\n"; }
    ~Trace() { cout << "[Dtor] " << id << "\n"; }
};

void f() {
    Trace a(100);  // 먼저 생성
    Trace b(200);  // 나중에 생성
    cout << "Inside f()\n";
} // f() 종료 -> b가 먼저 소멸, 그 다음 a 소멸

int main() {
    Trace m1(1);
    Trace m2(2);
    f();
    cout << "Back to main()\n";
    return 0;
} // main 종료 -> m2 -> m1 순으로 소멸
