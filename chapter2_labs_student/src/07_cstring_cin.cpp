#include <iostream>

/*
[핵심 정리]
1) `char name[20]`은 최대 19글자 + 문자열 끝(`\0`)만 저장 가능하다.
2) `std::cin >> name`은 공백에서 입력이 끊긴다.
3) 따라서 `Michael Jackson` 입력 시 `Michael`만 저장된다.
4) 긴 입력/공백 입력이 필요한 경우에는 C-문자열보다 `std::string`이 안전하다.
*/

int main() {
    char name[20];

    std::cout << "Enter your name (no spaces): ";

    std::cin >> name;

    std::cout << "You entered: [" << name << "]\n";

    // 주의: 입력이 19글자를 넘으면 배열 경계를 넘어갈 위험이 있다.

    return 0;
}

/*
[컴파일/실행]
macOS/Linux:
  g++ -std=c++17 07_cstring_cin.cpp -o run
  ./run

Windows(MinGW):
  g++ -std=c++17 07_cstring_cin.cpp -o run.exe
  run.exe
*/
