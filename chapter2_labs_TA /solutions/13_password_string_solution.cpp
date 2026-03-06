#include <iostream>
#include <string>

int main() {
    std::string adminPw, userPw;
    std::cout << "Set admin password: ";
    std::cin >> adminPw;

    std::cout << "Enter password to check: ";
    std::cin >> userPw;

    if (userPw == adminPw) std::cout << "Access granted.\n";
    else std::cout << "Access denied.\n";
    return 0;
}
