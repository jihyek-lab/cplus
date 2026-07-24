#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

/*
[Lab15 Revised] sort 알고리즘 확장: 오름차순, 내림차순, 문자열 정렬
------------------------------------------------------------
학습 목표
- sort(begin, end)는 반복자 범위를 받는 알고리즘이다.
- 기본 정렬은 오름차순이며, 원소 타입의 < 비교를 사용한다.
- 비교자를 추가하면 정렬 기준을 바꿀 수 있다.
- 같은 sort라도 vector<int>, vector<string>에 공통으로 적용할 수 있다.

핵심 정리
- sort(v.begin(), v.end()) : 오름차순
- sort(v.begin(), v.end(), greater<int>()) : 내림차순
- 범위 표기는 [begin, end) 이다. end()는 마지막 원소의 다음 위치다.
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

int main() {
    vector<int> numbers;

    cout << "5개의 정수를 입력하세요>> ";
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        numbers.push_back(n);
    }

    printVector(numbers, "입력 순서: ");

    sort(numbers.begin(), numbers.end());
    printVector(numbers, "오름차순 정렬: ");

    sort(numbers.begin(), numbers.end(), greater<int>());
    printVector(numbers, "내림차순 정렬: ");

    cout << "\n";

    vector<string> words;
    words.push_back("peach");
    words.push_back("apple");
    words.push_back("banana");
    words.push_back("grape");

    printVector(words, "문자열 원본: ");
    sort(words.begin(), words.end());
    printVector(words, "문자열 사전순 정렬: ");
}
