#include <iostream>
using namespace std;

/*
[Lab08] 템플릿 클래스 MyStack<T>
------------------------------------------------------------
핵심
- class template: template<class T> class MyStack { ... }
- 사용할 때: MyStack<int> / MyStack<double> 처럼 타입을 지정해야 함.
- 멤버 함수에서 T()는 "T의 기본값" 생성(0, false, 빈 string 등).

주의
- pop()에서 빈 스택이면 T() 반환 -> 호출자 입장에선 "에러"와 구분 어려울 수 있음.
  (6장의 average(bool+out param) 같은 패턴 또는 예외/optional 등이 대안)
------------------------------------------------------------
*/

template <class T>
class MyStack {
    int tos;
    T data[100];
public:
    MyStack() : tos(-1) {}
    void push(T element) {
        if(tos == 99) { cout << "stack full\n"; return; }
        data[++tos] = element;
    }
    T pop() {
        if(tos == -1) { cout << "stack empty\n"; return T(); }
        return data[tos--];
    }
};

int main() {
    MyStack<int> iStack;
    iStack.push(3);
    cout << iStack.pop() << "\n";

    MyStack<double> dStack;
    dStack.push(3.5);
    cout << dStack.pop() << "\n";

    MyStack<char>* p = new MyStack<char>();
    p->push('a');
    cout << p->pop() << "\n";
    delete p;
}
