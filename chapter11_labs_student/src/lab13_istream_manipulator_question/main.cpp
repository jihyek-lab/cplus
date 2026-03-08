#include <iostream>
#include <string>
using namespace std;

/*
[Lab13] 입력 조작자(istream& (istream&))
------------------------------------------------------------
핵심
- 입력 조작자는 "입력 전에 실행되는 훅(hook)"처럼 사용 가능.
- 시그니처: istream& f(istream&)
- 사용: cin >> question >> answer;

주의
- question은 실제 입력을 읽지 않고, 단지 질문을 출력만 한다.
------------------------------------------------------------
*/

istream& question(istream& ins) {
    cout << "거울아 거울아 누가 제일 예쁘니?";
    return ins;
}

int main() {
    string answer;
    cin >> question >> answer;
    cout << "세상에서 제일 예쁜 사람은 " << answer << "입니다.\n";
}
