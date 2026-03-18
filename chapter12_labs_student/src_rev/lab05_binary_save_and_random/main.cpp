#include <iostream>
#include <fstream>
using namespace std;

/*
[Lab05] 바이너리 저장/복원 + 임의 접근
------------------------------------------------------------
문제 설명
1) int 배열과 double 값을 바이너리로 저장/복원한다.
2) seekg/tellg로 원하는 위치를 읽는다.
------------------------------------------------------------
핵심 요약
- write/read는 "그대로" 저장/복원된다.
- seekg는 읽기 위치, tellg는 현재 위치를 알려준다.
------------------------------------------------------------
주의 포인트
- 바이너리는 엔디안/타입 크기/패딩에 영향받을 수 있다.
------------------------------------------------------------
*/

void save_load() {
    const char* file = "./data/data.dat";
    int n[10] = {0,1,2,3,4,5,6,7,8,9};
    double d = 3.15;

    ofstream fout(file, ios::out | ios::binary);
    if(!fout) { cout << "open fail\n"; return; }
    fout.write((char*)n, sizeof(n));
    fout.write((char*)(&d), sizeof(d));
    fout.close();

    for(int i=0;i<10;i++) n[i]=99;
    d = 8.15;

    ifstream fin(file, ios::in | ios::binary);
    if(!fin) { cout << "open fail\n"; return; }
    fin.read((char*)n, sizeof(n));
    fin.read((char*)(&d), sizeof(d));
    fin.close();

    for(int i=0;i<10;i++) cout << n[i] << ' ';
    cout << "\n" << d << "\n";
}

void random_access() {
    const char* file = "./data/data.dat";
    ifstream fin(file, ios::in | ios::binary);
    if(!fin) { cout << "open fail\n"; return; }

    fin.seekg(4 * (int)sizeof(int), ios::beg);
    cout << "pos(after seek int) = " << fin.tellg() << "\n";
    int x;
    fin.read((char*)&x, sizeof(x));
    cout << "5번째 int = " << x << "\n";

    fin.seekg(10 * (int)sizeof(int), ios::beg);
    cout << "pos(after seek double) = " << fin.tellg() << "\n";
    double d;
    fin.read((char*)&d, sizeof(d));
    cout << "double = " << d << "\n";

    fin.close();
}

int main() {
    save_load();
    random_access();
}
