#include <iostream>
#include <cstring>
using namespace std;

/*
[Lab03] get(char*,n) + '\\n' 버퍼 함정 + ignore()
------------------------------------------------------------
핵심
- cin.get(buf,n)은 '\\n'을 만나면 읽기를 멈추고,
  '\\n'은 "버퍼에 남긴다".
- 그래서 다음 루프에서 cin.get(buf,n)이 바로 '\\n'을 만나
  빈 문자열을 읽는 문제가 생길 수 있다.

해결
- cin.ignore(1) 또는 cin.get()으로 버퍼에 남은 '\\n' 제거.

실습
- ignore(1)을 주석 처리하면 어떤 일이 생기는지 관찰해보기.
------------------------------------------------------------
*/

int main() {
    char cmd[80];
    cout << "cin.get(char*, int)로 문자열을 읽습니다.\n";

    while (true) {
        cout << "종료하려면 exit을 입력하세요 >> ";
        cin.get(cmd, 80);

        if (strcmp(cmd, "exit") == 0) {
            cout << "프로그램을 종료합니다....\n";
            return 0;
        }

        // 핵심: 남은 '\n' 제거
        cin.ignore(1);
        // cin.get(); // 동일 효과(1글자 제거)
    }
}
