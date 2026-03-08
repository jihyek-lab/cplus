#include <iostream>
#include <string>

/*
[핵심 정리]
1) `std::string`은 길이 관리/복사/비교가 쉬운 C++ 표준 문자열 타입이다.
2) `+` 연산으로 문자열 결합이 가능하다.
3) 길이는 `length()`(또는 `size()`)로 확인한다.
4) `std::string`은 `==`로 "내용 비교"가 가능해 C-문자열보다 직관적이다.
*/

int main() {
    std::string a = "Hello";
    std::string b = "C++";

    std::string c = a + " " + b + "!";
    std::cout << c << "\n";

    std::cout << "Length: " << c.length() << "\n";

    if (b == "C++") {
        std::cout << "b is exactly C++\n";
    }

    return 0;
}

/*
[컴파일/실행]
macOS/Linux:
  g++ -std=c++17 10_string_basic.cpp -o run
  ./run

Windows(MinGW):
  g++ -std=c++17 10_string_basic.cpp -o run.exe
  run.exe
*/
