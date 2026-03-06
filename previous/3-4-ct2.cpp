class Circle {
    int radius;
public:
    double getArea();
    Circle();
    Circle(int r);
    void Circle( short r); //
};
int main() {
    Circle waffle; // 2
    Circle pizza(30); //
    double d = pizza.getArea(); // @
}