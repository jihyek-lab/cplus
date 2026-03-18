#include <iostream>
using namespace std;

/*
[Lab03] 템플릿 클래스 MyStack<T>
------------------------------------------------------------
문제 설명
1) 템플릿 클래스를 정의하고 서로 다른 타입으로 사용한다.
2) pop() 실패 시 기본값 반환의 한계를 이해한다.
------------------------------------------------------------
핵심 요약
- 클래스 템플릿은 사용할 때 MyStack<int>처럼 타입을 지정한다.
- T()는 T의 기본값을 만든다.
- 실무에서는 예외/optional 같은 에러 처리 전략이 필요하다.
------------------------------------------------------------
주의 포인트
- 빈 스택에서 T() 반환은 \"실패\"와 구분하기 어렵다.
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
