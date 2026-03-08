#include <iostream>

int main() {
    char name[20];

    std::cout << "Enter your name (no spaces): ";

    // (1) char 배열로 문자열 입력: cin >> 는 공백에서 끊김
    //     예: "Michael Jackson" 입력하면 name에는 "Michael"만 들어감
    std::cin >> name;

    std::cout << "You entered: [" << name << "]\n";

    // (2) 주의: 입력이 19글자보다 길면 배열을 넘겨서 위험(버퍼 오버플로우 가능)
    //     => 그래서 C++에서는 보통 string을 추천

    return 0;
}
