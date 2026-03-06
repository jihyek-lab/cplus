#include <iostream>

int main() {
    int a = 10, b = 3;

    // (1) << 를 여러 번 이어서 출력 가능
    std::cout << "a = " << a << ", b = " << b << "\n";

    // (2) 괄호로 연산 결과를 출력할 수 있음
    std::cout << "a + b = " << (a + b) << "\n";

    // (3) int / int 는 정수 나눗셈: 소수점 버림(몫만)
    std::cout << "a / b = " << (a / b) << "  (integer division)\n";

    // (4) 줄바꿈 비교
    std::cout << "Line 1\n";               // 줄바꿈 문자만 출력
    std::cout << "Line 2" << std::endl;    // 줄바꿈 + flush 개념

    return 0;
}
