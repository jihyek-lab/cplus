#include <iostream>
using namespace std;

/*
[Lab09] struct vs class: 디폴트 접근 지정자 차이
------------------------------------------------------------
이 코드로 알아야 할 것(핵심 체크)
1) C++에서 struct와 class는 거의 동일(멤버 함수/생성자/상속 등 가능)
2) 가장 큰 기본 차이:
   - class: 디폴트 접근 지정자 = private
   - struct: 디폴트 접근 지정자 = public
3) struct도 private/public을 사용해 캡슐화할 수 있다.
------------------------------------------------------------
*/

class C {
    int x; // class는 디폴트 private
public:
    C(int v) : x(v) {}
    int getX() const { return x; }
};

struct S {
    int x; // struct는 디폴트 public
    S(int v) : x(v) {}
};

int main() {
    C c(10);
    // cout << c.x << "\n"; // (에러) private
    cout << "C.getX() = " << c.getX() << "\n";

    S s(20);
    cout << "S.x = " << s.x << "\n"; // OK

    return 0;
}
