#include <iostream>
using namespace std;

class Shape {
public:
    void paint(){ draw(); }
    virtual void draw(){ cout << "Shape\n"; }
    virtual ~Shape() {}
};

class Rectangle : public Shape {
public:
    void draw() override { cout << "Rectangle\n"; }
};

int main(){
    Shape* p = new Rectangle();
    p->paint(); // Rectangle
    delete p;
}
