#include <iostream>
int main() {
    int a = 10, b = 3;
    std::cout << "int division a/b = " << (a / b) << "\n";
    double div = static_cast<double>(a) / b;
    std::cout << "double division a/b = " << div << "\n";
    return 0;
}
