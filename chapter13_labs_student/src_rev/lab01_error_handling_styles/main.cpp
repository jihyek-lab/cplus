#include <iostream>
using namespace std;

/*
[Lab01] 오류 처리 방식 비교: 무시/리턴코드/out/throw
------------------------------------------------------------
문제 설명
1) 잘못된 입력을 "조용히" 처리하면 어떤 문제가 생기는지 본다.
2) 리턴 코드(-1), bool+out, throw 방식의 차이를 비교한다.
------------------------------------------------------------
핵심 요약
- 리턴 코드: 충돌 가능(정상 값과 구분 어려움)
- bool+out: 성공/실패 분리 가능(패턴 반복)
- throw: 오류를 호출자에게 전파, 흐름 분리 가능
------------------------------------------------------------
주의 포인트
- 예외는 남용하지 말고, 실패가 "예외 상황"인 경우에 사용한다.
------------------------------------------------------------
*/

int getExp_no_check(int base, int exp) {
    int value = 1;
    for(int n=0; n<exp; n++) value *= base;
    return value;
}

int getExp_return_error(int base, int exp) {
    if(base <= 0 || exp <= 0) return -1; // 오류 표시
    int value = 1;
    for(int n=0; n<exp; n++) value *= base;
    return value;
}

bool getExp_bool_out(int base, int exp, int& out) {
    if(base <= 0 || exp <= 0) return false;
    int value = 1;
    for(int n=0; n<exp; n++) value *= base;
    out = value;
    return true;
}

int getExp_throw(int base, int exp) {
    if(base <= 0 || exp <= 0) throw "음수 사용 불가";
    int value = 1;
    for(int n=0; n<exp; n++) value *= base;
    return value;
}

int main() {
    cout << "no check 2^-3 = " << getExp_no_check(2, -3) << "\n";

    int v = getExp_return_error(2, -3);
    cout << "return code = " << v << "\n";

    int out;
    if(getExp_bool_out(2, 3, out)) cout << "bool/out = " << out << "\n";
    else cout << "bool/out = 오류\n";

    try {
        cout << "throw = " << getExp_throw(2, -3) << "\n";
    } catch(const char* msg) {
        cout << "예외: " << msg << "\n";
    }
}
