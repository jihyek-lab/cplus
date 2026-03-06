#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
[Lab12] map으로 영한 사전
------------------------------------------------------------
핵심
- map<K,V>는 키로 값을 찾는 자료구조(정렬된 트리 기반)
- find(key)==end()면 없음
- operator[]는 "없으면 삽입"할 수 있음 -> 조회용이라면 주의

실습
- exit 입력 시 종료
------------------------------------------------------------
*/

int main() {
    map<string,string> dic;
    dic.insert(make_pair("love","사랑"));
    dic.insert(make_pair("apple","사과"));
    dic["cherry"] = "체리";

    cout << "저장된 단어 개수 " << dic.size() << "\n";

    string eng;
    while(true){
        cout << "찾고 싶은 단어>> ";
        getline(cin, eng);
        if(eng=="exit") break;

        if(dic.find(eng)==dic.end()) cout << "없음\n";
        else cout << dic[eng] << "\n"; // 여기서 []는 존재할 때만 안전
    }
    cout << "종료합니다...\n";
}
