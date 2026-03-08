#include <iostream>

/*
[핵심 정리]
1) C++ 프로그램은 main()에서 시작한다.
2) 표준 출력은 std::cout을 사용한다.
3) 줄바꿈은 '\n' 또는 std::endl로 할 수 있다.
4) return 0;은 프로그램이 정상 종료되었음을 의미한다.
*/

int main() {
    std::cout << "Hello C++!" << std::endl;
    std::cout << "This program starts at main() and ends when main() ends.\n";
    return 0;
}

/*
[컴파일/실행]
macOS/Linux:
  g++ -std=c++17 01_hello.cpp -o run
  ./run

Windows(MinGW):
  g++ -std=c++17 01_hello.cpp -o run.exe
  run.exe
*/
