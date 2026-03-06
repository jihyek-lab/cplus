#include <iostream>
#include "Calculator.h"
#include "Adder.h"
using namespace std;

/*
Calculator.cpp
------------------------------------------------------------
이 코드로 알아야 할 것(핵심 체크)
1) Calculator::run()은 사용자 입력을 받고,
   Adder 같은 "모듈"을 호출해서 결과를 출력한다.
2) main은 Calculator를 실행만 한다(구현을 숨김).
------------------------------------------------------------
*/

void Calculator::run() {
    cout << "두 개의 수를 입력하세요>>";
    int a, b;
    cin >> a >> b;

    Adder adder(a, b);                 // 계산 모듈 사용
    cout << "result = " << adder.process() << "\n";
}
