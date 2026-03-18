#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

/*
[Lab05] map + iterator 출력 + sort 알고리즘
------------------------------------------------------------
문제 설명
1) map으로 사전/재고 관리 기본을 익힌다.
2) iterator로 map 전체를 출력한다.
3) vector를 sort로 정렬한다.
------------------------------------------------------------
핵심 요약
- map<K,V>는 키로 값을 찾는 자료구조(정렬됨)
- map::operator[]는 없으면 삽입하므로 find 사용 습관
- sort는 [begin, end) 반열린 구간 사용
------------------------------------------------------------
주의 포인트
- map의 []는 조회용으로 쓰면 의도치 않은 삽입이 발생할 수 있다.
------------------------------------------------------------
*/

void printMap(map<string,int>& m) {
    for(map<string,int>::iterator it=m.begin(); it!=m.end(); it++)
        cout << it->first << ":" << it->second << "원\n";
}

int main() {
    // (1) map 기본
    map<string,string> dic;
    dic.insert(make_pair("love","사랑"));
    dic["cherry"] = "체리";

    string eng = "love";
    if(dic.find(eng)==dic.end()) cout << "없음\n";
    else cout << dic[eng] << "\n";

    // (2) map<int> 출력
    map<string,int> priceMap;
    priceMap["붕어빵"] = 2000;
    priceMap["잉어빵"] = 2500;
    priceMap.insert(make_pair("국화빵", 3000));
    printMap(priceMap);

    // (3) sort
    vector<int> v;
    v.push_back(5); v.push_back(1); v.push_back(3);
    sort(v.begin(), v.end());
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)
        cout << *it << ' ';
    cout << "\n";
}
