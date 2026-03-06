#include <iostream>
#include <cstring>
using namespace std;

/*
[Lab15] 깊은 복사(deep copy): 사용자 정의 복사 생성자
------------------------------------------------------------
핵심
1) 복사 생성자에서 새 메모리를 할당하고 내용을 복사해야 한다.
2) 그러면 두 객체가 서로 다른 name 메모리를 갖는다.
3) 각각의 소멸자가 자기 메모리만 delete[] 하므로 안전.
------------------------------------------------------------
*/

class Person {
    char* name;
    int id;
public:
    Person(int id, const char* n) : id(id) {
        int len = (int)strlen(n);
        name = new char[len + 1];
        strcpy(name, n);
    }

    // (핵심) 깊은 복사 복사 생성자
    Person(const Person& p) : id(p.id) {
        int len = (int)strlen(p.name);
        name = new char[len + 1];
        strcpy(name, p.name);
        cout << "[CopyCtor] " << name << "\n";
    }

    ~Person() { delete[] name; }

    void changeName(const char* n) {
        if (strlen(n) > strlen(name)) return;
        strcpy(name, n);
    }

    void show() const { cout << id << "," << name << "\n"; }
};

int main() {
    Person father(1, "Kitae");
    Person daughter(father); // 깊은 복사

    daughter.changeName("Grace");
    father.show();   // father는 그대로
    daughter.show(); // daughter만 변경

    return 0;
}
