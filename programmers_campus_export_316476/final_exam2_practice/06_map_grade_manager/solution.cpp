/*
 * Reference solution
 * 문제 6: map 활용
 *
 * 문제 요약:
 * - map<string, int> 으로 이름과 성적을 저장한다.
 * - insert 는 중복 이름을 막고, search 는 이름으로 점수를 찾는다.
 */

#include <iostream>
#include <map>
#include <string>
using namespace std;

class GradeManager {
    map<string, int> scoreMap;
    void insert();
    void search();

public:
    void run();
};

void GradeManager::insert() {
    string name;
    int score;
    cin >> name >> score;

    // 이미 존재하는 키인지 먼저 확인한다.
    if (scoreMap.find(name) != scoreMap.end()) {
        cout << name << " already exsits" << endl;
        return;
    }

    scoreMap[name] = score;
}

void GradeManager::search() {
    string name;
    cin >> name;

    // find 결과가 end()이면 해당 이름이 없다는 뜻이다.
    map<string, int>::iterator it = scoreMap.find(name);
    if (it == scoreMap.end()) {
        cout << name << " doesn't exist" << endl;
        return;
    }

    cout << name << ": " << it->second << endl;
}

void GradeManager::run() {
    int menu;
    while (true) {
        cin >> menu;
        switch (menu) {
            case 1:
                insert();
                break;
            case 2:
                search();
                break;
            case 3:
                return;
        }
    }
}

int main() {
    GradeManager gm = GradeManager();
    gm.run();
}
