#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

/*
[Lab08] map으로 판매 횟수 집계하기
------------------------------------------------------------
문제 상황
- 하루 동안 팔린 상품 이름이 순서대로 기록되어 있다.
- 가게 주인은 어떤 상품이 몇 번 팔렸는지 집계하고 싶다.
- 또 특정 상품이 실제로 팔렸는지, 몇 번 팔렸는지도 확인하고 싶다.

문제 설명
1) vector에 "판매된 상품 이름 목록"을 저장한다.
2) map<string,int>로 각 상품이 몇 번 팔렸는지 집계한다.
3) find()로 특정 상품의 판매 횟수를 안전하게 조회한다.
------------------------------------------------------------
핵심 요약
- map은 "키 -> 값" 구조다.
- countMap[item]++ 는 없던 키면 0에서 시작해 집계하기 편하다.
- 조회만 할 때는 find()로 확인하는 습관이 좋다.
------------------------------------------------------------
주의 포인트
- []는 삽입/수정에는 매우 편리하다.
- 하지만 단순 조회 상황에서는 없는 키를 만들 수 있으므로 find()가 더 안전하다.
------------------------------------------------------------
*/

void printSales(const map<string, int>& salesCount) {
    cout << "[판매 횟수 집계]\n";

    for (map<string, int>::const_iterator it = salesCount.begin(); it != salesCount.end(); ++it) {
        cout << it->first << " : " << it->second << "회\n";
    }
    cout << "\n";
}

void searchItem(const map<string, int>& salesCount, const string& itemName) {
    map<string, int>::const_iterator it = salesCount.find(itemName);

    if (it == salesCount.end()) {
        cout << itemName << " : 판매 기록 없음\n";
    } else {
        cout << itemName << " : " << it->second << "회 판매됨\n";
    }
}

int main() {
    // 하루 동안 팔린 상품 기록
    vector<string> soldItems;
    soldItems.push_back("apple");
    soldItems.push_back("banana");
    soldItems.push_back("apple");
    soldItems.push_back("milk");
    soldItems.push_back("banana");
    soldItems.push_back("apple");

    map<string, int> salesCount;

    // 문제 해결 단계 1:
    // 판매 기록을 하나씩 보면서 상품별 판매 횟수를 센다.
    for (vector<string>::const_iterator it = soldItems.begin(); it != soldItems.end(); ++it) {
        // []는 "집계"처럼 삽입/수정이 함께 필요한 상황에서 특히 편리하다.
        salesCount[*it]++;
    }

    // 문제 해결 단계 2:
    // 집계 결과를 전체 출력한다.
    printSales(salesCount);

    // 문제 해결 단계 3:
    // 특정 상품의 판매 기록이 있는지 안전하게 조회한다.
    searchItem(salesCount, "apple");
    searchItem(salesCount, "orange");
}
