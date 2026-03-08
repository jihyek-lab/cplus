#include <iostream>
#include <string>
#include <limits>

/*
[핵심 정리]
1) `>>`는 필요한 토큰만 읽고, 엔터(`\n`)는 버퍼에 남길 수 있다.
2) 직후 `std::getline`을 호출하면 남은 `\n`을 읽어 빈 문자열이 될 수 있다.
3) 해결법: `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');`
4) 암기: `>>` 다음에 `getline`이면 `ignore` 한 번.
*/

int main() {
    int age;
    std::string intro;

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
