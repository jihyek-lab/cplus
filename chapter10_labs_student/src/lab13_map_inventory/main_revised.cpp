#include <iostream>
#include <string>
#include <map>
using namespace std;

/*
[Lab13 Revised] map<string, Item> 재고 관리 보강판
------------------------------------------------------------
학습 목표
- map의 value를 객체로 두면 "키 -> 복합 정보"를 저장할 수 있다.
- find()로 검색하고, iterator를 통해 값을 안전하게 읽는다.
- 같은 상품이 다시 들어오면 새로 insert만 하는 것이 아니라,
  기존 재고를 갱신하는 흐름도 생각해야 한다.

핵심 정리
- map 원소 하나는 (key, value) 한 쌍(pair)이다.
- 여기서는 key가 상품명이고, value가 가격과 재고를 담은 Item 객체다.
- key는 중복될 수 없으므로 같은 상품명은 하나의 항목으로 관리된다.
- insert()는 새 키 추가에 적합하다.
- 이미 있는 상품을 갱신하려면 find() 후 second를 수정하는 방식이 자연스럽다.
- erase(key)는 삭제된 원소 개수를 반환한다.

make_pair 설명
- map 원소 하나는 (상품명, Item 객체) 한 쌍(pair)이다.
- make_pair(name, Item(...))는 이 두 값을 하나로 묶어서 insert()에 전달한다.
- 즉, "키와 값이 함께 들어 있는 한 묶음"을 만들 때 쓰는 함수다.
------------------------------------------------------------
*/

class Item {
public:
    int price;
    int count;

    Item(int price = 0, int count = 0) : price(price), count(count) {}
};

void printInventory(const map<string, Item>& stock) {
    cout << "\n[현재 재고 목록]\n";

    if (stock.empty()) {
        cout << "비어 있습니다.\n\n";
        return;
    }

    for (map<string, Item>::const_iterator it = stock.begin(); it != stock.end(); ++it) {
        cout << it->first
             << " : 가격 " << it->second.price
             << ", 재고 " << it->second.count << "개\n";
    }
    cout << "\n";
}

void addOrUpdateItem(map<string, Item>& stock, const string& name, int price, int count) {
    map<string, Item>::iterator it = stock.find(name);

    if (it == stock.end()) {
        // 새 상품이면 (상품명, Item 객체) pair를 만들어 map에 삽입한다.
        stock.insert(make_pair(name, Item(price, count)));
        cout << name << " 새 상품 등록 완료\n";
    } else {
        // 이미 있는 상품이면 가격을 최신값으로 바꾸고 재고를 누적한다.
        it->second.price = price;
        it->second.count += count;
        cout << name << " 기존 상품 갱신 완료\n";
    }
}

void searchItem(const map<string, Item>& stock, const string& name) {
    map<string, Item>::const_iterator it = stock.find(name);

    if (it == stock.end()) {
        cout << name << " 없음\n";
    } else {
        cout << "가격 " << it->second.price
             << ", 재고 " << it->second.count << "개\n";
    }
}

int main() {
    map<string, Item> stock;

    while (true) {
        cout << "입고:1, 검색:2, 삭제:3, 전체출력:4, 종료:5>>";
        int menu;
        cin >> menu;

        string name;
        int price = 0;
        int count = 0;

        switch (menu) {
        case 1:
            cout << "상품명, 가격, 개수 입력>>";
            cin >> name >> price >> count;
            addOrUpdateItem(stock, name, price, count);
            break;
        case 2:
            cout << "상품명 입력>>";
            cin >> name;
            searchItem(stock, name);
            break;
        case 3: {
            cout << "상품명 입력>>";
            cin >> name;

            int removed = stock.erase(name);
            if (removed == 0) {
                cout << name << " 없음\n";
            } else {
                cout << name << " 삭제 완료\n";
            }
            break;
        }
        case 4:
            printInventory(stock);
            break;
        case 5:
            cout << "종료합니다...\n";
            return 0;
        default:
            cout << "메뉴를 다시 입력하세요.\n";
        }
    }
}
