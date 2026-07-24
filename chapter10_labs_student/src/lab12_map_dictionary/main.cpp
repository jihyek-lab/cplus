#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
[Lab12] map으로 영한 사전
------------------------------------------------------------
1. map 기본 이론
- map<K,V>는 key와 value를 한 쌍으로 저장하는 컨테이너다.
- map 원소 하나는 pair 구조이며, (key, value) 형태라고 생각하면 된다.
- key는 중복될 수 없고, key 기준으로 자동 정렬된다.
- 배열처럼 숫자 위치로 찾는 것이 아니라 "이름표 역할의 key"로 값을 찾는다.
- `map<string,string>`이면 key와 value가 모두 string이다.
- 이 예제에서는 영어 단어가 key, 한글 뜻이 value다.

2. map에서 자주 보는 기본 문법
- `dic[key] = value` : 삽입 또는 수정
- `dic.find(key)` : key가 있으면 iterator, 없으면 end()
- `dic.size()` : 저장된 key-value 쌍의 개수
- `dic.begin()`, `dic.end()` : 전체 원소 순회 범위

3. pair와 make_pair
- map 원소가 (key, value) 한 쌍이므로 insert()에도 이런 한 쌍이 필요하다.
- `make_pair(a, b)`는 두 값을 하나의 pair 객체로 만들어 주는 표준 함수다.
- 예: `make_pair("love", "사랑")`
- 즉, "love"와 "사랑"을 하나로 묶어서 map에 넣기 좋게 만드는 함수라고 보면 된다.

4. operator[]를 조회용으로 쓸 때 주의할 점
- `dic[key]`는 단순 조회 전용 문법이 아니다.
- 없는 key를 읽으면 새 원소가 자동으로 삽입될 수 있다.
- 그래서 존재 여부만 확인하거나 안전하게 조회하고 싶을 때는 find()를 먼저 쓰는 습관이 좋다.

5. 이 예제에서 하는 일
- 영한 사전을 map으로 만든다.
- 몇 개의 단어를 저장한다.
- iterator로 전체 목록을 출력한다.
- 사용자가 입력한 영어 단어를 찾아 뜻을 출력한다.
- exit를 입력하면 종료한다.
------------------------------------------------------------
*/

int main() {
    map<string,string> dic;

    // (영어, 뜻) 한 쌍을 만들어 map에 저장한다.
    dic.insert(make_pair("love","사랑"));
    dic.insert(make_pair("apple","사과"));

    // []는 pair를 직접 만들지 않고도 삽입/수정을 간단히 표현할 수 있다.
    dic["cherry"] = "체리";

    cout << "저장된 단어 개수 " << dic.size() << "\n";

    // iterator로 map 전체를 순회한다.
    cout << "[현재 사전 목록]\n";
    for(map<string,string>::iterator it = dic.begin(); it != dic.end(); ++it) {
        // map 원소는 pair이므로 key는 first, value는 second로 꺼낸다.
        cout << it->first << " : " << it->second << "\n";
    }
    cout << "\n";

    string eng;
    while(true){
        cout << "찾고 싶은 단어>> ";
        getline(cin, eng);
        if(eng=="exit") break;

        // 조회만 할 때는 find()로 먼저 확인하는 방식이 안전하다.
        if(dic.find(eng)==dic.end()) cout << "없음\n";
        else cout << dic[eng] << "\n"; // 여기서 []는 존재할 때만 안전
    }
    cout << "종료합니다...\n";
}
