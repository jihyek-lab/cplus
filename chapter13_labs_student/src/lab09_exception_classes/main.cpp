#include <iostream>
#include <string>
using namespace std;

class MyException {
    int lineNo; string func; string msg;
public:
    MyException(int n, string f, string m): lineNo(n), func(f), msg(m) {}
    void print() const { cout << func << ":" << lineNo << " " << msg << "\n"; }
};
class DivideByZeroException : public MyException {
public: DivideByZeroException(int n,string f,string m): MyException(n,f,m) {}
};
class InvalidInputException : public MyException {
public: InvalidInputException(int n,string f,string m): MyException(n,f,m) {}
};

int main() {
    int x,y;
    try {
        cin >> x >> y;
        if(x<0 || y<0) throw InvalidInputException(10,"main","음수");
        if(y==0) throw DivideByZeroException(11,"main","0 나눔");
        cout << (double)x/y << "\n";
    } catch(const DivideByZeroException& e){ e.print(); }
      catch(const InvalidInputException& e){ e.print(); }
}
