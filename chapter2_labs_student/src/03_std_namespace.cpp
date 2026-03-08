#include <iostream>

/*
[핵심 정리]
1) C++ 표준 라이브러리 이름(cout, endl 등)은 std 네임스페이스에 있다.
2) std 사용 방식 3가지
   - std::cout 처럼 접두사 사용: 가장 안전(권장)
   - using std::cout; 처럼 필요한 이름만 가져오기: 실무 절충안
   - using namespace std; 전체 가져오기: 편하지만 이름 충돌 위험
*/

int main() {
    // [A] std::를 붙여 쓰는 방식 (가장 안전)
    std::cout << "[A] Using std:: prefix\n";

    // [B] 필요한 이름만 가져오기 (실무 절충)
    using std::cout;
    using std::endl;
    cout << "[B] Using selected names (cout, endl)\n" << endl;

    // [C] std 이름 전체 가져오기 (충돌 위험)
    using namespace std;
    cout << "[C] Using namespace std;\n";

    return 0;
}

/*
[컴파일/실행]
macOS/Linux:
  g++ -std=c++17 03_std_namespace.cpp -o run
  ./run

Windows(MinGW):
  g++ -std=c++17 03_std_namespace.cpp -o run.exe
  run.exe
*/
