#include <iostream>
#include <string>

/*
[핵심 정리]
1) `std::getline(std::cin, s)`는 공백을 포함한 한 줄 전체를 읽는다.
2) 이름/문장/주소처럼 공백이 들어가는 입력은 `getline`이 기본 선택이다.
3) 바로 앞에서 `>>`를 썼다면 버퍼의 `\n` 때문에 빈 문자열이 읽힐 수 있다.
4) 이 경우 09번처럼 `ignore(...)`로 버퍼를 먼저 정리한다.
*/

int main() {
    std::string singer;

    std::cout << "Enter your favorite singer (can include spaces): ";

    std::getline(std::cin, singer);

    std::cout << "Favorite singer: [" << singer << "]\n";

    return 0;
}

/*
[컴파일/실행]
macOS/Linux:
  g++ -std=c++17 11_string_getline.cpp -o run
  ./run

Windows(MinGW):
  g++ -std=c++17 11_string_getline.cpp -o run.exe
  run.exe
*/
