#include <iostream>
#include <vector>
using namespace std;

/*
[Lab11] iterator로 vector 순회하며 값 수정
------------------------------------------------------------
핵심
- vector<int>::iterator it
- it = v.begin(); it != v.end(); it++
- *it 로 원소 접근(읽기/쓰기)

추가
- C++11부터는 range-based for도 가능하지만,
  iterator는 STL 알고리즘과 결합할 때 매우 중요.
------------------------------------------------------------
*/

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)
        *it = (*it) * 2;

    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)
        cout << *it << ' ';
    cout << "\n";
}
