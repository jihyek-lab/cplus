#include <iostream>

/*
[핵심 정리]
1) `std::cin`은 키보드 입력(표준 입력 스트림)을 읽는다.
2) `>>`는 공백/탭/줄바꿈을 구분자로 사용해서 값을 순서대로 변수에 저장한다.
3) `std::cin >> w >> h;`는 한 줄 입력(`3 4`)도 되고, 여러 줄 입력도 된다.
4) 입력이 숫자가 아니면 실패 상태가 될 수 있으므로, 다음 실습(06)처럼 검사가 필요하다.
*/

int main() {
    int w, h;

    std::cout << "Enter width and height: ";

    std::cin >> w >> h;

    std::cout << "Area = " << (w * h) << "\n";

    return 0;
}

/*
[컴파일/실행]
macOS/Linux:
  g++ -std=c++17 05_cin_numbers.cpp -o run
  ./run

Windows(MinGW):
  g++ -std=c++17 05_cin_numbers.cpp -o run.exe
  run.exe
*/
