#include <iostream>
using namespace std;

/*
[Lab04] 객체 리턴 + 참조 리턴 응용
------------------------------------------------------------
파트 A) 객체 리턴과 대입
- c = getCircle(); 는 대입 연산자로 멤버 복사(기본은 멤버 단위 복사)
- 함수 리턴 시 복사가 생길 수 있으나 RVO/NRVO로 생략될 수 있음

파트 B) 참조 리턴
- 참조 리턴은 "값"이 아니라 "공간(변수)"을 리턴한다.
- 전역/배열 원소/자기 자신을 리턴하는 패턴을 확인한다.
------------------------------------------------------------
*/

class Circle {
    int radius;
public:
    Circle() : radius(1) {}
    Circle(int r) : radius(r) {}
    void setRadius(int r) { radius = r; }
    double getArea() const { return 3.14 * radius * radius; }

    // 참조 반환을 통한 메서드 체이닝
    // - 리턴타입이 Circle& (자신의 참조) → 호출 후 같은 객체 조작 가능
    // - radius += n: 현재 객체의 반지름을 증가
    // - return *this: this 포인터가 가리키는 객체(자신)의 참조 반환
    // - 체이닝 원리: a.plus(1).plus(2)는 a.plus(1) 결과(a의 참조)에 plus(2) 호출
    // - 그 결과: a의 반지름이 1 + 2 증가 (임시 복사 없음, 효율적)
    Circle& plus(int n) {
        radius += n;
        return *this;  // 자신의 참조 반환
    }
    int getRadius() const { return radius; }
};

// 값 반환: Circle 객체의 복사본을 반환하는 함수
// - 리턴타입이 Circle (참조 아님)이므로 값(복사본) 반환
// - 지역 객체 tmp를 반환해도 안전 (복사본이 호출자에게 전달되므로)
// - 단점: 복사 오버헤드 (단, 컴파일러 최적화 RVO/NRVO로 생략될 수 있음)
Circle getCircle() {
    Circle tmp(30);  // 반지름 30인 지역 객체 생성
    return tmp;      // tmp를 복사하여 호출자에게 반환 (tmp 자체가 아니라 복사본!)
}

char g = 'a';  // 전역 변수: 프로그램 전체 생명주기(항상 존재)

// 참조 반환: 전역 변수 g의 "공간" 자체를 반환 (복사 아님!)
// - 리턴타입 char&는 g의 참조이므로 함수 호출 결과를 lvalue로 사용 가능
// - findGlobal() = 'b'처럼 직접 값 할당 가능 (안전: g는 항상 유효)
char& findGlobal() {
    return g;
}

// 참조 반환: 배열 원소에 대한 참조를 반환
// - 매개변수 s[]는 배열의 시작 주소 (포인터처럼 동작)
// - 배열 원소 s[index]는 실제 메모리 공간에 존재 → 참조로 반환 가능 (안전)
// - 함수 호출 후에도 배열은 유효하므로 대기: findAt(...) = 'x' 형태로 직접 수정 가능
char& findAt(char s[], int index) {
    return s[index];  // 배열의 index 위치 원소(공간)의 참조 반환
}

int main() {
    // (A) 객체 리턴 + 대입
    Circle c;
    cout << c.getArea() << "\n";
    // 반환된 객체(복사본 또는 최적화 결과)를 c에 대입
    c = getCircle();
    cout << c.getArea() << "\n\n";

    // (B-1) 전역 변수 참조 리턴
    // findGlobal()이 g의 "공간"을 돌려주므로 대입 가능
    char a = g;
    cout << "a=" << a << "\n";
    findGlobal() = 'b';
    cout << "g=" << g << "\n\n";

    // (B-2) 배열 원소 참조 리턴
    char name[] = "Mike";
    cout << name << "\n";
    // 배열의 0번 원소를 직접 수정
    findAt(name, 0) = 'S';
    cout << name << "\n";
    // 참조를 받아 두고 수정하면 같은 원소가 바뀜
    char& ref = findAt(name, 2);
    ref = 't';
    cout << name << "\n\n";

    // (B-3) 객체 자신 참조 리턴(체이닝)
    // plus()가 *this를 반환하므로 연쇄 호출 가능
    Circle aCircle(5);
    aCircle.plus(1).plus(2).plus(3);
    cout << aCircle.getRadius() << "\n";

    return 0;
}
