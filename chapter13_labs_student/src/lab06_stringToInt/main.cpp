#include <iostream>
#include <cstring>
using namespace std;

int stringToInt(const char x[]) {
    int sum = 0;
    for(int i=0; i<(int)strlen(x); i++) {
        if(x[i] >= '0' && x[i] <= '9') sum = sum*10 + (x[i]-'0');
        else throw x;
    }
    return sum;
}

int main() {
    try {
        cout << stringToInt("123") << "\n";
        cout << stringToInt("1A3") << "\n";
    } catch(const char* s) {
        cout << "예외: " << s << "\n";
    }
}
