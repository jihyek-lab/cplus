#include <iostream>

int main() {
    char line[100];

    std::cout << "Enter a full sentence: ";

    // (1) cin.getline(): 공백 포함해서 한 줄 전체를 읽음(엔터 전까지)
    // (2) 최대 99글자 + 마지막에 '\0' (문자열 끝 표시) 저장
    std::cin.getline(line, 100);

    std::cout << "You entered: [" << line << "]\n";

    // (3) 배열 크기 제한 때문에 긴 문장은 잘릴 수 있음 -> string이 더 편함
    return 0;
}
