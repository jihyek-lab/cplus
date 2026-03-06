#include "Adder.h"

/*
Adder.cpp: Adder 구현
- 생성자에서 op1/op2 초기화
- process()에서 덧셈 결과 반환
*/

Adder::Adder(int a, int b) : op1(a), op2(b) {}
int Adder::process() const { return op1 + op2; }
