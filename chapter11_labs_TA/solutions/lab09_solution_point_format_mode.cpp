#include <iostream>
using namespace std;

static bool g_verbose = false;

struct verbose_t{}; // 조작자 타입
verbose_t verbose;

ostream& operator<<(ostream& os, verbose_t){
    g_verbose = true;
    return os;
}

class Point{
    int x,y;
public:
    Point(int x=0,int y=0):x(x),y(y){}
    friend ostream& operator<<(ostream& os, const Point& p){
        if(g_verbose) os << "x=" << p.x << ",y=" << p.y;
        else os << "(" << p.x << "," << p.y << ")";
        return os;
    }
};

int main(){
    Point p(3,4);
    cout << p << "\n";
    cout << verbose << p << "\n";
}
