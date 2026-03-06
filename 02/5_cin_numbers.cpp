#include <iostream>

int main() {
    int w, h;

    std::cout << "Enter width and height: ";

    // (1) std::cin : 표준 입력 스트림(키보드)
    // (2) >> 연산자 : 입력 스트림에서 값을 "추출"해서 변수에 저장
    // (3) 공백/탭/줄바꿈을 구분자로 사용
    std::cin >> w >> h;

    // (4) 같은 줄에 "3 4" 입력해도 되고, 엔터로 나눠 입력해도 됨
    std::cout << "Area = " << (w * h) << "\n";

    return 0;
}
