#include <iostream>
using namespace std;

/*
[Lab06] 기본 타입 동적 할당: new / delete
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
    
    return 0;
}
