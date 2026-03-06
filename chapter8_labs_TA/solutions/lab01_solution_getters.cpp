#include <iostream>
#include <string>
using namespace std;

class Point {
    int x,y;
public:
    void set(int x,int y){ this->x=x; this->y=y; }
    int getX() const { return x; }
    int getY() const { return y; }
};

class ColorPoint : public Point {
    string color;
public:
    void setColor(string c){ color=c; }
    void show() const { cout << color << ":(" << getX() << "," << getY() << ")\n"; }
};

int main(){
    ColorPoint cp; cp.set(3,4); cp.setColor("Red"); cp.show();
}
