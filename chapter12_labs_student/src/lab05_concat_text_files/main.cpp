#include <iostream>
#include <fstream>
using namespace std;

/*
[Lab05] 텍스트 파일 연결(append)
------------------------------------------------------------
목표
- student.txt 끝에 sample.txt 내용을 붙인다.

핵심
- 출력 파일: ios::out | ios::app
- 입력 파일: ios::in
- get/put으로 1바이트씩 복사
------------------------------------------------------------
*/

int main() {
    const char* firstFile  = "./data/student.txt";
    const char* secondFile = "./data/sample.txt";

    fstream fout(firstFile, ios::out | ios::app);
    if(!fout) { cout << "open fail: " << firstFile << "\n"; return 0; }

    fstream fin(secondFile, ios::in);
    if(!fin) { cout << "open fail: " << secondFile << "\n"; return 0; }

    int c;
    while((c = fin.get()) != EOF) fout.put((char)c);

    fin.close();
    fout.close();
    cout << "concat 완료\n";
}
