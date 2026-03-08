#include <iostream>
using namespace std;

int main() {
    try {
        throw 3; // 바깥 예외

        try { throw "abc"; }
        catch(const char* s) { cout << "inner: " << s << "\n"; }
    }
    catch(const char* s) { cout << "outer str: " << s << "\n"; }
    catch(int x) { cout << "outer int: " << x << "\n"; }
}
