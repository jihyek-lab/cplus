#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
[Lab02] 텍스트 파일 읽기(>>)
------------------------------------------------------------
핵심
- ifstream fin("./data/student.txt");
- >> 는 공백 기준 토큰 읽기
- 파일이 없으면 open 실패(경로 확인)
------------------------------------------------------------
*/

int main() {
    ifstream fin("./data/student.txt");
    if(!fin) {
        cout << "파일 열기 실패: ./data/student.txt\n";
        return 0;
    }

    string name, dept;
    int sid;

    fin >> name >> sid >> dept;
    cout << name << "\n" << sid << "\n" << dept << "\n";
    fin.close();
}
