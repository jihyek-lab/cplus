#include <iostream>
#include <string>

/*
[핵심 정리]
1) `std::string`은 `==`로 내용 비교가 가능해 비밀번호 비교 코드가 직관적이다.
2) C-문자열의 `strcmp`보다 문법이 간단해 실수 가능성이 줄어든다.
3) 입력이 공백 없이 한 단어라면 `std::cin >> input`으로 충분하다.
4) 공백이 포함될 수 있는 입력은 `std::getline`을 사용한다.
*/

int main() {
    const std::string correct = "zkrypto123";
    std::string input;

    std::cout << "Password: ";
    std::cin >> input;

    if (input == correct) {
        std::cout << "Access granted.\n";
    } else {
        std::cout << "Access denied.\n";
    }

    return 0;
}

/*
[컴파일/실행]
macOS/Linux:
  g++ -std=c++17 13_password_string.cpp -o run
  ./run

Windows(MinGW):
  g++ -std=c++17 13_password_string.cpp -o run.exe
  run.exe
*/
