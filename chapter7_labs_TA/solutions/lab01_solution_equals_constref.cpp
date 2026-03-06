#include <iostream>
using namespace std;

class Rect;
bool equals(const Rect& r, const Rect& s);

class Rect {
    int w,h;
public:
    Rect(int w,int h): w(w), h(h) {}
    friend bool equals(const Rect& r, const Rect& s);
};

bool equals(const Rect& r, const Rect& s){
    return r.w==s.w && r.h==s.h;
}

int main(){
    Rect a(1,2), b(1,2);
    cout << (equals(a,b)?"equal\n":"not\n");
}
