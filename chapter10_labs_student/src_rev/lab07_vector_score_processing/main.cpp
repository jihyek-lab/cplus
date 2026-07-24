#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
[Lab07] vector + iterator + sort로 성적 처리하기
------------------------------------------------------------
문제 상황
- 한 반의 시험 점수가 저장되어 있다.
- 선생님은 80점 미만 학생에게 5점의 보너스를 주려고 한다.
- 보너스를 준 뒤 전체 점수를 정렬해서 최저 점수와 최고 점수를 확인하고 싶다.

문제 설명
1) vector에 점수를 저장한다.
2) iterator로 벡터를 순회하며 조건에 따라 점수를 수정한다.
3) sort로 정렬하고, front()/back()으로 최솟값과 최댓값을 확인한다.
------------------------------------------------------------
핵심 요약
- vector는 "가변 크기 배열"처럼 사용한다.
- iterator는 읽기뿐 아니라 값 수정에도 쓸 수 있다.
- sort(begin, end)는 vector 전체를 정렬하는 표준 패턴이다.
------------------------------------------------------------
주의 포인트
- end()는 마지막 원소가 아니라 마지막 다음 위치다.
- 값을 바꿀 때는 iterator, 읽기만 할 때는 const_iterator를 구분해 보자.
------------------------------------------------------------
*/

void printScores(const vector<int>& scores, const string& title) {
    cout << title;

    for (vector<int>::const_iterator it = scores.begin(); it != scores.end(); ++it) {
        cout << *it << ' ';
    }
    cout << "\n";
}

int getAverage(const vector<int>& scores) {
    int sum = 0;

    for (vector<int>::const_iterator it = scores.begin(); it != scores.end(); ++it) {
        sum += *it;
    }

    return sum / (int)scores.size();
}

void addBonus(vector<int>& scores, int cutoffScore, int bonusScore) {
    for (vector<int>::iterator it = scores.begin(); it != scores.end(); ++it) {
        if (*it < cutoffScore) {
            *it += bonusScore;
        }
    }
}

int main() {
    // 학생들의 원래 시험 점수 목록
    vector<int> scores;
    scores.push_back(70);
    scores.push_back(82);
    scores.push_back(95);
    scores.push_back(68);
    scores.push_back(87);

    printScores(scores, "원래 점수: ");
    cout << "원래 평균: " << getAverage(scores) << "\n\n";

    // 문제 해결 단계 1:
    // 80점 미만 학생에게 5점 보너스를 준다.
    addBonus(scores, 80, 5);
    printScores(scores, "보너스 후 점수: ");
    cout << "보너스 후 평균: " << getAverage(scores) << "\n\n";

    // 문제 해결 단계 2:
    // 정렬 후 최솟값과 최댓값을 더 쉽게 확인한다.
    sort(scores.begin(), scores.end());
    printScores(scores, "오름차순 정렬: ");
    cout << "최저 점수(front): " << scores.front() << "\n";
    cout << "최고 점수(back): " << scores.back() << "\n";
}
