#include <iostream>
using namespace std;

class Power{
    int k,p;
public:
    Power(int k=0,int p=0):k(k),p(p){}
    bool operator==(const Power& o) const { return k==o.k && p==o.p; }
    bool operator!=(const Power& o) const { return !(*this==o); }
};

int main(){
    Power a(1,2), b(2,1);
    cout << (a!=b ? "diff\n":"same\n");
}
