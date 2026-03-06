#include <iostream>
#include <string>
using namespace std;

/*
[Lab13] stoi: string -> int 변환
------------------------------------------------------------
핵심
1) stoi("123") => 123 (int)
2) 숫자가 아닌 문자열이면 예외가 날 수 있다(추후 예외 처리에서 다룸).
------------------------------------------------------------
*/

int main() {
    string s = "123";
    int n = stoi(s);
    cout << "n = " << n << "\n";
    return 0;
}
