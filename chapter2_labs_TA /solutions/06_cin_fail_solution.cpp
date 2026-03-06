#include <iostream>
#include <limits>

int main() {
    int x;
    while (true) {
        std::cout << "Enter an integer: ";
        std::cin >> x;

        if (!std::cin.fail()) break;

        std::cout << "Not an integer. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "You entered: " << x << "\n";
    return 0;
}
