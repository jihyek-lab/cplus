#include <iostream>
using namespace std;

/*
[Lab10] 디폴트 매개변수로 "중복 간소화"
-----------------------------------------
핵심
- 원래는 fillLine() 과 fillLine(n,c) 두 함수를 만들 수 있지만,
- 디폴트 매개변수로 하나의 함수로 합칠 수 있다.

여기서 확인할 것
- fillLine();        -> 25개 '*'
- fillLine(10,'%');  -> 10개 '%'
-----------------------------------------
*/

void fillLine(int n = 25, char c = '*') {
    for (int i = 0; i < n; i++) cout << c;
    cout << "\n";
}

int main() {
    fillLine();
    fillLine(10, '%');
    return 0;
}
