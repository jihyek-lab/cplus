#include <iostream>
using namespace std;

/*
[Lab04] 추상 클래스 + 템플릿 메서드 흐름
------------------------------------------------------------
문제 설명
1) 순수 가상 함수로 추상 클래스를 만들고, 파생 클래스에서 구현한다.
2) Base가 공통 흐름(run)을 제공하고, calc만 파생에서 구현한다.
------------------------------------------------------------
핵심 요약
- 순수 가상 함수가 있으면 객체 생성 불가(추상 클래스)
- Base 포인터로 파생 객체를 다룰 수 있다(다형성)
- 공통 흐름 + 바뀌는 부분 분리(템플릿 메서드 느낌)
------------------------------------------------------------
주의 포인트
- 추상 클래스 소멸자는 virtual로 두는 것이 안전하다.
------------------------------------------------------------
*/

class Shape {
public:
    virtual void draw() = 0;
    void paint() { draw(); }
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override { cout << "Circle\n"; }
};

class Calculator {
    void input() {
        cout << "정수 2 개를 입력하세요>> ";
        cin >> a >> b;
    }
protected:
    int a, b;
    virtual int calc(int a, int b) = 0;
public:
    void run() {
        input();
        cout << "계산된 값은 " << calc(a,b) << "\n";
    }
    virtual ~Calculator() {}
};

class Adder : public Calculator {
protected:
    int calc(int a, int b) override { return a + b; }
};

class Subtractor : public Calculator {
protected:
    int calc(int a, int b) override { return a - b; }
};

int main() {
    Shape* p = new Circle();
    p->paint();
    delete p;

    Adder adder;
    Subtractor subtractor;
    adder.run();
    subtractor.run();
}
