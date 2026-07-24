/*
 * 실습용 starter code
 * 문제: 상속과 protected 멤버 활용
 *
 * 학생용 가이드:
 * - README.md 에 문제 설명과 체크리스트가 정리되어 있습니다.
 * - 아래 코드의 TODO 위치를 중심으로 구현을 진행하세요.
 * - 필요하면 main 함수는 그대로 두고, 클래스/함수 구현만 채워 넣는 방식으로 연습해 보세요.
 */

#include <iostream>
using namespace std;
class BaseArray {
private:
    int capacity; // 동적 할당된 메모리 용량
    int *mem; // 동적 할당된 배열
protected:
    BaseArray(int capacity=10) {
        // capacity 크기의 동적 메모리 할당
        this->capacity = capacity; mem = new int [capacity];
    }
    ~BaseArray() { delete [] mem; }
    void put(int index, int val) { mem[index] = val; }
    int get(int index) { return mem[index]; }
    int getCapacity() { return capacity; }
};
class MyQueue : public BaseArray {
    int head, tail;
    int size; // 현재 큐 안에 있는 데이터의 개수
public:
    MyQueue(int capacity);
    void enqueue(int n);
    int dequeue();
    int capacity();
    int length();
};
// TODO:
// MyQueue 생성자와 멤버 함수를 구현하세요.
// head 는 dequeue 위치, tail 은 enqueue 위치, size 는 현재 원소 수를 의미하도록 두면 구현이 단순해집니다.
int main() {
    MyQueue mQ(10);
    int n;
    int input;
    string cmd;
    cin >> n; // 명령의 갯수 입력
    for (int i=0; i<n; i++) {
        cin >> cmd; // 명령 입력
        if (cmd == "enqueue") {
            cin >> input; // 데이터 입력
            mQ.enqueue(input); // 큐 객체에 데이터 추가
        }
        else if (cmd == "dequeue") {
            cout << mQ.dequeue() << endl; // 큐 객체의 가장 먼저 저장된 원소를 꺼냄
        }
        else if (cmd == "length") {
            cout << mQ.length() << endl; // 큐의 길이
        }
        else if (cmd == "capacity") {
            cout << mQ.capacity() << endl; // 큐의 동적 배열의 크기
        }
    }
}
