/*
 * 실습용 starter code
 * 문제: vector와 객체 포인터 관리
 *
 * 학생용 가이드:
 * - README.md 에 문제 설명과 체크리스트가 정리되어 있습니다.
 * - 아래 코드의 TODO 위치를 중심으로 구현을 진행하세요.
 * - 필요하면 main 함수는 그대로 두고, 클래스/함수 구현만 채워 넣는 방식으로 연습해 보세요.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Circle {
    string name;
    int radius;
public:
    Circle(int radius, string name) {
        this->radius = radius;
        this->name = name;
    }
    double getArea() { return 3.14*radius*radius; }
    string getName() { return name; }
};
class CircleVectorManager {
    vector<Circle*> v;
    void add();
    void remove();
    void show();
public:
    CircleVectorManager() { }
    ~CircleVectorManager() { }
    void run();
};
// TODO:
// add, remove, show 를 구현하세요.
// 특히 remove 와 소멸자에서는 delete 를 호출해 동적 메모리를 해제하는 습관을 들여 보세요.
void CircleVectorManager::run() {
    while(true) {
        int menu;
        cin >> menu;
        switch(menu) {
            case 1: //add
            add(); break;
            case 2: // remove;
            remove(); break;
            case 3: // paint
            show(); break;
            case 4: // end
            return;
            default:
            break;
        }
    }
}
int main() {
    CircleVectorManager cvm;
    cvm.run();
}
