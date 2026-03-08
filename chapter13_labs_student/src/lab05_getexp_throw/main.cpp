#include <iostream>
using namespace std;

int getExp(int base, int exp) {
    if(base <= 0 || exp <= 0) throw "음수 사용 불가";
    int value = 1;
    for(int n=0; n<exp; n++) value *= base;
    return value;
}

int main() {
    try {
        cout << "2^3=" << getExp(2,3) << "\n";
        cout << "2^-3=" << getExp(2,-3) << "\n"; // throw
        cout << "unreachable\n";
    } catch(const char* msg) {
        cout << "예외 발생: " << msg << "\n";
    }
}
