#include <iostream>
using namespace std;

/*
[Lab04] 증감/논리/체이닝 연산자
------------------------------------------------------------
문제 설명
1) 전위/후위 ++ 연산의 차이를 확인한다.
2) ! 연산자로 상태를 검사한다.
3) << 연산자로 참조 리턴 체이닝을 경험한다.
------------------------------------------------------------
핵심 요약
- 전위 ++ : operator++() -> 증가 후 참조 반환
- 후위 ++ : operator++(int) -> 증가 전 값 반환
- ! 연산자 : bool 반환
- << 체이닝 : 참조 반환이 핵심
------------------------------------------------------------
주의/포인트
- 전위/후위는 시그니처와 반환 의미가 다르다.
- << 오버로딩은 실제 스트림 출력과 혼동 가능(교육용 예제).
------------------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    // 전위 ++ (멤버)
    Power& operator++() {
        // 증가 후 자신 반환
        kick++; punch++;
        return *this;
    }

    // 후위 ++ (멤버)
    Power operator++(int) {
        // 증가 전 값을 복사해 반환
        Power tmp = *this;
        kick++; punch++;
        return tmp;
    }

    // ! 연산자
    bool operator!() const {
        // 둘 다 0이면 true
        return (kick == 0 && punch == 0);
    }

    // 체이닝용 << (교육용)
    Power& operator<<(int n) {
        // 참조 리턴으로 연쇄 호출 가능
        kick += n;
        punch += n;
        return *this;
    }

    // friend 전위/후위 ++ 버전도 제공
    friend Power& operator++(Power& op);
    friend Power operator++(Power& op, int);
};

Power& operator++(Power& op) {
    op.kick++; op.punch++;
    return op;
}

Power operator++(Power& op, int) {
    Power tmp = op;
    op.kick++; op.punch++;
    return tmp;
}

int main() {
    Power a(3,5), b;

    b = ++a; // 전위
    a.show(); b.show();

    b = a++; // 후위
    a.show(); b.show();

    cout << (!Power(0,0) ? "zero\n" : "not zero\n");

    Power c(1,2);
    c << 3 << 5 << 6;
    c.show();

    return 0;
}
