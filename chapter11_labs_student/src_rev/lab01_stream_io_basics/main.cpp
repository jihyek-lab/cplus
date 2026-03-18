#include <iostream>
#include <cstring>
using namespace std;

/*
[Lab01] ostream/istream 기본 + get/line/ignore/gcount
------------------------------------------------------------
문제 설명
1) put/write/flush로 출력 스트림 기본을 연습한다.
2) cin.get(), cin.get(char&), cin.getline() 차이를 비교한다.
3) ignore와 gcount로 입력 버퍼를 제어한다.
------------------------------------------------------------
핵심 요약
- put(char): 문자 1개 출력, write(buf,n): n글자 출력, flush(): 버퍼 비움
- get()은 '\n'을 버퍼에 남기고, getline()은 '\n'을 제거한다.
- ignore는 버퍼를 비우고, gcount는 직전 읽은 문자 수를 알려준다.
------------------------------------------------------------
주의 포인트
- get(char*, n)은 '\n'을 남기므로 필요시 ignore로 제거해야 한다.
- gcount는 \"직전\" 입력 함수에만 의미가 있다.
------------------------------------------------------------
*/

void demo_output() {
    cout.put('H');
    cout.put('i');
    cout.put(33);
    cout.put('\n');

    char str[] = "I love programming";
    cout.put('C').put('+').put('+').put(' ');
    cout.write(str, 6);
    cout.put('\n');

    cout << "[flush demo]" << flush << "\n";
}

void demo_get() {
    cout << "cin.get()로 <Enter>까지 입력 받고 출력합니다>> ";
    int ch;
    while ((ch = cin.get()) != EOF) {
        cout.put(ch);
        if (ch == '\n') break;
    }

    cout << "cin.get(char&)로 <Enter>까지 입력 받고 출력합니다>> ";
    char c;
    while (true) {
        cin.get(c);
        if (cin.eof()) break;
        cout.put(c);
        if (c == '\n') break;
    }
}

void demo_getline_ignore() {
    char line[80];
    cout << "getline으로 한 줄 입력>> ";
    cin.getline(line, 80);
    cout << "line = [" << line << "]\n";
    cout << "gcount = " << cin.gcount() << "\n";

    cout << "ignore(5) 후 다음 단어 입력>> ";
    cin.ignore(5);
    string w;
    cin >> w;
    cout << "w=" << w << "\n";
}

int main() {
    demo_output();
    demo_get();
    demo_getline_ignore();
}
