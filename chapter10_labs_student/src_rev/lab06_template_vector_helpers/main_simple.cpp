#include <iostream>
#include <vector>
using namespace std;

/*
[Lab06 Simple] scores만 사용하는 일반 함수 버전
------------------------------------------------------------
문제 상황
- 한 반의 시험 점수 목록에서 최고 점수를 찾고 싶다.
- 아직 템플릿은 쓰지 않고, int 점수 전용 함수로 먼저 생각해 본다.

문제 설명
1) vector<int>에 시험 점수를 저장한다.
2) 일반 함수 printScores(), getMaxScore()를 사용한다.
3) 이 코드를 본 뒤 main.cpp의 템플릿 버전과 비교해 본다.

비교 포인트
- 이 파일은 int 점수 전용 코드다.
- 나중에 string 이름 목록까지 처리하려면 함수를 새로 만들거나 코드를 복사해야 한다.
- main.cpp는 이 중복을 템플릿으로 일반화한 버전이다.
------------------------------------------------------------
*/

void printScores(const vector<int>& scores, const string& title) {
    cout << title;

    for (vector<int>::const_iterator it = scores.begin(); it != scores.end(); ++it) {
        cout << *it << ' ';
    }
    cout << "\n";
}

int getMaxScore(const vector<int>& scores) {
    int maxScore = scores.at(0);

    for (vector<int>::const_iterator it = scores.begin() + 1; it != scores.end(); ++it) {
        if (maxScore < *it) {
            maxScore = *it;
        }
    }

    return maxScore;
}

int main() {
    vector<int> scores;
    scores.push_back(88);
    scores.push_back(75);
    scores.push_back(92);
    scores.push_back(81);

    printScores(scores, "시험 점수: ");
    cout << "최고 점수: " << getMaxScore(scores) << "\n";
}
