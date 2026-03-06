#include <iostream>
int main() {
    char name[20];
    int age;

    std::cout << "Enter name (no spaces): ";
    std::cin >> name;
    std::cout << "Enter age: ";
    std::cin >> age;

    std::cout << "Name: " << name << ", Age: " << age << "\n";
    return 0;
}
