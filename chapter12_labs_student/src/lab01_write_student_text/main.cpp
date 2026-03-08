#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
[Lab01] 키보드 입력 -> 텍스트 파일 저장(<<)
------------------------------------------------------------
핵심
- ofstream fout("./data/student.txt");
- if(!fout) 로 open 실패 검사
- << 로 쓰면 "텍스트"로 저장됨(사람이 읽을 수 있음)

주의
- ./data 폴더가 없으면 파일 생성 실패할 수 있음.
  (이 패키지에는 data 폴더가 포함되어 있음)
------------------------------------------------------------
*/

int main() {
    string name, dept;
    int sid;

    cout << "이름>> ";
    cin >> name;
    cout << "학번>> ";
    cin >> sid;
    cout << "학과>> ";
    cin >> dept;

    ofstream fout("./data/student.txt");
    if(!fout) {
        cout << "파일 열기 실패\n";
        return 0;
    }

    fout << name << '\n';
    fout << sid  << '\n';
    fout << dept << '\n';
    fout.close();

    cout << "저장 완료: ./data/student.txt\n";
}
