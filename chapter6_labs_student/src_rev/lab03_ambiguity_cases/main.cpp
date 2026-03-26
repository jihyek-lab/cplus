#include <iostream>
#include <string>
using namespace std;

/*
[Lab03] 모호성 사례 묶음
------------------------------------------------------------
강의 핵심
1) 오버로딩은 편리하지만, 후보가 둘 이상 똑같이 그럴듯하면 컴파일러도 결정하지 못한다.
2) 디폴트 매개변수는 호출 가능한 함수 수를 늘리기 때문에 모호성을 만들기 쉽다.
3) 자동 형 변환이 여러 방향으로 가능하면 의도하지 않은 충돌이 생긴다.
4) 값 전달과 참조 전달처럼 의미가 다른 함수는 이름을 분리하는 편이 안전하다.
------------------------------------------------------------
*/

namespace DefaultParamConflict {
// 각각은 가능해 보여도, 함께 두면 msg(6) 같은 호출이 충돌할 수 있다.
void msg(int id) {
    cout << "msg(int) -> " << id << "\n";
}

void msg(int id, string text = "") {
    cout << "msg(int, string) -> " << id << ":" << text << "\n";
}
}

namespace CastAmbiguity {
// square(3)에서는 int가 float와 double로 모두 변환될 수 있다.
float square(float value) {
    return value * value;
}

double square(double value) {
    return value * value;
}
}

namespace ReferenceAmbiguity {
// 호출 문법이 같으면 컴파일러 입장에서도 구분 근거가 약해진다.
int add(int a, int b) {
    return a + b;
}

int add(int a, int& b) {
    b += a;
    return b;
}
}

namespace BetterDesign {
// 의미가 다른 함수는 이름을 나눠 두는 편이 더 분명하다.
int addValue(int a, int b) {
    return a + b;
}

int addInPlace(int a, int& b) {
    b += a;
    return b;
}
}

int main() {
    // 디폴트 인자는 호출 가능한 후보를 늘리므로 모호성을 만들 수 있다.
    cout << "[1] 디폴트 매개변수 + 오버로딩\n";
    DefaultParamConflict::msg(5, "Good Morning");
    // DefaultParamConflict::msg(6);
    // 위 줄을 풀면 msg(int) 와 msg(int, string="") 둘 다 가능해서 모호해진다.

    // 자동 형 변환 후보가 둘 이상이면 컴파일러가 고르지 못할 수 있다.
    cout << "\n[2] 형 변환 후보가 둘 다 가능한 경우\n";
    cout << "square(3.0) = " << CastAmbiguity::square(3.0) << "\n";
    cout << "square(static_cast<float>(3)) = "
         << CastAmbiguity::square(static_cast<float>(3)) << "\n";
    // cout << CastAmbiguity::square(3) << "\n";
    // 위 줄을 풀면 int -> float, int -> double 둘 다 가능해서 모호하다.

    // 값 전달과 참조 전달을 같은 이름에 묶으면 호출 의미가 흐려진다.
    cout << "\n[3] 값/참조 오버로딩의 함정\n";
    int s = 10;
    int t = 20;
    cout << "ReferenceAmbiguity::add(10, 20) = "
         << ReferenceAmbiguity::add(10, 20) << "\n";
    // cout << ReferenceAmbiguity::add(s, t) << "\n";
    // 위 줄을 풀면 add(int,int) 와 add(int,int&) 사이에서 모호해질 수 있다.

    // 가능하더라도 헷갈리는 설계라면 이름을 분리하는 쪽이 낫다.
    cout << "\n[4] 더 안전한 설계\n";
    cout << "addValue(s, t) = " << BetterDesign::addValue(s, t) << "\n";
    cout << "addInPlace(s, t) = " << BetterDesign::addInPlace(s, t) << "\n";
    cout << "변경 후 t = " << t << "\n";

    return 0;
}
