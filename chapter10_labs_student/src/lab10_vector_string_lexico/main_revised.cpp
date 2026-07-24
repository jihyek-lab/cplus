#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
[Lab10 Revised] vector<string> + 템플릿 정렬 함수
------------------------------------------------------------
핵심
- vector<string>를 사전순으로 정렬한다.
- 정렬 자체는 sortVector<T>() 템플릿 함수로 일반화한다.
- 즉, string 전용 정렬이 아니라 "정렬 가능한 타입의 vector"에 재사용 가능하다.

이론 연결
- vector는 템플릿 클래스다: vector<string>, vector<int>처럼 원소 타입만 바뀐다.
- sort는 함수 템플릿이다.
- string은 operator<가 정의되어 있으므로 sort가 사전순 정렬을 수행할 수 있다.
------------------------------------------------------------
*/

template <class T>
void sortVector(vector<T>& v)
{
    // [begin, end) 범위를 오름차순으로 정렬한다.
    sort(v.begin(), v.end());
}

template <class T>
void printVector(const vector<T>& v)
{
    for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << "\n";
    }
}

int main()
{
    vector<string> sv;
    string name;

    cout << "이름을 5개 입력하라\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ">>";
        getline(cin, name);
        sv.push_back(name);
    }

    sortVector(sv);

    cout << "\n[사전순 정렬 결과]\n";
    printVector(sv);

    cout << "\n사전에서 가장 앞 이름: " << sv.front() << "\n";
    cout << "사전에서 가장 뒤 이름: " << sv.back() << "\n";
    return 0;
}
