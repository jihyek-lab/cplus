#include <iostream>
using namespace std;

/*
[Lab02] istream get(): 한 글자씩 읽기
------------------------------------------------------------
핵심
- cin.get()은 int를 리턴(EOF=-1과 비교해야 해서).
- cin.get(char&)은 읽은 문자를 참조로 채움.
- Enter('\n')를 만날 때까지 읽는 패턴을 연습한다.

관찰
- 첫 함수는 cin.get() 사용
- 두 번째는 cin.get(char&) 사용
------------------------------------------------------------
*/

void get1() {
    cout << "cin.get()로 <Enter>까지 입력 받고 출력합니다>> ";
    int ch;
    while ((ch = cin.get()) != EOF) {
        cout.put(ch);
        if (ch == '\n') break;
    }
}

void get2() {
    cout << "cin.get(char&)로 <Enter>까지 입력 받고 출력합니다>> ";
    char ch;
    while (true) {
        cin.get(ch);
        if (cin.eof()) break;
        cout.put(ch);
        if (ch == '\n') break;
    }
}

int main() {
    get1();
    get2();
}
