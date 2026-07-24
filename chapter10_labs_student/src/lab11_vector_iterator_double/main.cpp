#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
[Lab11] vector iterator를 표준 패턴으로 읽고, 수정하고, 출력하기
------------------------------------------------------------
학습 목표
- vector<int>::iterator : 원소를 읽고 수정할 수 있는 반복자
- vector<int>::const_iterator : 원소를 읽기만 하는 반복자
- begin()은 첫 원소, end()는 "마지막 원소의 다음 위치"
- 표준 순회 패턴: for(it = begin(); it != end(); ++it)
- *it 로 현재 원소에 접근한다

왜 중요한가?
- iterator는 vector, map, algorithm(sort 등)을 이어 주는 공통 문법이다.
- 배열 인덱스와 달리 "컨테이너 종류가 달라도 비슷한 방식"으로 순회할 수 있다.

주의
- end()가 가리키는 위치는 실제 원소가 아니므로 *v.end() 는 하면 안 된다.
- 값을 바꿀 때는 iterator, 읽기만 할 때는 const_iterator를 구분해 보자.
------------------------------------------------------------
*/

void printVector(const vector<int>& v, const string& title) {
    cout << title;

    for(vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << ' ';
    }
    cout << "\n";
}

int sumVector(const vector<int>& v) {
    int sum = 0;

    for(vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
        sum += *it;
    }

    return sum;
}

void doubleElements(vector<int>& v) {
    cout << "[값을 2배로 바꾸는 과정]\n";

    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << "현재 원소 " << *it;
        *it *= 2;
        cout << " -> 변경 후 " << *it << "\n";
    }
}

int main() {
    vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(10);
    numbers.push_back(15);
    numbers.push_back(20);

    cout << "첫 번째 원소: " << *numbers.begin() << "\n";
    cout << "end()는 마지막 다음 위치이므로 출력에 직접 사용하지 않는다.\n\n";

    printVector(numbers, "초기 벡터: ");
    cout << "초기 합계: " << sumVector(numbers) << "\n\n";

    doubleElements(numbers);
    cout << "\n";

    printVector(numbers, "2배 변경 후: ");
    cout << "변경 후 합계: " << sumVector(numbers) << "\n";
}
