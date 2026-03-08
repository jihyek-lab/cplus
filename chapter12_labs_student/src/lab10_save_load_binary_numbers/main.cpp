#include <iostream>
#include <fstream>
using namespace std;

/*
[Lab10] 바이너리로 숫자 저장/복원(write/read)
------------------------------------------------------------
핵심
- int 배열 10개 + double 1개를 그대로 저장
- 읽어와서 값이 복원되는지 확인

주의
- 바이너리는 엔디안/타입 크기/패딩에 영향 -> 다른 환경 호환 이슈 가능
------------------------------------------------------------
*/

int main() {
    const char* file = "./data/data.dat";
    int n[10] = {0,1,2,3,4,5,6,7,8,9};
    double d = 3.15;

    ofstream fout(file, ios::out | ios::binary);
    if(!fout) { cout << "open fail\n"; return 0; }
    fout.write((char*)n, sizeof(n));
    fout.write((char*)(&d), sizeof(d));
    fout.close();

    for(int i=0;i<10;i++) n[i]=99;
    d = 8.15;

    ifstream fin(file, ios::in | ios::binary);
    if(!fin) { cout << "open fail\n"; return 0; }
    fin.read((char*)n, sizeof(n));
    fin.read((char*)(&d), sizeof(d));
    fin.close();

    for(int i=0;i<10;i++) cout << n[i] << ' ';
    cout << "\n" << d << "\n";
}
