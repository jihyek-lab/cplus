#include <iostream>
using namespace std;

/*
[Lab03] 예외 흐름: 스택 예외 + 중첩 try
------------------------------------------------------------
문제 설명
1) 스택에서 overflow/underflow를 예외로 처리한다.
2) 중첩 try에서 예외가 어떤 catch로 전달되는지 확인한다.
------------------------------------------------------------
핵심 요약
- 예외는 가장 가까운 matching catch로 이동
- 처리되지 않으면 바깥 try로 전파
------------------------------------------------------------
주의 포인트
- catch 순서는 타입 일치 범위가 좁은 것부터 배치한다.
------------------------------------------------------------
*/

class MyStack {
    int data[3];
    int tos;
public:
    MyStack(): tos(-1) {}
    void push(int n){ if(tos==2) throw "Stack Full"; data[++tos]=n; }
    int pop(){ if(tos==-1) throw "Stack Empty"; return data[tos--]; }
};

int main() {
    MyStack st;
    try {
        st.push(1); st.push(2); st.push(3);
        cout << st.pop() << "\n";
        cout << st.pop() << "\n";
        cout << st.pop() << "\n";
        cout << st.pop() << "\n"; // throw

        try { throw "inner"; }
        catch(const char* s) { cout << "inner: " << s << "\n"; }
    }
    catch(const char* msg) {
        cout << "outer: " << msg << "\n";
    }
}
