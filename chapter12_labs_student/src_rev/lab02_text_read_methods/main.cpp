#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
[Lab02] 텍스트 읽기 방법: get/getline + 검색 + count
------------------------------------------------------------
문제 설명
1) get()로 1바이트씩 읽으며 카운트한다.
2) getline(char*, n)으로 줄 단위 읽기를 한다.
3) getline(string)으로 읽고 검색한다.
------------------------------------------------------------
핵심 요약
- get()은 1바이트씩 읽고 EOF 검사
- getline(char*)은 \n 제거, 버퍼 기반
- getline(string)은 편리하며 string::find로 검색 가능
------------------------------------------------------------
주의 포인트
- 텍스트 모드에서 \r\n 처리로 바이트 수가 달라질 수 있음(Windows)
------------------------------------------------------------
*/

void count_bytes() {
    ifstream fin("./data/sample.txt");
    if(!fin) { cout << "open fail\n"; return; }
    int c, count=0;
    while((c = fin.get()) != EOF) { count++; }
    cout << "count=" << count << "\n";
    fin.close();
}

void read_lines_charbuf() {
    ifstream fin("./data/sample.txt");
    if(!fin) { cout << "open fail\n"; return; }
    char buf[81];
    while(fin.getline(buf, 81)) cout << buf << "\n";
    fin.close();
}

void search_lines_string() {
    ifstream fin("./data/words.txt");
    if(!fin) { cout << "open fail\n"; return; }

    vector<string> lines;
    string line;
    while(getline(fin, line)) lines.push_back(line);
    fin.close();

    cout << "검색어>> ";
    string word;
    getline(cin >> ws, word);

    for(int i=0;i<(int)lines.size();i++)
        if(lines[i].find(word) != string::npos)
            cout << lines[i] << "\n";
}

int main() {
    count_bytes();
    read_lines_charbuf();
    search_lines_string();
}
