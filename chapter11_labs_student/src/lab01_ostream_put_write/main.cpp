#include <iostream>
using namespace std;

/*
[Lab01] ostream 멤버: put / write / flush
------------------------------------------------------------
핵심
- put(char): 문자 1개 출력. int(ASCII 코드)도 가능.
- write(char*, n): 배열에서 n글자 출력(널문자 자동 출력 아님).
- flush(): 출력 버퍼를 즉시 비움(강제 출력).

관찰
- put()은 ostream&를 리턴해서 체이닝 가능.
------------------------------------------------------------
*/

int main() {
    cout.put('H');
    cout.put('i');
    cout.put(33);   // ASCII 33 == '!'
    cout.put('\n');

    cout.put('C').put('+').put('+').put(' ');
    char str[] = "I love programming";
    cout.write(str, 6); // "I love"
    cout.put('\n');

    cout << "[flush demo]" << flush;
}
