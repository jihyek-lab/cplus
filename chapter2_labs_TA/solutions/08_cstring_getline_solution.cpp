#include <iostream>
int main() {
    char line[100];
    std::cout << "Enter a full sentence: ";
    std::cin.getline(line, 100);

    std::cout << "1) " << line << "\n";
    std::cout << "2) " << line << "\n";
    return 0;
}
