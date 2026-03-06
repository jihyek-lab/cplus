#include <iostream>
using namespace std;

/*
[Lab11] 디폴트 매개변수로 "생성자 중복 간소화"
-----------------------------------------
상황
- MyVector() 와 MyVector(int) 두 생성자를 만들 수도 있다.

핵심
- MyVector(int n = 100) 하나만 두면 두 경우를 모두 커버 가능.
- 동적 배열을 쓰면 소멸자에서 delete[] 필수.

주의
- 복사 생성자/대입 연산자까지 고려하면(5장) Rule of 3 문제가 생길 수 있다.
  (이번 장에서는 '디폴트 생성자 간소화'가 목표)
-----------------------------------------
*/

class MyVector {
    int* p;
    int size;
public:
    MyVector(int n = 100) {
        p = new int[n];
        size = n;
    }
    ~MyVector() { delete[] p; }
    int getSize() const { return size; }
};

int main() {
    MyVector* v1 = new MyVector();     // 100
    MyVector* v2 = new MyVector(1024); // 1024
    cout << v1->getSize() << "\n";
    cout << v2->getSize() << "\n";
    delete v1;
    delete v2;
    return 0;
}
