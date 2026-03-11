#include <iostream>
#include <string>
using namespace std;

/*
[Lab16 - No Empty Tokens]
------------------------------------------------------------
목표
- "7+23+5+100" 같은 문자열을 입력 받아 합을 계산한다.

전제
- 입력에 빈 토큰이 없다.
  예) "7+23+5+100" OK
      "+7+23", "7+23+", "7++23" 같은 경우는 없다.

사용 함수 요약
- find(ch, start): start 위치부터 문자 ch를 찾아 인덱스를 반환.
  찾지 못하면 string::npos(여기서는 -1로 비교).
- substr(pos, count): pos부터 count개 부분 문자열을 반환.
  count를 생략하면 pos부터 끝까지 반환.
- stoi(str): 문자열을 int로 변환.

처리 흐름
1) find로 '+' 위치를 찾는다.
2) substr로 토큰을 잘라 stoi로 더한다.
3) 더 이상 '+'가 없으면 마지막 토큰을 처리하고 종료한다.
------------------------------------------------------------
*/

int main() {
    string s;
    cout << "Enter sum expression like 7+23+5+100: ";
    getline(cin, s);

    long long sum = 0;
    int pos = 0; // 현재 토큰의 시작 위치

    while (true) {
        int plus = (int)s.find('+', pos); // 다음 '+'의 위치

        if (plus == -1) { // 더 이상 '+' 없음 -> 마지막 토큰
            string tok = s.substr(pos);
            sum += stoi(tok); // 전제상 빈 토큰 없음
            break;
        }

        string tok = s.substr(pos, plus - pos); // pos ~ plus-1
        sum += stoi(tok);
        pos = plus + 1;
    }

    cout << "sum = " << sum << "\n";
    return 0;
}
