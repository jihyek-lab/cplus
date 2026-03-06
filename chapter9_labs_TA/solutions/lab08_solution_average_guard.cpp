#include <iostream>
using namespace std;

class Calculator {
public:
    virtual int add(int,int)=0;
    virtual int subtract(int,int)=0;
    virtual double average(int a[], int size)=0;
    virtual ~Calculator(){}
};

class GoodCalc : public Calculator {
public:
    int add(int a,int b) override { return a+b; }
    int subtract(int a,int b) override { return a-b; }
    double average(int a[], int size) override {
        if(size<=0) return 0.0;
        double s=0;
        for(int i=0;i<size;i++) s+=a[i];
        return s/size;
    }
};

int main(){
    int a[]={1,2,3};
    Calculator* p=new GoodCalc();
    cout << p->average(a,0) << "\n";
    delete p;
}
