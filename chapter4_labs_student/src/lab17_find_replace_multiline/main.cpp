#include <iostream>
#include <string>
using namespace std;

/*
[Lab17] find/replace: 여러 줄 입력(& 종료) + 부분 문자열 치환
------------------------------------------------------------
목표
- &가 나올 때까지 여러 줄 텍스트를 입력받고,
  특정 문자열 f를 찾아 r로 바꾼 결과를 출력한다.

핵심
1) getline(cin, s, '&'): '&'가 나올 때까지 입력(여러 줄 가능)
2) cin.ignore(): '&' 뒤 남아있을 수 있는 개행 제거 (환경에 따라 필요)
3) find(pattern, start)로 검색
4) replace(pos, len, repl)로 치환
5) startIndex를 fIndex + r.length()로 이동해 무한 루프 방지
------------------------------------------------------------
*/

int main() {
    string s;
    cout << "Enter multi-line text. End with '&' character.\n";
    getline(cin, s, '&');
    cin.ignore(); // & 뒤의 엔터 제거(입력 환경에 따라 유용)

    string f, r;
    cout << "find: ";
    getline(cin, f);
    cout << "replace: ";
    getline(cin, r);

    int startIndex = 0;
    while (true) {
        int fIndex = (int)s.find(f, startIndex);
        if (fIndex == -1) break;

        s.replace(fIndex, (int)f.length(), r);
        startIndex = fIndex + (int)r.length();
    }

    cout << "\n--- result ---\n";
    cout << s << "\n";
    return 0;
}
