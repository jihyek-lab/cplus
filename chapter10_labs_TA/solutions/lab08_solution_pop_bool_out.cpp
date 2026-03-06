#include <iostream>
using namespace std;

template <class T>
class MyStack {
    int tos;
    T data[100];
public:
    MyStack(): tos(-1) {}
    void push(const T& e){ if(tos==99) return; data[++tos]=e; }
    bool pop(T& out){
        if(tos==-1) return false;
        out = data[tos--];
        return true;
    }
};

int main(){
    MyStack<int> s;
    int out;
    cout << boolalpha << s.pop(out) << "\n"; // false
    s.push(3);
    cout << s.pop(out) << " " << out << "\n"; // true 3
}
