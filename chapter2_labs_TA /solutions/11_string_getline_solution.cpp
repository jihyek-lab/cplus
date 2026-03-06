#include <iostream>
#include <string>

int main() {
    std::string singer, song;
    std::cout << "Enter favorite singer: ";
    std::getline(std::cin, singer);
    std::cout << "Enter favorite song: ";
    std::getline(std::cin, song);

    std::cout << "Singer: [" << singer << "]\n";
    std::cout << "Song:   [" << song << "]\n";
    return 0;
}
