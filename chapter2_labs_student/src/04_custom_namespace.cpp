#include <iostream>

/*
[핵심 정리]
1) namespace는 이름(함수/변수/클래스)의 "구역"을 만들어 이름 충돌을 줄인다.
2) 같은 이름 함수라도 `kitae::print()`, `bob::print()`처럼 구분해서 호출할 수 있다.
3) `using namespace ...`는 편하지만, 여러 네임스페이스를 섞으면 이름 충돌로 모호성 에러가 날 수 있다.
4) 학생용 권장: 초반에는 `std::cout`처럼 접두사(`::`)를 명시하는 습관을 들인다.
*/

namespace kitae {
    void print() { std::cout << "kitae::print()\n"; }
}

namespace bob {
    void print() { std::cout << "bob::print()\n"; }
}

int main() {
    // 같은 이름 print()라도 네임스페이스로 구분 가능
    kitae::print();
    bob::print();

    // using namespace kitae; 를 쓰면 kitae 안의 이름을 생략 가능
    using namespace kitae;
    print(); // 여기서는 kitae::print()가 호출됨

    // 만약 kitae와 bob을 둘 다 using namespace로 가져오면
    // print()가 모호해져서 컴파일 에러가 날 수 있음(충돌!)

    return 0;
}

/*
[컴파일/실행]
macOS/Linux:
  g++ -std=c++17 04_custom_namespace.cpp -o run
  ./run

Windows(MinGW):
  g++ -std=c++17 04_custom_namespace.cpp -o run.exe
  run.exe
*/
