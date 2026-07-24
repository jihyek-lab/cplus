#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
[Lab13] map<string, Item> 재고 관리
------------------------------------------------------------
핵심
- map의 value를 객체로 두면 작은 DB처럼 동작
- map 원소 하나는 (상품명, Item 객체) 한 쌍(pair)이다.
- key인 상품명은 중복될 수 없고, key 기준으로 정렬된다.
- 즉, "상품명으로 Item 정보를 찾는 구조"라고 보면 된다.
- erase(key)는 삭제 성공 여부를 0/1로 반환
- 조회할 때 stock[name]는 없으면 기본 Item 생성 -> find 습관 권장
- make_pair(name, Item(...))는 상품명과 Item 객체를 하나의 pair로 묶어
  insert()에 넘길 때 사용

주의
- 이 예제는 cin만 쓰므로 공백 포함 상품명 입력은 안 됨(확장 과제 가능)

이론 연결
- map의 값은 기본 타입일 수도 있고 사용자 정의 객체일 수도 있다.
- 그래서 map은 "키 -> 하나의 복합 정보"를 저장하는 데 매우 유용하다.
------------------------------------------------------------
*/

class Item {
public:
    int price;
    int count;
    Item(int price=0,int count=0):price(price),count(count){}
};

int main() {
    map<string, Item> stock;

    while(true) {
        cout << "상품 입고:1, 검색:2, 삭제:3, 종료:4>>";
        int menu;
        cin >> menu;

        string name;
        int price=0, count=0;

        switch(menu) {
        case 1:
            cout << "상품명, 가격, 개수 입력>>";
            cin >> name >> price >> count;
            // map에 넣을 때는 (키, 값) 형태의 한 쌍이 필요하다.
            stock.insert(make_pair(name, Item(price, count)));
            break;
        case 2:
            cout << "상품명 입력>>";
            cin >> name;
            if(stock.find(name)==stock.end())
                cout << name << " 없음\n";
            else {
                Item item = stock[name];
                cout << "가격 " << item.price << ", 재고 " << item.count << "개\n";
            }
            break;
        case 3: {
            cout << "상품명 입력>>";
            cin >> name;
            int removed = stock.erase(name);
            if(removed==0) cout << name << " 없음\n";
            else cout << name << " 삭제 완료\n";
            break;
        }
        case 4:
            cout << "종료합니다...\n";
            return 0;
        }
    }
}
