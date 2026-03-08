#include <iostream>
#include <fstream>
using namespace std;

/*
[Lab12] 임의 접근(Random Access): seekg/tellg
------------------------------------------------------------
준비
- lab10을 실행해서 ./data/data.dat를 만든 후 실행 추천.

구조
- int 10개(40바이트) + double(8바이트)
- 5번째 int(index 4) 위치로 이동하여 읽기
- double 위치로 이동하여 읽기

핵심
- seekg(offset, ios::beg)
- tellg()로 현재 위치 확인 가능
------------------------------------------------------------
*/

int main() {
    const char* file = "./data/data.dat";
    ifstream fin(file, ios::in | ios::binary);
    if(!fin) { cout << "open fail\n"; return 0; }

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
