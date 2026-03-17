#include <iostream>
using namespace std;

/*
[Lab06] 기본 타입 동적 할당 + delete 주의사항
------------------------------------------------------------
핵심
1) int* p = new int;   => 힙(heap)에 int 1개 할당
2) *p = 5;             => 그 공간에 값 저장
3) delete p;           => 반드시 반환(메모리 누수 방지)
4) delete 후 p는 "댕글링 포인터"가 될 수 있어 접근하면 위험.
   (실무 팁: delete 후 p = nullptr; 로 안전하게)
------------------------------------------------------------
*/

int main() {
    int* p = new int; // (1) 동적 할당
    *p = 5;

    cout << "*p = " << *p << "\n";

    delete p;         // (2) 반환
    // cout << *p;     // (금지) delete 후 접근 위험
    p = nullptr;      // (실무 팁) delete 후 포인터를 nullptr로 설정

    // [delete 주의사항]
    // (A) 동적 할당이 아닌 메모리를 delete 하면 안 됨 (정의되지 않은 동작)
    int n = 0;
    int* p1 = &n;
    // delete p1; // (금지)

    // (B) 같은 메모리를 두 번 delete 하면 안 됨 (double free)
    int* p2 = new int(10);
    delete p2;
    // delete p2; // (금지)

    return 0;
}
