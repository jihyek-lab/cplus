#include <iostream>
using namespace std;

/*
[Lab10] 다중 상속: Calculator = Adder + Subtractor
------------------------------------------------------------
핵심
- class Calculator : public Adder, public Subtractor
- 두 부모의 기능을 합쳐 하나의 클래스로 제공 가능.

주의
- 다중 상속은 이름 충돌/다이아몬드 문제 등 복잡성을 만들 수 있다.
- 실무에선 "구성(composition)"이 더 안전한 경우가 많음.
------------------------------------------------------------
*/

class Adder {
protected:
    int add(int a, int b) { return a + b; }
};
class Subtractor {
protected:
    int minus(int a, int b) { return a - b; }
};

class Calculator : public Adder, public Subtractor {
public:
    int calc(char op, int a, int b) {
        switch(op) {
        case '+': return add(a,b);
        case '-': return minus(a,b);
        default:  return 0;
        }
    }
};

int main() {
    Calculator c;
    cout << "2 + 4 = " << c.calc('+',2,4) << "\n";
    cout << "100 - 8 = " << c.calc('-',100,8) << "\n";
}
