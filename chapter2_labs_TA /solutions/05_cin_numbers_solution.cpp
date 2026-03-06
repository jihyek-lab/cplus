#include <iostream>
int main() {
    int w, h;
    std::cout << "Enter width and height: ";
    std::cin >> w >> h;
    std::cout << "Area = " << (w * h) << "\n";
    std::cout << "Perimeter = " << 2 * (w + h) << "\n";
    return 0;
}
