#include <iostream>
#include <cmath> // sqrt 선언(Declaration)이 들어있는 헤더

/*
[핵심 정리]
1) 헤더(`cmath`)를 include하면 함수 선언 정보를 컴파일러가 알 수 있다.
2) `std::sqrt(x)`처럼 표준 수학 함수는 `std` 네임스페이스로 사용한다.
3) 선언을 모르면 컴파일 단계에서 함수 사용을 검사할 수 없다.
4) 구현 코드는 표준 라이브러리와 링크되어 실행 시 동작한다.
*/

int main() {
    double x;

    std::cout << "Enter a number: ";
    std::cin >> x;

    std::cout << "sqrt(x) = " << std::sqrt(x) << "\n";

    return 0;
}

/*
[컴파일/실행]
macOS/Linux:
  g++ -std=c++17 14_header_function_demo.cpp -o run
  ./run

Windows(MinGW):
  g++ -std=c++17 14_header_function_demo.cpp -o run.exe
  run.exe
*/
