#include <iostream>
using namespace std;

/*
[Lab11] 배열 원소 참조 리턴
------------------------------------------------------------
핵심
1) s[index]는 배열의 "원소 공간"이다.
2) char&를 리턴하면 호출자가 그 원소를 직접 수정 가능.
3) 그래서 findAt(name,0) = 'S'; 같은 코드가 된다.
------------------------------------------------------------
*/

char& findAt(char s[], int index) {
    return s[index];
}

int main() {
    char name[] = "Mike";
    cout << name << "\n";

    findAt(name, 0) = 'S';
    cout << name << "\n";

    char& ref = findAt(name, 2);
    ref = 't';
    cout << name << "\n";

    return 0;
}
