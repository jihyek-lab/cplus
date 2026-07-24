#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
[Lab06] 템플릿 함수와 vector를 함께 보기
------------------------------------------------------------
문제 상황
- 어떤 반의 시험 점수 목록에서 최고 점수를 찾고 싶다.
- 또 학생 이름 목록에서 사전순으로 가장 뒤에 오는 이름도 찾고 싶다.
- 두 문제는 "자료의 타입"만 다르고, "목록에서 가장 큰 값을 찾는다"는 작업은 같다.

문제 설명
1) 점수(vector<int>)와 이름(vector<string>)에 같은 함수를 적용해 본다.
2) printVector<T>(), getMax<T>()로 "타입만 다른 같은 작업"을 일반화한다.
3) 템플릿과 vector가 실제로 함께 쓰이는 모습을 확인한다.
------------------------------------------------------------
핵심 요약
- vector도 템플릿 클래스다.
- printVector<T>(), getMax<T>()는 함수 템플릿이다.
- 즉, chapter10은 템플릿과 STL이 따로 노는 장이 아니라 서로 연결되는 장이다.
------------------------------------------------------------
주의 포인트
- getMax<T>()는 > 비교가 가능한 타입에서만 잘 동작한다.
- 이 실습에서는 비어 있지 않은 vector만 사용한다.
------------------------------------------------------------
*/

template <class T>
void printVector(const vector<T>& v, const string& title) {
    cout << title;

    for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << "\n";
}

template <class T>
T getMax(const vector<T>& v) {
    T maxValue = v.at(0);

    for (typename vector<T>::const_iterator it = v.begin() + 1; it != v.end(); ++it) {
        if (maxValue < *it) {
            maxValue = *it;
        }
    }

    return maxValue;
}

int main() {
    // 문제 1: 시험 점수 목록에서 최고 점수를 찾는다.
    vector<int> scores;
    scores.push_back(88);
    scores.push_back(75);
    scores.push_back(92);
    scores.push_back(81);

    printVector(scores, "시험 점수: ");
    cout << "최고 점수: " << getMax(scores) << "\n\n";

    // 문제 2: 이름 목록에서 사전순으로 가장 뒤 이름을 찾는다.
    // string도 < 비교가 가능하므로 같은 getMax()를 그대로 사용할 수 있다.
    vector<string> names;
    names.push_back("Kim");
    names.push_back("Lee");
    names.push_back("Park");
    names.push_back("Choi");

    printVector(names, "학생 이름: ");
    cout << "사전순으로 가장 뒤 이름: " << getMax(names) << "\n";
}
