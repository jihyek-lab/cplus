#include <iostream>
#include <fstream>
using namespace std;

/*
[Lab04] 바이너리 파일 복사 (get/put vs read/write)
------------------------------------------------------------
문제 설명
1) 바이너리 파일을 1바이트씩 복사한다.
2) read/write 블록 복사와 비교한다.
------------------------------------------------------------
핵심 요약
- ios::binary로 열어야 바이트가 그대로 복사된다.
- read() 후 gcount()로 실제 읽은 크기를 확인한다.
------------------------------------------------------------
주의 포인트
- 텍스트 모드로 복사하면 줄바꿈 변환으로 파일이 달라질 수 있다.
------------------------------------------------------------
*/

void copy_getput() {
    const char* src  = "./data/src.bin";
    const char* dest = "./data/dest.bin";

    ifstream fsrc(src, ios::in | ios::binary);
    if(!fsrc) { cout << "open fail: " << src << "\n"; return; }

    ofstream fdest(dest, ios::out | ios::binary);
    if(!fdest) { cout << "open fail: " << dest << "\n"; return; }

    int c;
    while((c = fsrc.get()) != EOF) fdest.put((char)c);

    fsrc.close();
    fdest.close();
    cout << "copy(get/put) 완료\n";
}

void copy_readwrite() {
    const char* src  = "./data/src.bin";
    const char* dest = "./data/dest_readwrite.bin";

    ifstream fsrc(src, ios::in | ios::binary);
    if(!fsrc) { cout << "open fail\n"; return; }

    ofstream fdest(dest, ios::out | ios::binary);
    if(!fdest) { cout << "open fail\n"; return; }

    char buf[1024];
    while(true) {
        fsrc.read(buf, sizeof(buf));
        streamsize n = fsrc.gcount();
        if(n <= 0) break;
        fdest.write(buf, n);
    }

    fsrc.close();
    fdest.close();
    cout << "copy(read/write) 완료\n";
}

int main() {
    copy_getput();
    copy_readwrite();
}
