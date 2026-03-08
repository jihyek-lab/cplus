#include <iostream>

int main() {
    // (1) C++ 표준 라이브러리 이름들은 std 네임스페이스에 있음
    //     그래서 원래 cout은 std::cout, endl은 std::endl

    // [A] std::를 붙여 쓰는 방식 (가장 안전, 충돌 적음)
    std::cout << "[A] Using std:: prefix\n";

    // [B] 필요한 이름만 가져오기 (실무에서 추천되는 절충)
    using std::cout;
    using std::endl;
    cout << "[B] Using selected names (cout, endl)\n" << endl;

    // [C] std 안의 이름을 전부 가져오기 (실습에서는 편하지만 큰 프로젝트에서는 충돌 위험)
    using namespace std;
    cout << "[C] Using namespace std;\n";

    return 0;
}
