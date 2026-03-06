#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int r): radius(r) {}
    int getRadius() const { return radius; }
    void setRadius(int r){ radius=r; }
};

void increase(Circle* p) {
    if (p == nullptr) return;
    p->setRadius(p->getRadius() + 1);
}

int main() {
    Circle c(30);
    increase(&c);
    cout << c.getRadius() << "\n";
    increase(nullptr); // 안전
}
