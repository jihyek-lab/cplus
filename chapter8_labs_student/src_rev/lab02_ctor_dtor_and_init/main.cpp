#include <iostream>
#include <string>
using namespace std;

/*
[Lab02] 생성자/소멸자 순서 + 기본 생성자 문제 + 초기화 리스트
------------------------------------------------------------
문제 설명
1) 상속에서 생성/소멸 순서를 확인한다.
2) 기본 클래스에 기본 생성자가 없을 때 발생하는 문제를 이해한다.
3) 초기화 리스트로 부모 생성자를 명시적으로 호출한다.
------------------------------------------------------------
핵심 요약
- 생성: Base -> Derived, 소멸: Derived -> Base
- Base()가 없으면 파생 생성자에서 Base(...)를 명시해야 함
- 초기화 리스트는 "부모/멤버" 초기화의 표준 방식
------------------------------------------------------------
*/

class A {
public:
    A(int x) { cout << "Ctor A(int) " << x << "\n"; }
    ~A() { cout << "Dtor A\n"; }
};

class B : public A {
public:
    // Base에 기본 생성자가 없으므로 반드시 초기화 리스트 필요
    B(int x) : A(x + 3) { cout << "Ctor B(int) " << x << "\n"; }
    ~B() { cout << "Dtor B\n"; }
};

class C : public B {
public:
    C() : B(5) { cout << "Ctor C\n"; }
    ~C() { cout << "Dtor C\n"; }
};

int main() {
    C c;
    return 0;
}

/*
[에러 데모] 기본 생성자가 없는 Base를 호출한 경우
------------------------------------------------------------
아래 코드는 컴파일 에러가 나야 정상이다.
이유: Base에 A()가 없는데, B()가 암묵적으로 A()를 호출하려 하기 때문.

class A2 {
public:
    A2(int x) { cout << "Ctor A2(int) " << x << "\n"; }
};

class B2 : public A2 {
public:
    B2() { // (에러) A2()가 없음
        cout << "Ctor B2\n";
    }
};
*/
