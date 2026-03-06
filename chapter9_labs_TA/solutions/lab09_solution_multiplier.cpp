#include <iostream>
using namespace std;

class Calculator {
    void input(){ cin >> a >> b; }
protected:
    int a,b;
    virtual int calc(int a,int b)=0;
public:
    void run(){ input(); cout << calc(a,b) << "\n"; }
    virtual ~Calculator(){}
};

class Multiplier : public Calculator {
protected:
    int calc(int a,int b) override { return a*b; }
};

int main(){
    Multiplier m;
    m.run();
}
