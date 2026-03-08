#include <iostream>
#include <cstring>
using namespace std;

/*
[Lab04] getline(): 공백 포함 한 줄 읽기
------------------------------------------------------------
핵심
- cin.getline(line,n)은 '\\n'을 만나면 종료하고,
  '\\n'은 버퍼에서 제거한다(배열에는 저장하지 않음).
- 즉 get(char*,n)과 달리 '\\n'이 남지 않아 다음 입력이 깔끔하다.
------------------------------------------------------------
*/

int main() {
    char line[80];
    cout << "cin.getline() 함수로 라인을 읽습니다.\n";
    cout << "exit를 입력하면 루프가 끝납니다.\n";

    int no = 1;
    while (true) {
        cout << "라인 " << no << " >> ";
        cin.getline(line, 80);
        if (strcmp(line, "exit") == 0) break;

        cout << "echo --> " << line << "\n";
        no++;
    }
}
