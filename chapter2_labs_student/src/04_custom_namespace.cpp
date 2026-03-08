#include <iostream>

// (1) namespace: 이름(함수/변수/클래스)의 "구역"을 만들어 충돌을 피함
namespace kitae {
    void print() { std::cout << "kitae::print()\n"; }
}

namespace bob {
    void print() { std::cout << "bob::print()\n"; }
}

int main() {
    // (2) 같은 이름 print()라도 네임스페이스로 구분 가능
    kitae::print();
    bob::print();

    // (3) using namespace kitae; 를 쓰면 kitae 안의 이름을 생략 가능
    using namespace kitae;
    print(); // 여기서는 kitae::print()가 호출됨

    // (4) 만약 kitae와 bob을 둘 다 using namespace로 가져오면
    //     print()가 모호해져서 컴파일 에러가 날 수 있음(충돌!)

    return 0;
}
