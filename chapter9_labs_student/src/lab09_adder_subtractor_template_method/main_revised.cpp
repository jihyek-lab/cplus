#include <iostream>
#include <string>
using namespace std;

/*
[Lab09 Revised] Adder / Subtractor 확장
------------------------------------------------------------
핵심
- 부모가 run()으로 공통 흐름을 고정한다.
- 자식은 실제 계산 방식만 바꾼다.
- 공통 흐름: 제목 출력 -> 입력 확인 -> 계산 -> 식 출력

왜 이 버전이 좋은가?
- 원래 예제의 Adder / Subtractor 맥락을 그대로 유지한다.
- 하지만 "입력 확인"과 "출력 형식"을 부모에 모아 두어서
  템플릿 메서드 느낌이 더 분명해진다.
------------------------------------------------------------
*/

class Calculator {
protected:
    int a, b;

    bool isValid() const
    {
        // 예제에서는 음수 입력은 받지 않는다고 가정한다.
        return a >= 0 && b >= 0;
    }

    // 아래 3개는 자식 클래스마다 달라지는 부분이다.
    virtual string getTitle() const = 0;
    virtual char getSymbol() const = 0;
    virtual int calc(int a, int b) const = 0;

public:
    void setValue(int x, int y)
    {
        a = x;
        b = y;
    }

    void run() const
    {
        // run()이 전체 실행 순서를 고정한다.
        cout << "[" << getTitle() << "]\n";

        if (!isValid()) {
            cout << "invalid input\n\n";
            return;
        }

        // 실제 계산만 자식 클래스의 구현을 사용한다.
        int result = calc(a, b);
        cout << a << ' ' << getSymbol() << ' ' << b << " = " << result << "\n\n";
    }

    virtual ~Calculator() {}
};

class Adder : public Calculator {
protected:
    string getTitle() const override
    {
        return "Adder";
    }

    char getSymbol() const override
    {
        return '+';
    }

    int calc(int a, int b) const override
    {
        // 덧셈 규칙 구현
        return a + b;
    }
};

class Subtractor : public Calculator {
protected:
    string getTitle() const override
    {
        return "Subtractor";
    }

    char getSymbol() const override
    {
        return '-';
    }

    int calc(int a, int b) const override
    {
        // 뺄셈 규칙 구현
        return a - b;
    }
};

class Multiplier : public Calculator {
protected:
    string getTitle() const override
    {
        return "Multiplier";
    }

    char getSymbol() const override
    {
        return '*';
    }

    int calc(int a, int b) const override
    {
        // 곱셈 규칙 구현
        return a * b;
    }
};

int main()
{
    Adder adder;
    Subtractor subtractor;
    Multiplier multiplier;
    Calculator* p[3] = {&adder, &subtractor, &multiplier};

    // 부모 타입 포인터 배열로 자식 객체들을 한꺼번에 다룬다.
    // 같은 run()을 호출해도 실제 계산은 각 객체의 override가 사용된다.
    for (int i = 0; i < 3; i++) {
        p[i]->setValue(20, 5);
        p[i]->run();
    }

    return 0;
}
