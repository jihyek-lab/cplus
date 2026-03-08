#include <iostream>
#include <fstream>
using namespace std;

/*
[Lab09] 바이너리 파일 복사(read/write 블록)
------------------------------------------------------------
핵심
- read(buf,N)로 최대 N바이트 읽기
- 실제 읽은 바이트는 gcount()로 확인
- n>0이면 write(buf,n)

주의
- eof()를 while 조건으로 바로 쓰면 마지막 블록 처리에서 실수하기 쉬움.
------------------------------------------------------------
*/

int main() {
    const char* src  = "./data/src.bin";
    const char* dest = "./data/dest_readwrite.bin";

    ifstream fsrc(src, ios::in | ios::binary);
    if(!fsrc) { cout << "open fail\n"; return 0; }

    ofstream fdest(dest, ios::out | ios::binary);
    if(!fdest) { cout << "open fail\n"; return 0; }

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
