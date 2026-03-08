#include <iostream>
using namespace std;

bool getExp(int base, int exp, int& out) {
    if(base <= 0 || exp <= 0) return false;
    int value = 1;
    for(int n=0; n<exp; n++) value *= base;
    out = value;
    return true;
}

int main() {
    int v;
    if(getExp(2, 3, v)) cout << v << "\n";
    else cout << "오류\n";
}
