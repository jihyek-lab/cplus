#include <iostream>
#include <limits>

int main() {
    int x;

    std::cout << "Enter an integer: ";
    std::cin >> x;

    // (1) 사용자가 정수가 아닌 값(예: abc)을 입력하면 cin이 실패 상태가 됨
    if (std::cin.fail()) {
        std::cout << "Input was not an integer.\n";

        // (2) clear(): 실패 상태 플래그를 해제 (안 하면 이후 입력도 계속 실패함)
        std::cin.clear();

        // (3) ignore(): 입력 버퍼에 남아있는 찌꺼기(문자/줄)를 버림
        //     max() 만큼 버리되, '\n' 만날 때까지 버림
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 0;
    }

    std::cout << "You entered: " << x << "\n";
    return 0;
}
