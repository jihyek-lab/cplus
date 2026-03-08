#include <iostream>
#include <string>
#include <limits>

/*
[핵심 정리]
1) `std::string`은 C++ 표준 문자열 타입으로, 길이를 자동 관리해 `char[]`보다 다루기 쉽다.
2) 실무 기본 문자열 입력은 `std::string + std::getline` 조합이다.
3) 다만 앞에서 `>>`를 쓰면 엔터(`\n`)가 버퍼에 남아, 다음 `getline`이 빈 문자열이 될 수 있다.
4) 해결은 `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');` 한 줄이다.
5) 암기: `>>` 다음에 `getline`이면 `ignore` 한 번.
*/

int main() {
    int age;
    std::string intro; // 공백 포함 문장 입력에 적합한 문자열 타입

    std::cout << "Enter age: ";
    std::cin >> age;

    // 버퍼에 남은 엔터 제거
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter a one-line introduction: ";
    std::getline(std::cin, intro); // 공백 포함 한 줄 입력

    std::cout << "age = " << age << "\n";
    std::cout << "intro = [" << intro << "]\n";

    return 0;
}

/*
[컴파일/실행]
macOS/Linux:
  g++ -std=c++17 09_cin_then_getline.cpp -o run
  ./run

Windows(MinGW):
  g++ -std=c++17 09_cin_then_getline.cpp -o run.exe
  run.exe
*/
