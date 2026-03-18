#include <iostream>
#include <cstring>
using namespace std;

/*
[Lab06] 얕은 복사 vs 깊은 복사
------------------------------------------------------------
핵심
1) 포인터 멤버가 있는 객체는 디폴트 복사 시 "얕은 복사"가 된다.
2) 얕은 복사는 같은 메모리를 공유해 double delete 위험이 있다.
3) 복사 생성자를 구현해 "깊은 복사"를 해야 안전하다.
------------------------------------------------------------
*/

// 얕은 복사 문제를 보여주는 클래스
class PersonShallow {
    char* name;  // 동적 할당한 문자열 주소
    int id;
public:
    PersonShallow(int id, const char* n) : id(id) {
        int len = (int)strlen(n);
        name = new char[len + 1];
        strcpy(name, n);
    }

    // 얕은 복사일 경우 double delete 위험
    ~PersonShallow() { delete[] name; }

    void changeName(const char* n) {
        if (strlen(n) > strlen(name)) return;
        strcpy(name, n);
    }

    void show() const { cout << id << "," << name << "\n"; }

    // 복사 생성자 미구현 -> 디폴트 복사 생성자(얕은 복사)
};

// 깊은 복사로 문제를 해결하는 클래스
class PersonDeep {
    char* name;
    int id;
public:
    PersonDeep(int id, const char* n) : id(id) {
        int len = (int)strlen(n);
        name = new char[len + 1];
        strcpy(name, n);
    }

    // 복사 생성자 명시적 구현 (깊은 복사)
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
    // [A] 얕은 복사: 포인터 주소만 복사 -> 메모리 공유
    cout << "[A] shallow copy\n";
    PersonShallow father(1, "Kitae");
    PersonShallow daughter(father); // 얕은 복사
    daughter.changeName("Grace");  // father도 같이 바뀜
    father.show();
    daughter.show();
    cout << "(주의) 종료 시 double delete 위험 가능\n\n";

    // [B] 깊은 복사: 새 메모리 할당 -> 독립적
    cout << "[B] deep copy\n";
    PersonDeep father2(1, "Kitae");
    PersonDeep daughter2(father2); // 깊은 복사
    daughter2.changeName("Grace"); // father2는 유지
    father2.show();
    daughter2.show();

    return 0;
}
