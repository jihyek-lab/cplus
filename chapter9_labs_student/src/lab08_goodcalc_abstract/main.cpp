#include <iostream>
using namespace std;

/*
[Lab08] 추상 클래스 Calculator -> GoodCalc 구현
------------------------------------------------------------
핵심
- 순수 가상 함수 3개를 가진 Calculator는 추상 클래스.
- GoodCalc가 3개를 모두 구현하면 객체 생성 가능.
- 포인터 타입은 Calculator*로 두고, 실제 객체는 GoodCalc로 만들면
  다형성(polymorphism)을 활용할 수 있다.

주의
- average는 size==0 방어 필요(미니과제에서 추가).
------------------------------------------------------------
*/

class Calculator {
public:
    virtual int add(int a, int b) = 0;
    virtual int subtract(int a, int b) = 0;
    virtual double average(int a[], int size) = 0;
    virtual ~Calculator() {}
};

class GoodCalc : public Calculator {
public:
    int add(int a, int b) override { return a + b; }
    int subtract(int a, int b) override { return a - b; }
    double average(int a[], int size) override {
        double sum = 0;
        for (int i = 0; i < size; i++) sum += a[i];
        return sum / size;
    }
};

int main() {
    int a[] = {1,2,3,4,5};
    Calculator* p = new GoodCalc();
    cout << p->add(2,3) << "\n";
    cout << p->subtract(2,3) << "\n";
    cout << p->average(a,5) << "\n";
    delete p;
}
