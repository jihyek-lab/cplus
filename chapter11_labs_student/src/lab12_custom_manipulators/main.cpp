#include <iostream>
using namespace std;

/*
[Lab12] 사용자 정의 조작자(ostream& (ostream&))
------------------------------------------------------------
핵심
- 조작자는 함수이며, cout << manipulator 형태로 사용.
- 시그니처: ostream& f(ostream&)

예)
- beep: '\a' 출력(터미널/OS에 따라 소리 안 날 수 있음)
------------------------------------------------------------
*/

ostream& fivestar(ostream& outs) { return outs << "*****"; }
ostream& rightarrow(ostream& outs) { return outs << "---->"; }
ostream& beep(ostream& outs) { return outs << '\a'; }

int main() {
    cout << "벨이 울립니다" << beep << endl;
    cout << "C" << rightarrow << "C++" << rightarrow << "Java" << endl;
    cout << "Visual" << fivestar << "C++" << endl;
}
