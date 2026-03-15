#include <iostream>
#include <cstring>
using namespace std;

/*
[Lab06] 얕은 복사 vs 깊은 복사
------------------------------------------------------------
파트 A) 얕은 복사 문제 데모
- 디폴트 복사 생성자는 포인터 값만 복사한다.
- 두 객체가 같은 메모리를 공유하면 double delete 위험.

파트 B) 깊은 복사 해결
- 복사 생성자에서 새 메모리를 할당해 내용까지 복사한다.
------------------------------------------------------------
*/

class PersonShallow {
    char* name;
    int id;
public:
    PersonShallow(int id, const char* n) : id(id) {
        int len = (int)strlen(n);
        name = new char[len + 1];
        strcpy(name, n);
    }

    ~PersonShallow() { delete[] name; }

    void changeName(const char* n) {
        if (strlen(n) > strlen(name)) return;
        strcpy(name, n);
    }

    void show() const { cout << id << "," << name << "\n"; }

    // 복사 생성자 미구현 -> 디폴트 복사 생성자(얕은 복사)
};

class PersonDeep {
    char* name;
    int id;
public:
    PersonDeep(int id, const char* n) : id(id) {
        int len = (int)strlen(n);
        name = new char[len + 1];
        strcpy(name, n);
    }

    PersonDeep(const PersonDeep& p) : id(p.id) {
        int len = (int)strlen(p.name);
        name = new char[len + 1];
        strcpy(name, p.name);
        cout << "[CopyCtor] " << name << "\n";
    }

    ~PersonDeep() { delete[] name; }

    void changeName(const char* n) {
        if (strlen(n) > strlen(name)) return;
        strcpy(name, n);
    }

    void show() const { cout << id << "," << name << "\n"; }
};

int main() {
    cout << "[A] shallow copy demo\n";
    PersonShallow father(1, "Kitae");
    PersonShallow daughter(father); // 얕은 복사
    daughter.changeName("Grace");
    father.show();
    daughter.show();
    cout << "(환경에 따라 종료 시 오류 가능)\n\n";

    cout << "[B] deep copy demo\n";
    PersonDeep father2(1, "Kitae");
    PersonDeep daughter2(father2); // 깊은 복사
    daughter2.changeName("Grace");
    father2.show();
    daughter2.show();

    return 0;
}
