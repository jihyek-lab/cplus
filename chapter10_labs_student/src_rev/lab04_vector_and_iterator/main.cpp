#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
[Lab04] vector 기본 + iterator + 문자열 사전순
------------------------------------------------------------
문제 설명
1) vector<int> 기본 연산을 연습한다.
2) iterator로 순회하며 값을 수정한다.
3) vector<string>에서 사전식 최대값을 찾는다.
------------------------------------------------------------
핵심 요약
- push_back / size / at / []
- iterator는 STL 알고리즘과 결합할 때 중요
- string 비교는 사전식(lexicographical)
------------------------------------------------------------
주의 포인트
- v[i]는 범위 체크 없음, v.at(i)는 범위 체크 있음.
------------------------------------------------------------
*/

int main() {
    // (1) vector<int>
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int i=0;i<(int)v.size();i++) cout << v[i] << " ";
    cout << "\n";

    v[0] = 10;
    v.at(2) = 5;

    // (2) iterator로 값 2배
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)
        *it = (*it) * 2;

    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)
        cout << *it << ' ';
    cout << "\n";

    // (3) vector<string> 사전순
    vector<string> sv;
    string name;
    cout << "이름을 3개 입력하라\n";
    for(int i=0;i<3;i++){
        cout << i+1 << ">>";
        getline(cin >> ws, name);
        sv.push_back(name);
    }

    name = sv.at(0);
    for(int i=1;i<(int)sv.size();i++)
        if(name < sv[i]) name = sv[i];

    cout << "사전에서 가장 뒤에 나오는 이름은 " << name << "\n";
}
