#include <iostream>
using namespace std;

/*
[Lab09] 추상 클래스 + 공통 흐름 제공(run): 템플릿 메서드 느낌
------------------------------------------------------------
핵심
- Base 클래스 Calculator는 run() 전체 흐름을 제공한다:
  input() -> calc(a,b) -> 출력
- 파생 클래스는 calc()만 구현한다(Adder/Subtractor).
- 이렇게 하면 "공통 흐름"과 "바뀌는 부분"을 분리할 수 있다.

주의
- calc는 protected로 두면 외부에서 직접 호출 못하게 막을 수 있다(설계).

이론 연결
- 이 구조는 템플릿 메서드 패턴과 비슷하다.
- 바뀌지 않는 절차(run)는 부모가 고정하고, 바뀌는 계산(calc)은 자식이 맡는다.
- 이렇게 하면 중복 코드가 줄고, 새 연산 클래스를 추가하기도 쉬워진다.
------------------------------------------------------------
*/

class Calculator {
    void input() {
        cout << "정수 2 개를 입력하세요>> ";
        cin >> a >> b;
    }
protected:
    int a, b;
    // 세부 계산은 파생 클래스가 결정한다.
    virtual int calc(int a, int b) = 0;
public:
    void run() {
        // run()이 전체 흐름을 고정한다.
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
    Adder adder;
    Subtractor subtractor;
    adder.run();
    subtractor.run();
}
