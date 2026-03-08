#include <iostream>
#include <limits>

/*
[핵심 정리]
1) `std::cin >> x`에서 숫자 대신 문자(예: `abc`)를 입력하면 입력이 실패한다.
2) 실패 상태에서는 이후 입력도 연쇄 실패하므로 `clear()`로 상태를 복구해야 한다.
3) 실패 원인이 된 버퍼 데이터를 `ignore(...)`로 버려야 다음 입력이 정상 동작한다.
4) 실전 규칙: 입력 검사는 "읽기 직후" 바로 수행한다.
*/

int main() {
    int x;

    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (std::cin.fail()) {
        std::cout << "Input was not an integer.\n";

        // 실패 상태 플래그 해제
        std::cin.clear();

        // 잘못 남은 입력 버퍼 비우기
        // 개행('\n')이 나올 때까지 입력 버퍼를 비우기
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 0;
    }

    std::cout << "You entered: " << x << "\n";
    return 0;
}

/*
[컴파일/실행]
macOS/Linux:
  g++ -std=c++17 06_cin_fail_backup.cpp -o run
  ./run

Windows(MinGW):
  g++ -std=c++17 06_cin_fail_backup.cpp -o run.exe
  run.exe
*/
