#include <iostream>
using namespace std;

/*
[Lab10] 참조 리턴 vs 값 리턴
------------------------------------------------------------
핵심
1) 참조 리턴은 "값"이 아니라 "공간(변수)"을 리턴한다.
2) 그래서 findGlobal() = 'b'; 같은 코드가 가능.
3) 주의: 지역 변수(함수 안 변수)를 참조로 리턴하면 댕글링 참조(치명적).
------------------------------------------------------------
*/

char g = 'a';

char& findGlobal() { // 참조 리턴: g 공간을 리턴
    return g;
}

char getValue() { // 값 리턴: g 값만 복사
    return g;
}

int main() {
    char a = getValue();
    cout << "a=" << a << "\n";

    findGlobal() = 'b'; // g에 직접 대입
    cout << "g=" << g << "\n";
    return 0;
}
