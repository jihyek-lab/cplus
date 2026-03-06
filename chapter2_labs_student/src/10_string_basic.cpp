#include <iostream>
#include <string>

int main() {
    // (1) string: C++의 표준 문자열 클래스 (길이 관리/복사/비교가 쉬움)
    std::string a = "Hello";
    std::string b = "C++";

    // (2) string은 + 로 결합 가능
    std::string c = a + " " + b + "!";
    std::cout << c << "\n";

    // (3) 길이 구하기
    std::cout << "Length: " << c.length() << "\n";

    // (4) string은 == 로 내용 비교 가능 (char 배열과 대비!)
    if (b == "C++") {
        std::cout << "b is exactly C++\n";
    }

    return 0;
}
