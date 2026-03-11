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

/* trace trap은 프로그램이 실행 도중 SIGTRAP(트랩/브레이크포인트) 신호를 받아서 중단됐다는 뜻입니다.
./run은 실행 파일 이름. 즉, 이 바이너리가 실행되다가 
(디버거 브레이크포인트, 잘못된 메모리 접근, 비정상적 __builtin_trap 등으로) 트랩을 당함.*/


int main() {
    // (A) 동적 할당이 아닌 메모리를 delete 하면 안 됨
    int n = 0;
    int* p1 = &n;
    // delete p1; // (금지)

    // (B) 같은 메모리를 두 번 delete 하면 안 됨
    int* p2 = new int(10);
    delete p2;
  //  p2 = nullptr; // 안전을 위해 nullptr로 설정
    //  delete p2; // (금지)

    cout << "Done\n";
    return 0;
}


