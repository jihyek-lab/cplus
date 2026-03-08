#include <iostream>
#include <fstream>
using namespace std;

/*
[Lab04] 텍스트 모드에서 get()로 바이트 단위 읽기 + 카운트
------------------------------------------------------------
핵심
- fin.get()은 1바이트(문자)씩 읽는다.
- 텍스트 모드에서는(특히 Windows) \\r\\n이 \\n처럼 처리될 수 있어
  원본 파일의 바이트 수와 count가 달라질 수 있다.

준비
- ./data/sample.txt 가 포함되어 있음.
------------------------------------------------------------
*/

int main() {
    const char* file = "./data/sample.txt";
    ifstream fin(file); // 텍스트 모드
    if(!fin) { cout << "open fail\n"; return 0; }

    int c, count=0;
    while((c = fin.get()) != EOF) {
        cout.put((char)c);
        count++;
    }
    cout << "\ncount=" << count << "\n";
    fin.close();
}
