#include <iostream>
using namespace std;

int getExp(int base, int exp) {
    if(base <= 0 || exp <= 0) return -1; // 오류 표시(-1): 충돌 가능
    int value = 1;
    for(int n=0; n<exp; n++) value *= base;
    return value;
}

int main() {
    int v = getExp(2, 3);
    cout << (v!=-1 ? v : -1) << "\n";

    int e = getExp(2, -3);
    cout << (e!=-1 ? e : -1) << "\n";
}
