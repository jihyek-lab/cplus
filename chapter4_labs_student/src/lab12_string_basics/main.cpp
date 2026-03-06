#include <iostream>
#include <string>
using namespace std;

/*
[Lab12] string 기본: 생성/복사/출력, C-스트링에서 생성, append
------------------------------------------------------------
핵심
1) string은 가변 길이 문자열 클래스. (char[]보다 안전/편리)
2) 생성 방법:
   - string s;  (빈 문자열)
   - string s("text");
   - string copy(s);  (복사 생성)
   - string s(charArray); (C-스트링에서 생성)
3) append/length 등 다양한 멤버 함수 제공
------------------------------------------------------------
*/

int main() {
    string str;                         // 빈 문자열
    string address("서울시 성북구 삼선동 389");
    string copyAddress(address);        // 복사 생성

    char text[] = {'L','o','v','e',' ','C','+','+','\0'};
    string title(text);                 // C-스트링 -> string

    cout << "str=[" << str << "]\n";
    cout << address << "\n";
    cout << copyAddress << "\n";
    cout << title << "\n";

    str.append("I love ");
    str.append("C++.");
    cout << str << "\n";

    return 0;
}
