#include <iostream>
using namespace std;

/*
[Lab02] 연산자 오버로딩 기본(+ , == , +=)
------------------------------------------------------------
문제 설명
1) Power 객체끼리 + 연산을 수행하고 결과 객체를 만든다.
2) 두 객체가 같은지 == 로 비교한다.
3) += 연산으로 자기 자신을 변경하고 체이닝을 확인한다.
------------------------------------------------------------
핵심 요약
- operator+ : 새 객체 반환(원본 불변)
- operator==: 비교 연산(보통 const 멤버)
- operator+=: 원본 변경 + 참조 반환(체이닝 가능)
------------------------------------------------------------
문법 설명
- 연산자 오버로딩은 `operator연산자기호` 형태의 멤버 함수로 정의할 수 있다.
- `a + b` 는 멤버 함수로 쓰면 `a.operator+(b)`처럼 해석된다.
- `a == b` 는 `a.operator==(b)`처럼 해석된다.
- `a += b` 는 `a.operator+=(b)`처럼 해석된다.
- 매개변수 `const Power& op2`는 오른쪽 피연산자를 의미한다.
- 함수 뒤의 `const`는 "왼쪽 객체(this)를 바꾸지 않겠다"는 뜻이다.
------------------------------------------------------------
주의/포인트
- 비교 연산은 상태를 바꾸지 않으므로 const가 자연스럽다.
- +=는 연쇄 호출을 위해 *this 참조를 반환하는 것이 관례다.
------------------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    // 기본값을 둔 생성자이므로 Power(), Power(3,5) 둘 다 가능하다.
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    // 멤버 연산자 함수 문법:
    // 반환형 operator연산자기호(오른쪽피연산자) [const]
    //
    // 여기서는 a + b 를 a.operator+(b)로 해석한다.
    // +는 원본 a를 바꾸지 않고 "새 결과 객체"를 만들어 반환하는 것이 자연스럽다.
    Power operator+(const Power& op2) const {
        // a + b -> 새로운 Power 생성
        return Power(kick + op2.kick, punch + op2.punch);
    }

    // == 는 비교 결과가 참/거짓이므로 보통 bool을 반환한다.
    // 비교만 할 뿐 객체 상태를 바꾸지 않으므로 const 멤버 함수가 적절하다.
    bool operator==(const Power& op2) const {
        // 비교 연산은 상태를 바꾸지 않음
        return (kick == op2.kick && punch == op2.punch);
    }

    // += 는 왼쪽 객체 자신을 바꾸는 연산이다.
    // 따라서 반환형을 Power&로 두고 *this를 반환하면
    // (a += b) += c 같은 연쇄 사용도 가능해진다.
    Power& operator+=(const Power& op2) {
        // 자기 자신을 변경하고 참조 리턴
        kick += op2.kick;
        punch += op2.punch;
        return *this;
    }
};

int main() {
    Power a(3,5), b(4,6), c;

    // a + b 는 a.operator+(b) 호출과 같은 의미다.
    c = a + b;
    a.show(); b.show(); c.show();

    // a == b 는 a.operator==(b) 호출과 같은 의미다.
    cout << (a == b ? "same\n" : "diff\n");

    // a += b 는 a.operator+=(b) 호출과 같다.
    // 반환값이 Power& 이므로 그 결과를 다시 c에 대입할 수 있다.
    c = (a += b); // a 변경, c는 a의 참조 결과
    a.show(); c.show();

    return 0;
}
