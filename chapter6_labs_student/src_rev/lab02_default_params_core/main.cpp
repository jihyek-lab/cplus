#include <iostream>
#include <string>
using namespace std;

/*
[Lab02] 디폴트 매개변수 핵심 묶음
------------------------------------------------------------
강의 핵심
1) 디폴트 매개변수는 "인수를 생략했을 때 자동으로 채워지는 값"이다.
2) 보통 선언부에 적어야 함수 사용자가 기본값을 한눈에 볼 수 있다.
3) 디폴트 값은 뒤에서부터 연속으로만 줄 수 있다.
4) 잘 쓰면 비슷한 함수 여러 개를 만들 필요가 없어져 코드가 단순해진다.
------------------------------------------------------------
*/

void star(int count = 5);
void msg(int id, string text = "");
void calc(int a, int b = 5, int c = 0, int d = 0);
void fillLine(int n = 25, char c = '*');

// 아래 선언은 "중간 매개변수만 디폴트"라서 규칙에 어긋난다.
// 생략된 인수는 오른쪽 끝부터 채워지므로, 중간만 비워 둘 수는 없다.
// void calcBad(int a, int b = 5, int c, int d = 0);

void star(int count) {
    // star()와 star(10)을 하나의 함수로 처리하는 가장 단순한 예다.
    for (int i = 0; i < count; ++i) {
        cout << '*';
    }
    cout << "\n";
}

void msg(int id, string text) {
    // msg(10)은 msg(10, "")처럼 해석된다.
    cout << "id=" << id << ", text=\"" << text << "\"\n";
}

void calc(int a, int b, int c, int d) {
    // 전달되지 않은 인수는 오른쪽 끝부터 디폴트 값으로 채워진다.
    cout << "calc -> " << a << ", " << b << ", " << c << ", " << d << "\n";
}

void fillLine(int n, char c) {
    // 비슷한 함수 둘을 만들지 않고 하나로 줄일 수 있다는 점이 중요하다.
    for (int i = 0; i < n; ++i) {
        cout << c;
    }
    cout << "\n";
}

int main() {
    // 먼저 생략 호출이 어떻게 해석되는지 본다.
    cout << "[기본 호출]\n";
    star();
    star(10);
    msg(10);
    msg(10, "Hello");

    // 이 출력은 디폴트 값이 오른쪽부터 채워진다는 사실을 보여준다.
    cout << "\n[뒤쪽부터 채워지는 규칙]\n";
    calc(10);
    calc(10, 5);
    calc(10, 5, 20);
    calc(10, 5, 20, 30);

    // 디폴트 매개변수는 코드 중복을 줄이는 도구이기도 하다.
    cout << "\n[오버로딩을 줄이는 실전 예]\n";
    fillLine();
    fillLine(10, '%');
    fillLine(12, '-');

    cout << "\ncalcBad 주석을 풀면 디폴트 매개변수 규칙 위반을 확인할 수 있다.\n";

    return 0;
}
