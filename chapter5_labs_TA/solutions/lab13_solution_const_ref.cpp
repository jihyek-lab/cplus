#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;
public:
    Person(string n): name(n) {}
    Person(const Person& p): name(p.name) { cout << "[CopyCtor] " << name << "\n"; }
};

void f(const Person& p) { (void)p; } // 참조 전달 -> 복사 없음

int main() {
    Person father("Kitae");
    f(father); // CopyCtor 안 찍힘
}
