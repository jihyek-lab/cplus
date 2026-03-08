#include <iostream>

/*
[핵심 정리]
1) 이 예제는 "배열(C-문자열)로 한 줄 입력받는 방법"을 소개하는 보조(레거시) 예제다.
2) `std::cin.getline(char배열, 크기)`는 공백 포함 한 줄을 읽고, 최대 `크기-1`글자 + `\0`을 저장한다.
3) 배열 크기를 넘는 긴 입력은 잘려 저장될 수 있어 길이 관리 부담이 있다.
4) 실무 기본은 09번처럼 `std::string + std::getline`이며, C-문자열은 호환 코드에서 주로 본다.
*/

int main() {
    char line[10];

    std::cout << "Enter a full sentence: ";
    std::cin.getline(line, 10);
    std::cout << "You entered: [" << line << "]\n";
   
    return 0;
}

/*
[컴파일/실행]
macOS/Linux:
  g++ -std=c++17 08_cstring_getline.cpp -o run
  ./run

Windows(MinGW):
  g++ -std=c++17 08_cstring_getline.cpp -o run.exe
  run.exe
*/
