#include <iostream>
using namespace std;

class Power{
    int k,p;
public:
    Power(int k=0,int p=0):k(k),p(p){}
    void show() const { cout << k << "," << p << "\n"; }
    friend Power& operator--(Power& op);
    friend Power operator--(Power& op,int);
};

Power& operator--(Power& op){
    op.k--; op.p--;
    return op;
}
Power operator--(Power& op,int){
    Power tmp = op;
    op.k--; op.p--;
    return tmp;
}

int main(){
    Power a(3,5), b;
    b = --a; a.show(); b.show();
    b = a--; a.show(); b.show();
}
