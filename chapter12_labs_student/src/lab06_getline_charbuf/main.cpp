#include <iostream>
#include <fstream>
using namespace std;

/*
[Lab06] fin.getline(char*, n): C 스타일 라인 읽기
------------------------------------------------------------
핵심
- 한 줄씩 읽어 출력
- EOF에 도달하면 getline이 false가 되어 루프 종료
------------------------------------------------------------
*/

int main() {
    ifstream fin("./data/sample.txt");
    if(!fin) { cout << "open fail\n"; return 0; }

    char buf[81];
    while(fin.getline(buf, 81)) {
        cout << buf << "\n";
    }
    fin.close();
}
