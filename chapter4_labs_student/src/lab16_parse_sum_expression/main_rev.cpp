#include <iostream>
#include <string>
using namespace std;

/*
[Lab16] 덧셈 문자열 파싱: find + substr + stoi
------------------------------------------------------------
목표
- "7+23+5+100" 같은 문자열을 입력 받아 합을 계산한다.

사용 함수 요약
- find(ch, start): start 위치부터 문자 ch를 찾아 인덱스를 반환.
  찾지 못하면 string::npos(여기서는 -1로 비교).
- substr(pos, count): pos부터 count개 부분 문자열을 반환.
  count를 생략하면 pos부터 끝까지 반환.
- stoi(str): 문자열을 int로 변환.
- empty(): 문자열이 비어 있으면 true 반환.

처리하는 입력 케이스
- 일반 케이스: "7+23+5+100" -> 각 토큰을 더함.
- 마지막 토큰: 마지막 '+'가 없을 때 남은 부분을 합산하고 종료.
- 빈 토큰: "2+3+" 처럼 마지막이 비어있는 경우는 건너뜀.
  "+2+3"처럼 앞이 비어있는 경우도 같은 방식으로 무시됨.

핵심
1) find('+', startIndex)로 다음 '+' 위치를 찾는다.
2) substr(startIndex, count)로 토큰을 잘라낸다.
3) stoi로 숫자로 바꿔 sum에 더한다.
4) 더 이상 '+'가 없으면 마지막 토큰을 처리하고 종료한다.
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
            if (!tok.empty()) sum += stoi(tok); // 마지막 토큰 합산
            break;
        }

        string tok = s.substr(pos, plus - pos); // pos ~ plus-1
        // "2+3+"처럼 마지막이 비어있을 수 있으니 방어
        if (!tok.empty()) sum += stoi(tok);
        pos = plus + 1;
    }

    cout << "sum = " << sum << "\n";
    return 0;
}
