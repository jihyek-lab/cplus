#include <iostream>
#include <string>
using namespace std;

/*
[Lab14] 문자열 파싱 + find/replace
------------------------------------------------------------
문제 설명
1) 덧셈 문자열(예: "7+23+5+100")을 입력받아 합을 계산한다.
2) '&'가 나올 때까지 여러 줄 텍스트를 입력받고,
   찾을 문자열을 다른 문자열로 모두 치환하여 출력한다.
------------------------------------------------------------
파트 A) 덧셈 문자열 파싱
- find + substr + stoi로 "7+23+5" 같은 문자열의 합 계산
- getline(cin >> ws, s): 앞 공백/개행 제거 후 한 줄 입력

파트 B) find/replace (멀티라인)
- '&'가 나올 때까지 입력받고, 특정 문자열을 찾아 치환
------------------------------------------------------------
새로 나오는 함수 요약
- find(ch/str, start): start부터 문자/문자열 검색, 없으면 npos
- substr(pos): pos부터 끝까지 반환
- substr(pos, len): pos부터 len만큼 반환
- replace(pos, len, repl): pos부터 len만큼을 repl로 치환
- empty(): 비어있는지 확인
- getline(cin >> ws, s[, delim]): 앞 공백 제거 후 한 줄 입력
------------------------------------------------------------
*/

int main() {
    // (A) 덧셈 문자열 파싱
    cout << "Enter sum expression like 7+23+5+100: ";
    string expr;
    // getline: 공백 포함 한 줄 전체를 읽음
    getline(cin >> ws, expr);

    bool ignoreEmptyTokens = true; // 빈 토큰("2+3+", "2++3") 무시 여부
    long long sum = 0;
    size_t pos = 0;

    while (true) {
        // find(ch, start): start 위치부터 문자를 찾아 인덱스 반환, 없으면 npos
        size_t plus = expr.find('+', pos);
        if (plus == string::npos) {
            // substr(pos): pos부터 끝까지
            string part = expr.substr(pos);
            if (ignoreEmptyTokens) {
                if (!part.empty()) sum += stoi(part);
            } else {
                sum += stoi(part);
            }
            break;
        }

        // substr(pos, len): pos부터 len만큼
        string part = expr.substr(pos, plus - pos);
        if (ignoreEmptyTokens) {
            if (!part.empty()) sum += stoi(part);
        } else {
            sum += stoi(part);
        }
        pos = plus + 1;
    }

    cout << "sum = " << sum << "\n\n";

    // (B) find/replace (멀티라인)
    cout << "Enter multi-line text. End with '&' character.\n";
    string text;
    // getline(delim): delim 문자가 나올 때까지 읽음(멀티라인 가능)
    getline(cin >> ws, text, '&');

    cout << "Find: ";
    string from;
    getline(cin >> ws, from);

    cout << "Replace: ";
    string to;
    getline(cin >> ws, to);

    // empty(): 문자열이 비어있으면 true
    if (from.empty()) {
        cout << "\n--- result ---\n";
        cout << text << "\n";
        return 0;
    }

    size_t idx = 0;
    while (true) {
        // find(str, start): start 위치부터 문자열 str을 찾아 인덱스 반환
        idx = text.find(from, idx);
        if (idx == string::npos) break;
        // replace(pos, len, repl): pos부터 len만큼을 repl로 치환
        text.replace(idx, from.size(), to);
        idx += to.size(); // 무한 루프 방지
    }

    cout << "\n--- result ---\n";
    cout << text << "\n";
    return 0;
}
