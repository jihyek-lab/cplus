#include <iostream>
using namespace std;
int main() {
    int* p = new int(10);
    delete p;
    p = nullptr;

    if (p != nullptr) delete p; // 방어
    cout << "Done\n";
    return 0;
}
