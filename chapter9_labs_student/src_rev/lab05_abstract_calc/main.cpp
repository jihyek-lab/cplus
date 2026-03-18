#include <iostream>
using namespace std;

/*
[Lab05] 추상 클래스 Calculator -> GoodCalc 구현
------------------------------------------------------------
문제 설명
1) 순수 가상 함수 3개를 가진 추상 클래스를 정의한다.
2) 파생 클래스가 모든 함수를 구현하면 객체 생성 가능.
------------------------------------------------------------
핵심 요약
- 추상 클래스는 포인터/참조로만 사용 가능
- 파생 클래스가 모든 순수 가상 함수를 구현해야 함
------------------------------------------------------------
주의 포인트
- size==0 방어 등 입력 검증이 필요할 수 있다.
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
