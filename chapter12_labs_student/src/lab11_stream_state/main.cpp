#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
[Lab11] 스트림 상태 검사: eof/fail/bad
------------------------------------------------------------
핵심
- if(!fin)는 fail 상태 포함(열기 실패 등)
- eof()는 "EOF를 이미 만났는가" -> 보통 읽기 시도 후 true
- 안전한 패턴: while(getline(fin,line)) ...

실습
- sample.txt를 한 줄씩 출력
------------------------------------------------------------
*/

int main() {
    ifstream fin("./data/sample.txt");
    if(!fin) { cout << "open fail\n"; return 0; }

    string line;
    while(true) {
        if(!getline(fin, line)) {
            if(fin.eof()) cout << "EOF 도달\n";
            else cout << "읽기 실패(fail/bad)\n";
            break;
        }
        cout << line << "\n";
    }
}
