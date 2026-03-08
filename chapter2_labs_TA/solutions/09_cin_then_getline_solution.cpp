#include <iostream>
#include <string>
#include <limits>

int main() {
    int age;
    std::string name, hobby;

    std::cout << "Enter age: ";
    std::cin >> age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter name (one line): ";
    std::getline(std::cin, name);

    std::cout << "Enter hobby (one line): ";
    std::getline(std::cin, hobby);

    std::cout << "age=" << age << "\n";
    std::cout << "name=[" << name << "]\n";
    std::cout << "hobby=[" << hobby << "]\n";
    return 0;
}
