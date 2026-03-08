#include <iostream>
#include <cstring> // strcmp

/*
[핵심 정리]
1) `char[]`(C-문자열)은 `==`로 "내용 비교"를 하면 안 된다.
2) C-문자열 내용 비교는 `std::strcmp(a, b)`를 사용한다.
3) `std::strcmp` 결과: 같으면 0, 다르면 0이 아님(양수/음수는 사전식 순서).
4) 비밀번호처럼 비교 목적이 명확한 문자열은 `std::string`을 쓰면 코드가 단순해진다(13번).
*/

int main() {
    const char correct[] = "zkrypto123";
    char input[50];

    std::cout << "Password: ";
    std::cin >> input; // 공백 없는 입력이라고 가정

    if (std::strcmp(input, correct) == 0) {
        std::cout << "Access granted.\n";
    } else {
        std::cout << "Access denied.\n";
    }

    return 0;
}

/*
[컴파일/실행]
macOS/Linux:
  g++ -std=c++17 12_password_strcmp.cpp -o run
  ./run

Windows(MinGW):
  g++ -std=c++17 12_password_strcmp.cpp -o run.exe
  run.exe
*/
