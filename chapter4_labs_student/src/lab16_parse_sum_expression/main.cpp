#include <iostream>
#include <string>
using namespace std;

/*
[Lab16] 덧셈 문자열 파싱: find + substr + stoi
------------------------------------------------------------
목표
- "7+23+5+100" 같은 문자열을 입력 받아 합을 계산한다.

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
    int startIndex = 0;

    while (true) {
        int fIndex = (int)s.find('+', startIndex);

        if (fIndex == -1) { // 더 이상 '+' 없음 -> 마지막 토큰
            string part = s.substr(startIndex);
            if (part != "") sum += stoi(part);
            break;
        }

        int count = fIndex - startIndex;
        string part = s.substr(startIndex, count);

        // "2+3+"처럼 마지막이 비어있을 수 있으니 방어
        if (part != "") sum += stoi(part);

        startIndex = fIndex + 1;
    }

    cout << "sum = " << sum << "\n";
    return 0;
}
