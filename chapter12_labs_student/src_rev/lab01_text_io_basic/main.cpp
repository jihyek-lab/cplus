#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
[Lab01] 텍스트 파일 입출력 기본
------------------------------------------------------------
문제 설명
1) 키보드 입력을 텍스트 파일에 저장한다.
2) 같은 파일을 다시 읽어 출력한다.
3) append 모드로 파일 끝에 추가한다.
------------------------------------------------------------
핵심 요약
- ofstream/ifstream으로 텍스트 파일을 연다.
- << / >> 연산자는 공백 기준 토큰을 처리한다.
- ios::app는 항상 파일 끝에 덧붙인다.
------------------------------------------------------------
주의 포인트
- ./data 폴더가 없으면 파일 생성 실패 가능.
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
    if(!fout) { cout << "파일 열기 실패\n"; return 0; }
    fout << name << '\n' << sid << '\n' << dept << '\n';
    fout.close();

    ifstream fin("./data/student.txt");
    if(!fin) { cout << "파일 열기 실패\n"; return 0; }
    fin >> name >> sid >> dept;
    cout << name << "\n" << sid << "\n" << dept << "\n";
    fin.close();

    ofstream fapp("./data/student.txt", ios::out | ios::app);
    if(!fapp) { cout << "파일 열기 실패\n"; return 0; }
    fapp << "tel:010-0000-0000\n";
    fapp.close();

    cout << "append 완료\n";
}
