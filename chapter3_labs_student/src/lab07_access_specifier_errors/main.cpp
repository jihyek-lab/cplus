#include <iostream>
using namespace std;

/*
[Lab07] 접근 지정자: private/public + private 생성자/함수
------------------------------------------------------------
이 코드로 알아야 할 것(핵심 체크)
1) private 멤버(변수/함수/생성자)는 클래스 밖에서 접근/호출 불가
2) 생성자도 private 가능: 외부에서 객체 생성을 제한할 수 있다.
3) 클래스 내부에서는 private 생성자/함수 호출이 가능하다.
   -> 이 성질로 static factory(정적 생성 함수) 패턴을 만들 수 있다.
------------------------------------------------------------
[실습 팁]
- 주석을 풀어 컴파일 에러를 확인하고, "왜" 에러인지 말로 설명해보자.
*/

class PrivateAccessError {
private:
    int a;

    void f() { a = 5; }           // private 멤버 함수

    PrivateAccessError() {        // private 생성자: 외부에서 기본 생성 불가
        a = 1; b = 1;
    }

public:
    int b;

    PrivateAccessError(int x) {   // public 생성자
        a = x; b = x;
    }

    void g() { a = 6; b = 6; }    // public 멤버 함수
};

int main() {
    // PrivateAccessError objA;     // (에러) private 생성자라 외부 생성 불가
    PrivateAccessError objB(100);  // OK

    // objB.a = 10;                 // (에러) private 멤버 변수
    objB.b = 20;                    // OK

    // objB.f();                    // (에러) private 멤버 함수
    objB.g();                        // OK

    cout << "b = " << objB.b << "\n";
    return 0;
}
