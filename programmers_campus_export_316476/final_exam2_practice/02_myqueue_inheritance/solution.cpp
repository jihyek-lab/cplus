/*
 * Reference solution
 * 문제 2: 상속과 protected, 파생 클래스(큐)
 *
 * 문제 요약:
 * - BaseArray 를 상속한 MyQueue 를 구현한다.
 * - enqueue, dequeue, capacity, length 를 작성한다.
 * - 원형 큐 방식으로 head, tail, size 를 관리한다.
 */

#include <iostream>
using namespace std;

class BaseArray {
private:
    int capacity;
    int *mem;

protected:
    BaseArray(int capacity = 10) {
        this->capacity = capacity;
        mem = new int[capacity];
    }
    ~BaseArray() { delete[] mem; }
    void put(int index, int val) { mem[index] = val; }
    int get(int index) { return mem[index]; }
    int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray {
    int head, tail;
    int size;

public:
    MyQueue(int capacity);
    void enqueue(int n);
    int dequeue();
    int capacity();
    int length();
};

MyQueue::MyQueue(int capacity)
    : BaseArray(capacity), head(0), tail(0), size(0) {}

void MyQueue::enqueue(int n) {
    // 가득 찼으면 아무 일도 하지 않는다.
    if (size == getCapacity()) {
        return;
    }
    put(tail, n);
    // 원형 큐이므로 끝까지 가면 다시 0으로 순환한다.
    tail = (tail + 1) % getCapacity();
    size++;
}

int MyQueue::dequeue() {
    if (size == 0) {
        return -1;
    }
    int value = get(head);
    head = (head + 1) % getCapacity();
    size--;
    return value;
}

int MyQueue::capacity() { return getCapacity(); }

int MyQueue::length() { return size; }

int main() {
    MyQueue mQ(10);
    int n;
    int input;
    string cmd;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        if (cmd == "enqueue") {
            cin >> input;
            mQ.enqueue(input);
        } else if (cmd == "dequeue") {
            cout << mQ.dequeue() << endl;
        } else if (cmd == "length") {
            cout << mQ.length() << endl;
        } else if (cmd == "capacity") {
            cout << mQ.capacity() << endl;
        }
    }
}
