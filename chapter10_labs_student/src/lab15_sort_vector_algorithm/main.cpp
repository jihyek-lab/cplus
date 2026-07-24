#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/*
[Lab15] STL 알고리즘 sort(begin,end)
------------------------------------------------------------
핵심
- sort는 <algorithm> 헤더의 전역 함수 템플릿
- sort(v.begin(), v.end())에서 end는 "마지막 다음" (반열린구간 [begin,end))
- 기본은 오름차순(원소의 operator< 사용)
- sort(v.begin(), v.end(), greater<int>())는 내림차순 정렬

확장
- 비교자를 주면 정렬 기준을 바꿀 수 있다.

이론 연결
- sort는 컨테이너의 멤버 함수가 아니라 반복자 범위를 받는 알고리즘 함수다.
- 그래서 vector뿐 아니라 비슷한 iterator 범위를 제공하는 다른 컨테이너와도 연결된다.
------------------------------------------------------------
*/

int main() {
    vector<int> v;
    cout << "5개의 정수를 입력하세요>> ";
    for(int i=0;i<5;i++){
        int n; cin >> n;
        v.push_back(n);
    }

    // 기본 sort는 오름차순 정렬
    sort(v.begin(), v.end());
    cout << "오름차순: ";
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)
        cout << *it << ' ';
    cout << "\n";

    // greater<int>() 비교자를 주면 내림차순 정렬
    sort(v.begin(), v.end(), greater<int>());
    cout << "내림차순: ";
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)
        cout << *it << ' ';
    cout << "\n";
}
