#include <iostream>
using namespace std;
int main() {
    int* p = new int(5);
    cout << "*p=" << *p << "\n";
    delete p;
    p = nullptr;
    if (p == nullptr) cout << "safe: p is nullptr\n";
    return 0;
}
