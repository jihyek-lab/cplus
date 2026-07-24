#include <iostream>
#include <vector>
using namespace std;

/*
[Lab09] vector<int> 기본
------------------------------------------------------------
핵심
- push_back: 끝에 추가
- size: 원소 개수
- v[i] : 빠르지만 범위 체크 없음
- v.at(i): 범위 체크(잘못되면 예외 가능)

관찰
- v[0]=10 같은 수정 가능

이론 연결
- vector도 템플릿 클래스이므로 원소 타입을 angle bracket 안에 적는다.
- 배열과 달리 크기가 자동으로 늘어나므로 "가변 크기 배열"처럼 사용할 수 있다.
------------------------------------------------------------
*/

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int i=0;i<(int)v.size();i++) cout << v[i] << " ";
    cout << "\n";

    v[0] = 10;
    v.at(2) = 5;

    for(int i=0;i<(int)v.size();i++) cout << v[i] << " ";
    cout << "\n";
}
