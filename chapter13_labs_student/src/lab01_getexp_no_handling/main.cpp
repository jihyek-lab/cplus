#include <iostream>
using namespace std;

int getExp(int base, int exp) {
    int value = 1;
    for(int n=0; n<exp; n++) value *= base;
    return value;
}

int main() {
    cout << "2^3 = " << getExp(2, 3) << "\n";
    cout << "2^-3 = " << getExp(2, -3) << "\n"; // 조용히 틀린 값
}
