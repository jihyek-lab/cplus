#include <iostream>
#include <string>
using namespace std;

/*
[Lab14] string 배열 + getline + 사전순 비교
------------------------------------------------------------
핵심
1) getline(cin, s): 공백 포함 한 줄 입력
2) string은 <, > 비교가 가능하며 사전순(lexicographical) 비교를 한다.
3) 가장 "뒤"에 오는 문자열(latter)을 찾는 루프 패턴 익히기
------------------------------------------------------------
주의
- 바로 전에 cin >> 를 했다면 버퍼에 \n이 남아 getline이 빈 줄을 읽을 수 있음(2장 내용).
- 이 실습은 getline만 쓰므로 바로 실행하면 OK.
*/

int main() {
    string names[5];

    for (int i = 0; i < 5; i++) {
        cout << "name >> ";
        getline(cin, names[i]);
    }

    string latter = names[0];
    for (int i = 1; i < 5; i++) {
        if (latter < names[i]) latter = names[i];
    }

    cout << "Lexicographically last = " << latter << "\n";
    return 0;
}
