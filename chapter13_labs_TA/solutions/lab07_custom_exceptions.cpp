#include <iostream>
using namespace std;
struct StackFullException{};
struct StackEmptyException{};
class MyStack{ int data[3]; int tos=-1;
public:
    void push(int n){ if(tos==2) throw StackFullException{}; data[++tos]=n; }
    int pop(){ if(tos==-1) throw StackEmptyException{}; return data[tos--]; }
};
int main(){
    MyStack st;
    try{ st.push(1); st.push(2); st.push(3); st.push(4); }
    catch(StackFullException&){ cout<<"FULL\n"; }
    try{ cout<<st.pop()<<"\n"; cout<<st.pop()<<"\n"; cout<<st.pop()<<"\n"; cout<<st.pop()<<"\n"; }
    catch(StackEmptyException&){ cout<<"EMPTY\n"; }
}
