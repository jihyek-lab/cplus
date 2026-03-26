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
문법 설명
- 전위 `++a` 는 `a.operator++()`처럼 해석된다.
- 후위 `a++` 는 `a.operator++(0)`처럼 해석된다.
- 후위에서의 `int` 매개변수는 실제 값을 쓰기 위한 것이 아니라,
  "전위와 후위를 구분하기 위한 더미(dummy) 표식"이다.
- 전위는 증가된 자기 자신을 계속 써야 하므로 참조 반환이 자연스럽다.
- 후위는 증가 전의 옛값을 돌려줘야 하므로 보통 값 반환을 사용한다.
- `!a` 는 `a.operator!()`처럼 해석된다.
- `c << 3 << 5` 같은 체이닝은 각 단계가 참조를 반환하기 때문에 가능하다.
------------------------------------------------------------
주의/포인트
- 전위/후위는 시그니처와 반환 의미가 다르다.
- << 오버로딩은 실제 스트림 출력과 혼동 가능(교육용 예제).
------------------------------------------------------------
*/

class Power {
    int kick, punch;
public:
    // 기본값이 있으므로 Power(), Power(3,5) 둘 다 가능하다.
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    void show() const { cout << "kick=" << kick << ",punch=" << punch << "\n"; }

    // 전위 ++ (멤버)
    // ++a -> a.operator++()
    // 증가 후의 자기 자신을 계속 사용해야 하므로 Power& 반환이 자연스럽다.
    Power& operator++() {
        // 증가 후 자신 반환
        kick++; punch++;
        return *this;
    }

    // 후위 ++ (멤버)
    // a++ -> a.operator++(0)
    // 여기의 int는 값 의미가 아니라 "후위 버전" 표시용이다.
    // 후위는 증가 전의 옛값을 돌려줘야 하므로 복사본을 값으로 반환한다.
    Power operator++(int) {
        // 증가 전 값을 복사해 반환
        Power tmp = *this;
        kick++; punch++;
        return tmp;
    }

    // ! 연산자
    // !a -> a.operator!()
    bool operator!() const {
        // 둘 다 0이면 true
        return (kick == 0 && punch == 0);
    }

    // 체이닝용 << (교육용)
    // c << 3 은 c.operator<<(3)처럼 해석된다.
    // 참조를 반환해야 다시 << 5, << 6 으로 이어 붙일 수 있다.
    Power& operator<<(int n) {
        // 참조 리턴으로 연쇄 호출 가능
        kick += n;
        punch += n;
        return *this;
    }

    // 같은 연산을 외부 friend 함수 형태로도 만들 수 있음을 보여주는 예다.
 //   friend Power& operator++(Power& op);
 //   friend Power operator++(Power& op, int);
};

/*
// 외부 함수 버전 전위 ++
// ++a -> operator++(a)
Power& operator++(Power& op) {
    op.kick++; op.punch++;
    return op;
}

// 외부 함수 버전 후위 ++
// a++ -> operator++(a, 0)
Power operator++(Power& op, int) {
    Power tmp = op;
    op.kick++; op.punch++;
    return tmp;
}
*/
int main() {
    Power a(3,5), b;

    // 전위: 먼저 a가 증가하고, 그 증가된 결과가 b에 들어간다.
    b = ++a; // 전위
    a.show(); b.show();

    // 후위: 먼저 증가 전 값이 b에 들어가고, 그 뒤에 a가 증가한다.
    b = a++; // 후위
    a.show(); b.show();

    // !Power(0,0)은 true가 되므로 "zero"가 출력된다.
    cout << (!Power(0,0) ? "zero\n" : "not zero\n");

    Power c(1,2);
    // 참조 반환 덕분에 한 줄에서 연속 호출이 가능하다.
    c << 3 << 5 << 6;
    c.show();

    return 0;
}
