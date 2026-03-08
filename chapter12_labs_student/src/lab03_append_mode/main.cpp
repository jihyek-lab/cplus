#include <iostream>
#include <fstream>
using namespace std;

/*
[Lab03] 파일 모드: ios::app (append)
------------------------------------------------------------
핵심
- ios::app: 항상 파일 끝에 덧붙여 쓴다.
- 기존 내용을 유지하며 로그/기록 추가에 사용.
------------------------------------------------------------
*/

int main() {
    ofstream fout("./data/student.txt", ios::out | ios::app);
    if(!fout) {
        cout << "파일 열기 실패\n";
        return 0;
    }

    fout << "tel:010-0000-0000\n";
    fout.close();
    cout << "append 완료\n";
}
