#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
[Lab14 Revised] map iterator로 읽기와 수정 구분하기
------------------------------------------------------------
학습 목표
- map도 begin(), end()로 전체 순회할 수 있다.
- 출력만 할 때는 const_iterator를 사용한다.
- 값을 바꿀 때는 iterator를 사용한다.
- map iterator에서 it->first는 키, it->second는 값이다.

중요 포인트
- map의 각 원소는 pair 구조다.
- key(first)는 항목의 이름표 역할을 하고, value(second)는 실제 저장 데이터다.
- map은 key 기준으로 정렬되어 있으므로 순회 결과도 key 순서로 나온다.
- 키(first)는 map의 정렬 기준이므로 함부로 바꾸지 않는다.
- 값(second)은 iterator를 통해 수정할 수 있다.
- make_pair(a, b)는 (키, 값) 한 쌍을 만들어 map.insert()에 넘길 때 자주 쓴다.
------------------------------------------------------------
*/

void printMap(const map<string, int>& m, const string& title) {
    cout << title;

    for (map<string, int>::const_iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ":" << it->second << "원\n";
    }
    cout << "\n";
}

void increasePrices(map<string, int>& m, int amount) {
    cout << "[가격을 " << amount << "원씩 올리는 과정]\n";

    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " : " << it->second;
        it->second += amount;
        cout << " -> " << it->second << "\n";
    }
    cout << "\n";
}

int main() {
    map<string, int> priceMap;
    priceMap["붕어빵"] = 2000;
    priceMap["잉어빵"] = 2500;

    // make_pair("국화빵", 3000)은 ("국화빵", 3000) 한 쌍의 pair를 만든다.
    priceMap.insert(make_pair("국화빵", 3000));

    printMap(priceMap, "[초기 가격표]\n");

    increasePrices(priceMap, 500);

    printMap(priceMap, "[인상 후 가격표]\n");
}
