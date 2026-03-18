#include <iostream>
#include <string>
using namespace std;

/*
[Lab04] 예외 클래스 + 다형성 catch
------------------------------------------------------------
문제 설명
1) 예외를 클래스로 정의해 의미를 구체화한다.
2) 서로 다른 예외 타입을 구분해 처리한다.
------------------------------------------------------------
핵심 요약
- 예외 객체는 상태(라인, 함수, 메시지)를 담을 수 있다.
- catch 순서는 구체적인 타입부터 작성한다.
------------------------------------------------------------
주의 포인트
- 공통 처리가 필요하면 공통 기반 클래스 활용 가능.
------------------------------------------------------------
*/

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
