#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
[Lab14] map iterator로 전체 출력
------------------------------------------------------------
핵심
- map<K,V>::iterator it
- it->first (키), it->second (값)
- make_pair(a, b)는 (키, 값) pair를 만들어 insert()에 넘길 때 자주 사용

기본 이론
- map의 각 원소는 pair 형태이므로 iterator로 가리키면
  `it->first`는 key, `it->second`는 value가 된다.
- map은 key 기준으로 정렬되어 있으므로 출력 순서도 key 순서가 된다.

이론 연결
- map도 begin(), end()를 통해 전체 순회할 수 있다.
- iterator에서 `it->first`는 키, `it->second`는 값이라는 쌍(pair) 구조를 기억하면 된다.
------------------------------------------------------------
*/

void printMap(map<string,int>& m) {
    for(map<string,int>::iterator it=m.begin(); it!=m.end(); it++) {
        cout << it->first << ":" << it->second << "원\n";
    }
}

int main() {
    map<string,int> priceMap;
    priceMap["붕어빵"] = 2000;
    priceMap["잉어빵"] = 2500;
    // ("국화빵", 3000) 한 쌍을 만들어 map에 삽입
    priceMap.insert(make_pair("국화빵", 3000));

    printMap(priceMap);
    cout << "\n";
    priceMap.erase("붕어빵");
    printMap(priceMap);
}
