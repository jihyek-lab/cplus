#include <iostream>
#include <string>

int main() {
    const std::string correct = "zkrypto123";
    std::string input;

    std::cout << "Password: ";
    std::cin >> input;

    // (1) string은 == 로 내용 비교 가능 → 훨씬 직관적이고 안전
    if (input == correct) {
        std::cout << "Access granted.\n";
    } else {
        std::cout << "Access denied.\n";
    }

    return 0;
}
