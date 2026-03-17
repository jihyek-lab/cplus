#include <iostream>
#include <string>
using namespace std;

/*
[Lab12] string 기본 + 입력 + stoi
------------------------------------------------------------
핵심
1) string은 가변 길이 문자열 클래스. (char[]보다 안전/편리)
2) 생성/복사/C-스트링에서 생성, append/length 사용
3) getline(cin >> ws, s)로 공백 포함 한 줄 입력
4) stoi로 문자열을 int로 변환 가능
------------------------------------------------------------
새로 나오는 함수 요약
- append(str): 문자열 뒤에 str을 붙임
- length(): 문자열 길이 반환 (size()와 동일)
- getline(cin >> ws, s): 앞 공백 제거 후 한 줄 입력
- stoi(str): 문자열을 int로 변환
------------------------------------------------------------
*/

int main() {
    // (1) string 생성/복사
    string str;
    string address("서울시 성북구 삼선동 389");
    string copyAddress(address);

    char text[] = {'L','o','v','e',' ','C','+','+','\0'};
    string title(text);

    cout << "str=[" << str << "]\n";
    cout << address << "\n";
    cout << copyAddress << "\n";
    cout << title << "\n";

    // (2) append/length
    // append: 뒤에 문자열을 이어 붙임
    // length: 문자열 길이 반환 (size()와 동일)
    str.append("I love ");
    str.append("C++.");
    cout << str << "\n";
    cout << "length = " << str.length() << "\n\n";

    // (3) getline 입력 (공백 포함)
    string line;
    cout << "Enter a line: ";
    // getline: 개행 전까지 한 줄 전체를 읽음 (공백 포함)
    getline(cin >> ws, line);
    cout << "line = [" << line << "]\n\n";

    // (4) stoi
    // stoi: 문자열을 int로 변환 (앞 공백은 무시, 숫자 아닌 내용은 예외 가능)
    string s = "123";
    int n = stoi(s);
    cout << "stoi(\"" << s << "\") = " << n << "\n";

    return 0;
}
