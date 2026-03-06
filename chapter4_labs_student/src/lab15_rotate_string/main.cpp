#include <iostream>
#include <string>
using namespace std;

/*
[Lab15] 문자열 회전: substr로 왼쪽 1칸 회전 반복
------------------------------------------------------------
핵심
1) substr(pos, len)로 부분 문자열을 만들 수 있다.
2) 왼쪽 1칸 회전:
   - first = s.substr(0,1)
   - rest  = s.substr(1, len-1)
   - s = rest + first
3) 길이만큼 반복하면 모든 회전 결과를 볼 수 있다.
------------------------------------------------------------
*/

int main() {
    string s;
    cout << "Enter a line: ";
    getline(cin, s);

    int len = (int)s.length();
    for (int i = 0; i < len; i++) {
        string first = s.substr(0, 1);
        string rest  = s.substr(1, len - 1);
        s = rest + first;
        cout << s << "\n";
    }
    return 0;
}
