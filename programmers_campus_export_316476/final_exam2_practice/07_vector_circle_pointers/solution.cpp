/*
 * Reference solution
 * 문제 7: 객체 포인터를 vector에 삽입, 삭제
 *
 * 문제 요약:
 * - vector<Circle*> 에 원 객체를 동적 할당해 저장한다.
 * - add, remove, show 를 구현하고, 소멸자에서 메모리도 정리한다.
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

    double getArea() { return 3.14 * radius * radius; }
    string getName() { return name; }
};

class CircleVectorManager {
    vector<Circle *> v;
    void add();
    void remove();
    void show();

public:
    CircleVectorManager() {}
    ~CircleVectorManager();
    void run();
};

CircleVectorManager::~CircleVectorManager() {
    // vector 안에 남아 있는 모든 Circle 객체를 해제한다.
    for (vector<Circle *>::iterator it = v.begin(); it != v.end(); ++it) {
        delete *it;
    }
}

void CircleVectorManager::add() {
    int radius;
    string name;
    cin >> radius >> name;
    v.push_back(new Circle(radius, name));
}

void CircleVectorManager::remove() {
    string name;
    cin >> name;

    // erase 이후에는 새 iterator가 반환되므로 그 값을 다시 사용한다.
    for (vector<Circle *>::iterator it = v.begin(); it != v.end();) {
        if ((*it)->getName() == name) {
            delete *it;
            it = v.erase(it);
        } else {
            ++it;
        }
    }
}

void CircleVectorManager::show() {
    for (vector<Circle *>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << (*it)->getName() << " " << (*it)->getArea() << endl;
    }
}

void CircleVectorManager::run() {
    while (true) {
        int menu;
        cin >> menu;
        switch (menu) {
            case 1:
                add();
                break;
            case 2:
                remove();
                break;
            case 3:
                show();
                break;
            case 4:
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
