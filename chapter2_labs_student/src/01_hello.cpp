#include <iostream>
// (1) iostream: 표준 입출력(cin, cout, endl)을 쓰기 위해 포함
// (2) 컴파일 전에 전처리기가 iostream 선언들을 포함시킴

int main() {
    // (3) C++ 프로그램은 main()에서 시작해서 main()이 끝나면 종료됨
    // (4) int main() + return 0; 가 "표준" 형태 (정상 종료 코드 0)

    std::cout << "Hello C++!" << std::endl;
    // (5) std::cout : 표준 출력 스트림(콘솔 화면)
    // (6) << 연산자 : 오른쪽 값을 왼쪽 스트림에 "삽입" (출력)
    // (7) std::endl : 줄바꿈 + (필요시) 출력 버퍼 비우기(flush)

    std::cout << "This program starts at main() and ends when main() ends.\n";
    // (8) '\n'도 줄바꿈. 보통은 '\n'을 더 자주 사용(간단/빠름)

    return 0; // (9) 운영체제에 "정상 종료"를 알림
}
