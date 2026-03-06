#include <iostream>
namespace kitae { void print(){ std::cout << "kitae::print()\n"; } }
namespace bob   { void print(){ std::cout << "bob::print()\n"; } }
namespace alice { void print(){ std::cout << "alice::print()\n"; } }

int main() {
    kitae::print();
    bob::print();
    alice::print();
    return 0;
}
