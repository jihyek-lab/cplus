#include <iostream>
#include <string>
using namespace std;

/*
[Lab05] 복사 생성자: 언제 자동 호출되는가?
------------------------------------------------------------
핵심
1) 복사 생성자 형태: ClassName(const ClassName& other)
2) 자동 호출 대표 상황
   - Person son = father; (초기화)
   - f(father); (값 전달)
   - 함수가 객체를 리턴할 때(최적화로 생략될 수도)
------------------------------------------------------------
*/

class Person {
    string name;
public:
    Person(string n) : name(n) {}
    Person(const Person& p) : name(p.name) {
        cout << "[CopyCtor] " << name << "\n";
    }
};

void f(Person p) { (void)p; } // 값 전달 -> CopyCtor

Person g() {
    Person mother("Jane");
    return mother; // NRVO로 CopyCtor 생략 가능
}

int main() {
    Person father("Kitae");
    Person son = father; // CopyCtor
    f(father);           // CopyCtor
    g();                 // 환경에 따라 생략
    return 0;
}
