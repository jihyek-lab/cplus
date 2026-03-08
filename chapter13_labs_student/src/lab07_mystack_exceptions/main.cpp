#include <iostream>
using namespace std;

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
    } catch(const char* msg) {
        cout << "예외: " << msg << "\n";
    }
}
