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
주의/포인트
- 비교 연산은 상태를 바꾸지 않으므로 const가 자연스럽다.
- +=는 연쇄 호출을 위해 *this 참조를 반환하는 것이 관례다.
------------------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    Power operator+(const Power& op2) const {
        // a + b -> 새로운 Power 생성
        return Power(kick + op2.kick, punch + op2.punch);
    }

    bool operator==(const Power& op2) const {
        // 비교 연산은 상태를 바꾸지 않음
        return (kick == op2.kick && punch == op2.punch);
    }

    Power& operator+=(const Power& op2) {
        // 자기 자신을 변경하고 참조 리턴
        kick += op2.kick;
        punch += op2.punch;
        return *this;
    }
};

int main() {
    Power a(3,5), b(4,6), c;

    c = a + b;
    a.show(); b.show(); c.show();

    cout << (a == b ? "same\n" : "diff\n");

    c = (a += b); // a 변경, c는 a의 참조 결과
    a.show(); c.show();

    return 0;
}
