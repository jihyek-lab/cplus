#include <iostream>
using namespace std;

extern "C" int f(int x, int y); // C 링크 이름 규칙
int g(int x, int y);            // C++ 링크 이름 규칙

int main() {
    cout << "f(2,5)=" << f(2,5) << "\n";
    cout << "g(2,5)=" << g(2,5) << "\n";
}
