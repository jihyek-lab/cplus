#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() : radius(1) {}
    Circle& setRadiusChain(int r) {
        this->radius = r;
        return *this; // 자기 자신 참조 반환 -> 체이닝 가능
    }
    double getArea() const { return 3.14 * radius * radius; }
};

int main() {
    Circle c;
    c.setRadiusChain(3).setRadiusChain(4);
    cout << c.getArea() << "\n";
}
