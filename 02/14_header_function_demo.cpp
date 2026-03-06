#include <iostream>
#include <cmath> // sqrt 선언(Declaration)이 들어있는 헤더

int main() {
    double x;

    std::cout << "Enter a number: ";
    std::cin >> x;

    // (1) 헤더를 include 하는 이유:
    //     컴파일러에게 "sqrt라는 함수가 존재한다"는 선언을 알려주기 위해서
    // (2) 실제 구현은 표준 라이브러리와 링크되어 실행됨(1장의 컴파일/링크 흐름과 연결)
    std::cout << "sqrt(x) = " << std::sqrt(x) << "\n";

    return 0;
}
