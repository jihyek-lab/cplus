#include <iostream>
using namespace std;

class Person {
public:
    static int sharedMoney;
    static void addShared(int n){ sharedMoney += n; }
};
int Person::sharedMoney = 0;

int main(){
    Person::addShared(10);
    Person a,b;
    a.addShared(5);
    cout << Person::sharedMoney << "\n";
}
