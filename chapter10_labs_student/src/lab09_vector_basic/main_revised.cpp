#include <iostream>
#include <vector>
using namespace std;

/*
[Lab09 Revised] vector 기본 + 자주 쓰는 멤버 함수
------------------------------------------------------------
학습 목표
- vector는 크기가 자동으로 늘어나는 배열이다.
- push_back(), size(), empty(), front(), back()을 익힌다.
- [] 와 at() 모두 원소 접근/수정에 쓸 수 있지만 성격이 다르다.

핵심 정리
- empty() : 비어 있으면 true
- front() : 첫 원소
- back()  : 마지막 원소
- v[i]    : 빠르지만 범위 검사 없음
- v.at(i) : 범위 검사를 하는 접근 방식

이론 연결
- vector도 템플릿 클래스이므로 vector<int>, vector<string>처럼
  원소 타입만 바꾸어 같은 구조를 재사용한다.
------------------------------------------------------------
*/

void printVector(const vector<int>& v, const string& title) {
    cout << title;

    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << ' ';
    }
    cout << "\n";
}

int main() {
    vector<int> v;

    cout << "처음에는 비어 있는가? " << (v.empty() ? "yes" : "no") << "\n";

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    cout << "원소 개수: " << v.size() << "\n";
    cout << "첫 원소(front): " << v.front() << "\n";
    cout << "마지막 원소(back): " << v.back() << "\n";
    printVector(v, "초기 벡터: ");

    // []는 인덱스로 빠르게 접근할 수 있다.
    v[0] = 100;

    // at()는 범위를 확인하는 접근 방식이다.
    v.at(2) = 300;

    printVector(v, "수정 후 벡터: ");
    cout << "다시 비어 있는가? " << (v.empty() ? "yes" : "no") << "\n";
}
