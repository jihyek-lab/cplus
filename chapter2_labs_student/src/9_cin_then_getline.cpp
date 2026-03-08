#include <iostream>
#include <string>
#include <limits>

int main() {
    int age;
    std::string intro;

    std::cout << "Enter age: ";
    std::cin >> age;

    // (1) 핵심 버그:
    //     cin >> age 는 숫자만 읽고, 사용자가 친 엔터('\n')는 입력 버퍼에 남을 수 있음
    //     그래서 다음 getline이 그 '\n'을 읽어버려 intro가 빈 문자열이 되는 경우가 많음

    // (2) 해결: 버퍼에 남은 '\n'을 버리고 다음 입력으로 넘어간다
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter a one-line introduction: ";
    std::getline(std::cin, intro); // 공백 포함 한 줄 입력

    std::cout << "age = " << age << "\n";
    std::cout << "intro = [" << intro << "]\n";

    // (3) 암기: ">> 다음 getline이면 ignore 한 번"
    return 0;
}
