#include <iostream>
#include <cstring> // strcmp
using namespace std;

int main() {
    const char correct[] = "zkrypto123";
    char input[50];

    cout << "Password: ";
    cin >> input; // 공백 없는 입력이라고 가정

    // (1) char[] (C-스트링)은 == 로 내용 비교하면 안 됨!
    //     대부분 경우 주소(포인터) 비교처럼 되어버릴 수 있음
    // (2) strcmp(a, b):
    //     - 0이면 같다
    //     - 음수/양수면 사전식 비교 결과
    if (strcmp(input, correct) == 0) {
        cout << "Access granted.\n";
    } else {
        cout << "Access denied.\n";
    }

    return 0;
}
