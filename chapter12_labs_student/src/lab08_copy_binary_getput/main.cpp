#include <iostream>
#include <fstream>
using namespace std;

/*
[Lab08] 바이너리 파일 복사(get/put)
------------------------------------------------------------
핵심
- ios::binary로 열어야 바이트가 그대로 복사된다.
- 텍스트 모드로 복사하면(Windows) 줄바꿈 변환으로 파일이 달라질 수 있음.

준비
- ./data/src.bin 포함
- 결과: ./data/dest.bin 생성
------------------------------------------------------------
*/

int main() {
    const char* src  = "./data/src.bin";
    const char* dest = "./data/dest.bin";

    ifstream fsrc(src, ios::in | ios::binary);
    if(!fsrc) { cout << "open fail: " << src << "\n"; return 0; }

    ofstream fdest(dest, ios::out | ios::binary);
    if(!fdest) { cout << "open fail: " << dest << "\n"; return 0; }

    int c;
    while((c = fsrc.get()) != EOF) fdest.put((char)c);

    fsrc.close();
    fdest.close();
    cout << "copy 완료\n";
}
