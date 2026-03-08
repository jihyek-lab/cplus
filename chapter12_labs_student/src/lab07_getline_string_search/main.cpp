#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
[Lab07] getline(fin, string): string 기반 라인 읽기 + 검색
------------------------------------------------------------
핵심
- getline(fin, line) 사용
- vector<string>에 파일을 통째로 읽고
- 사용자 입력 word를 포함하는 라인만 출력

준비
- ./data/words.txt 가 포함되어 있음.
------------------------------------------------------------
*/

static void fileRead(vector<string>& v, ifstream& fin) {
    string line;
    while(getline(fin, line)) v.push_back(line);
}

static void search(const vector<string>& v, const string& word) {
    for(int i=0;i<(int)v.size();i++)
        if(v[i].find(word) != string::npos)
            cout << v[i] << "\n";
}

int main() {
    ifstream fin("./data/words.txt");
    if(!fin) { cout << "open fail\n"; return 0; }

    vector<string> lines;
    fileRead(lines, fin);
    fin.close();

    cout << "words.txt 읽기 완료. exit 입력 시 종료.\n";
    while(true) {
        cout << "검색어>> ";
        string word;
        getline(cin, word);
        if(word=="exit") break;
        search(lines, word);
    }
}
