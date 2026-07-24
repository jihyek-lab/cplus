#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
[Lab12 Revised] map 사전 + find()로 안전하게 조회하기
------------------------------------------------------------
학습 목표
- map<K,V>는 "키 -> 값" 형태의 자료구조다.
- find()는 키 존재 여부를 안전하게 확인한다.
- operator[]는 편리하지만, 없는 키를 읽으면 새 원소가 생길 수 있으므로
  조회 전용 상황에서는 find() 습관이 중요하다.

핵심 정리
- dic.insert(make_pair(key, value)) : 삽입
- dic[key] = value                  : 삽입 또는 수정
- dic.find(key)                     : 있으면 iterator, 없으면 end()

이론 연결
- map도 템플릿 클래스이므로 키 타입과 값 타입을 함께 지정한다.
- 사전, 전화번호부, 상품명-가격처럼 "이름표로 찾는 문제"에 잘 맞는다.
------------------------------------------------------------
*/

void printDictionary(const map<string, string>& dic) {
    cout << "[현재 사전 목록]\n";

    for (map<string, string>::const_iterator it = dic.begin(); it != dic.end(); ++it) {
        cout << it->first << " -> " << it->second << "\n";
    }
    cout << "\n";
}

void searchWord(const map<string, string>& dic, const string& eng) {
    map<string, string>::const_iterator it = dic.find(eng);

    if (it == dic.end()) {
        cout << eng << " : 없음\n";
    } else {
        // find()가 돌려준 iterator를 그대로 사용하면 불필요한 삽입을 피할 수 있다.
        cout << eng << " : " << it->second << "\n";
    }
}

int main() {
    map<string, string> dic;

    dic.insert(make_pair("love", "사랑"));
    dic.insert(make_pair("apple", "사과"));
    dic["cherry"] = "체리";
    dic["school"] = "학교";

    cout << "저장된 단어 개수: " << dic.size() << "\n\n";
    printDictionary(dic);

    string eng;
    while (true) {
        cout << "찾고 싶은 단어(exit 입력 시 종료)>> ";
        getline(cin, eng);

        if (eng == "exit") {
            break;
        }

        searchWord(dic, eng);
    }

    cout << "종료합니다...\n";
}
