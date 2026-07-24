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
- map 원소 하나는 (key, value) 한 쌍(pair)이다.
- key는 중복될 수 없고, key 기준으로 자동 정렬된다.
- map은 배열처럼 "몇 번째 칸"으로 찾는 구조가 아니라,
  "이 key에 대응하는 값이 무엇인가?"를 찾는 구조다.
- dic.insert(make_pair(key, value)) : 삽입
- dic[key] = value                  : 삽입 또는 수정
- dic.find(key)                     : 있으면 iterator, 없으면 end()
- dic.size()                        : 저장된 key-value 쌍의 개수

make_pair 설명
- make_pair(a, b)는 pair 객체를 만들어 주는 표준 함수다.
- map의 한 원소는 사실상 (key, value) 한 쌍(pair)이므로,
  insert()에 넣을 "키-값 묶음"이 필요할 때 make_pair를 자주 사용한다.
- 즉, make_pair("love", "사랑")는
  "love"와 "사랑"을 하나의 쌍으로 묶어서 map에 넣기 좋게 만드는 함수라고 이해하면 된다.

이론 연결
- map도 템플릿 클래스이므로 키 타입과 값 타입을 함께 지정한다.
- 사전, 전화번호부, 상품명-가격처럼 "이름표로 찾는 문제"에 잘 맞는다.
- `map<string, string>`은
  "문자열 key에 문자열 value를 연결하는 표"라고 생각하면 이해하기 쉽다.
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

    // make_pair는 (키, 값) 두 개를 하나의 pair로 묶어 insert()에 전달한다.
    dic.insert(make_pair("love", "사랑"));
    dic.insert(make_pair("apple", "사과"));

    // []는 pair를 직접 만들지 않고도 삽입/수정을 간단히 표현할 수 있다.
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
