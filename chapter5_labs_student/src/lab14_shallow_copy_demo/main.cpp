#include <iostream>
#include <cstring>
using namespace std;

/*
[Lab14] 얕은 복사(shallow copy) 문제 데모
------------------------------------------------------------
주의: 환경에 따라 실제로 크래시(double delete)가 날 수 있습니다.
(교육용) 왜 위험한지 이해하는 것이 목표입니다.

핵심
1) 포인터 멤버(char* name)를 가진 클래스에서
   "디폴트 복사 생성자"는 포인터 값(주소)만 복사한다. => 얕은 복사
2) 그러면 두 객체가 같은 name 메모리를 공유하게 된다.
3) 소멸자에서 delete[] name을 둘 다 수행하면 double free 위험.
4) 또한 한 객체가 name 내용을 바꾸면 다른 객체도 같이 바뀐 것처럼 보일 수 있다.
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

    ~Person() {
        delete[] name; // 얕은 복사면 double delete 위험
    }

    void changeName(const char* n) {
        if (strlen(n) > strlen(name)) return;
        strcpy(name, n);
    }

    void show() const { cout << id << "," << name << "\n"; }

    // 복사 생성자 미구현 -> 디폴트 복사 생성자(얕은 복사)
};

int main() {
    Person father(1, "Kitae");
    Person daughter(father); // 얕은 복사

    daughter.changeName("Grace");
    father.show();
    daughter.show();

    // 종료 시 double delete 위험(환경에 따라 크래시)
    return 0;
}
