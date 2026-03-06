#include <iostream>
using namespace std;

/*
[Lab07] delete 함정: 동적 할당이 아닌 것 delete 금지 + 중복 delete 금지
------------------------------------------------------------
핵심
1) int n; int* p=&n; delete p;   => 동적 할당이 아니므로 오류(정의되지 않은 동작)
2) 같은 포인터를 두 번 delete => double free(심각한 오류)
------------------------------------------------------------
*/

int main() {
    // (A) 동적 할당이 아닌 메모리를 delete 하면 안 됨
    int n = 0;
    int* p1 = &n;
    // delete p1; // (금지)

    // (B) 같은 메모리를 두 번 delete 하면 안 됨
    int* p2 = new int(10);
    delete p2;
    // delete p2; // (금지)

    cout << "Done\n";
    return 0;
}
