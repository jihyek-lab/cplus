#include <iostream>
#include <string>

int main() {
    std::string singer;

    std::cout << "Enter your favorite singer (can include spaces): ";

    // (1) getline(cin, string): 공백 포함 한 줄 입력의 정석
    std::getline(std::cin, singer);

    std::cout << "Favorite singer: [" << singer << "]\n";

    // (2) 주의: 앞에서 cin >> 로 숫자 등을 읽었다면,
    //     09번처럼 ignore가 필요할 수 있음 (버퍼에 '\n' 남아있을 때)
    return 0;
}
