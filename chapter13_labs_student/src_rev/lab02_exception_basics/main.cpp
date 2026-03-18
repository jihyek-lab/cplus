#include <iostream>
#include <cstring>
using namespace std;

/*
[Lab02] 예외 기본: throw/try/catch + 문자열 변환 예제
------------------------------------------------------------
문제 설명
1) 예외를 던지고 catch로 처리하는 기본 흐름을 익힌다.
2) stringToInt에서 잘못된 문자를 발견하면 예외를 던진다.
------------------------------------------------------------
핵심 요약
- try 블록에서 throw 발생 → 일치하는 catch가 처리
- catch는 타입이 가장 일치하는 곳으로 이동
------------------------------------------------------------
주의 포인트
- throw 이후 코드는 실행되지 않는다.
------------------------------------------------------------
*/

int stringToInt(const char x[]) {
    int sum = 0;
    for(int i=0; i<(int)strlen(x); i++) {
        if(x[i] >= '0' && x[i] <= '9') sum = sum*10 + (x[i]-'0');
        else throw x;
    }
    return sum;
}

int main() {
    try {
        cout << stringToInt("123") << "\n";
        cout << stringToInt("1A3") << "\n";
    } catch(const char* s) {
        cout << "예외: " << s << "\n";
    }
}
