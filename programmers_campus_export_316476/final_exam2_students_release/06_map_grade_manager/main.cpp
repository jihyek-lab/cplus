/*
 * 실습용 starter code
 * 문제: map 컨테이너 활용
 *
 * 학생용 가이드:
 * - README.md 에 문제 설명과 체크리스트가 정리되어 있습니다.
 * - 아래 코드의 TODO 위치를 중심으로 구현을 진행하세요.
 * - 필요하면 main 함수는 그대로 두고, 클래스/함수 구현만 채워 넣는 방식으로 연습해 보세요.
 */

#include <iostream>
#include <string>
#include <map>
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
    // TODO
    // name이 이미 map에 있는 경우
    // cout << name << " already exists" << endl;
    // return;
    //
    // 맵에 없는 사람이 입력된 경우, 맵에 저장
}
void GradeManager::search() {
    string name;
    cin >> name;
    // TODO
    // name을 맵에서 찾을 수 없을 경우
    // cout << name << " doesn't exist" << endl;
    //
    // 있는 경우
    // cout << name << ": " << score << endl;
}
void GradeManager::run() {
    int menu;
    while (true) {
        cin >> menu;
        switch (menu) {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: return; // end
        }
    }
}
int main() {
    GradeManager gm = GradeManager();
    gm.run();
}
