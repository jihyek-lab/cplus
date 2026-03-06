#ifndef ADDER_H
#define ADDER_H

/*
[Lab11] 미니 프로젝트: 클래스 2개 분리(Adder / Calculator)
------------------------------------------------------------
Adder.h로 알아야 할 것(핵심 체크)
1) Adder는 "계산 모듈": 입력(두 수)을 보관하고 결과를 만든다.
2) 책임 분리(SRP): 계산 로직을 UI/입출력과 분리하면 재사용/테스트가 쉬워진다.
------------------------------------------------------------
*/

class Adder {
private:
    int op1, op2;

public:
    Adder(int a, int b);
    int process() const; // 결과를 만드는 함수(여기서는 덧셈)
};

#endif // ADDER_H
