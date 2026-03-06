#include <iostream>
using namespace std;

class Adder{ protected: int add(int a,int b){ return a+b; } };
class Subtractor{ protected: int sub(int a,int b){ return a-b; } };
class Multiplier{ protected: int mul(int a,int b){ return a*b; } };

class Calculator : public Adder, public Subtractor, public Multiplier{
public:
    int calc(char op,int a,int b){
        if(op=='+') return add(a,b);
        if(op=='-') return sub(a,b);
        if(op=='*') return mul(a,b);
        return 0;
    }
};

int main(){
    Calculator c;
    cout << c.calc('*',3,4) << "\n";
}
