#include <iostream>
#include <string>
using namespace std;

/*
[Lab05] gcount() / ignore()
------------------------------------------------------------
핵심
- cin.gcount()는 "직전에 실행한 입력 함수가 읽은 문자 수" 리턴.
- ignore(n): n개 문자 제거
- ignore(n, delim): delim 만날 때까지(그 문자까지) 제거.

주의
- 어떤 입력 함수 이후에 gcount가 의미 있는지(예: getline/get) 구분.
------------------------------------------------------------
*/

int main() {
    char line[80];
    cout << "문장을 입력하세요>> ";
    cin.getline(line, 80);

    cout << "gcount = " << cin.gcount() << "\n";
    cout << "line = [" << line << "]\n";

    cout << "이제 입력 스트림에서 5문자 ignore\n";
    cin.ignore(5);

    cout << "다음 입력(한 단어)>> ";
    string w;
    cin >> w;
    cout << "w=" << w << "\n";
}
