#include <iostream>

/*
[핵심 정리]
1) << 연산자를 이어서 여러 값을 한 번에 출력할 수 있다.
2) int / int는 정수 나눗셈이라 소수점 이하가 버려진다.
3) '\n'은 줄바꿈 문자만 출력하고, std::endl은 줄바꿈 후 flush까지 수행한다.
4) 학생용 실전 규칙: 기본은 '\n', 즉시 화면 반영이 꼭 필요할 때만 std::endl 사용.
*/

int main() {
    int a = 10, b = 3;

    std::cout << "a = " << a << ", b = " << b << "\n";

    std::cout << "a + b = " << (a + b) << "\n";

    std::cout << "a / b = " << (a / b) << "  (integer division)\n";

    // 선택 가이드:
    // - 일반 출력(대부분): '\n' 사용
    // - 입력 직전 안내처럼 "지금 당장 보여야 하는" 출력: std::endl 사용
    std::cout << "Line 1\n";            // 줄바꿈만 수행
    std::cout << "Line 2" << std::endl; // 줄바꿈 + 즉시 flush

    return 0;
}

/*
[컴파일/실행]
macOS/Linux:
  g++ -std=c++17 02_cout_chain.cpp -o run
  ./run

Windows(MinGW):
  g++ -std=c++17 02_cout_chain.cpp -o run.exe
  run.exe
*/
