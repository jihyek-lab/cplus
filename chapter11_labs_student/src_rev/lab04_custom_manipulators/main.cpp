#include <iostream>
#include <string>
using namespace std;

/*
[Lab04] 사용자 정의 조작자(ostream/istream)
------------------------------------------------------------
문제 설명
1) ostream 조작자를 만들어 cout << manip 형태로 사용한다.
2) istream 조작자를 만들어 cin >> manip >> value 형태로 사용한다.
------------------------------------------------------------
핵심 요약
- 조작자는 함수이며, ostream& / istream& 를 반환한다.
- 조작자는 "입출력 흐름에 끼어드는 훅"처럼 동작한다.
------------------------------------------------------------
주의 포인트
- 입력 조작자는 실제 입력을 읽지 않을 수 있으므로 오해 주의.
------------------------------------------------------------
*/

ostream& fivestar(ostream& outs) { return outs << "*****"; }
ostream& rightarrow(ostream& outs) { return outs << "---->"; }
ostream& beep(ostream& outs) { return outs << '\a'; }

istream& question(istream& ins) {
    cout << "거울아 거울아 누가 제일 예쁘니?";
    return ins;
}

int main() {
    cout << "벨이 울립니다" << beep << endl;
    cout << "C" << rightarrow << "C++" << rightarrow << "Java" << endl;
    cout << "Visual" << fivestar << "C++" << endl;

    string answer;
    cin >> question >> answer;
    cout << "세상에서 제일 예쁜 사람은 " << answer << "입니다.\n";
}
