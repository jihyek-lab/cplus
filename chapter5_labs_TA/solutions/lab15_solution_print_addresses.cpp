#include <iostream>
#include <cstring>
using namespace std;

class Person {
    char* name;
    int id;
public:
    Person(int id, const char* n): id(id) {
        int len = (int)strlen(n);
        name = new char[len+1];
        strcpy(name,n);
    }
    Person(const Person& p): id(p.id) {
        int len = (int)strlen(p.name);
        name = new char[len+1];
        strcpy(name,p.name);
    }
    ~Person(){ delete[] name; }
    const char* getNamePtr() const { return name; }
};

int main() {
    Person father(1,"Kitae");
    Person daughter(father);
    cout << "father name ptr:   " << (const void*)father.getNamePtr() << "\n";
    cout << "daughter name ptr: " << (const void*)daughter.getNamePtr() << "\n";
}
