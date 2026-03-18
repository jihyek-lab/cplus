#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
[Lab03] 텍스트 파일 연결 + 스트림 상태
------------------------------------------------------------
문제 설명
1) 두 텍스트 파일을 이어 붙인다.
2) 스트림 상태(eof/fail/bad)를 확인하는 방법을 익힌다.
------------------------------------------------------------
핵심 요약
- get/put으로 바이트 단위 복사 가능
- while(getline(fin,line)) 패턴이 가장 안전
------------------------------------------------------------
주의 포인트
- eof()는 "이미" EOF를 만난 뒤 true가 된다.
------------------------------------------------------------
*/

void concat_text() {
    const char* firstFile  = "./data/student.txt";
    const char* secondFile = "./data/sample.txt";

    fstream fout(firstFile, ios::out | ios::app);
    if(!fout) { cout << "open fail: " << firstFile << "\n"; return; }

    fstream fin(secondFile, ios::in);
    if(!fin) { cout << "open fail: " << secondFile << "\n"; return; }

    int c;
    while((c = fin.get()) != EOF) fout.put((char)c);

    fin.close();
    fout.close();
    cout << "concat 완료\n";
}

void check_state() {
    ifstream fin("./data/sample.txt");
    if(!fin) { cout << "open fail\n"; return; }

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

int main() {
    concat_text();
    check_state();
}
