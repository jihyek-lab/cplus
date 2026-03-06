#include <iostream>
using namespace std;

/*
[Lab15] static으로 "현재 살아있는 객체 수" 세기
-----------------------------------------
핵심
- static int numOfCircles; 를 클래스 내부에 두면 모든 Circle 객체가 공유.
- 생성자에서 ++, 소멸자에서 -- 하면 "현재 살아있는 개수"를 알 수 있다.
- new Circle[10]  => 생성자 10번 호출
- delete[]        => 소멸자 10번 호출

여기서 확인할 것
- 배열 생성/삭제 시 개수가 어떻게 변하는지 출력으로 확인
-----------------------------------------
*/

class Circle {
private:
    static int numOfCircles;
    int radius;
public:
    Circle(int r = 1) : radius(r) { numOfCircles++; }
    ~Circle() { numOfCircles--; }
    static int getNumOfCircles() { return numOfCircles; }
};
int Circle::numOfCircles = 0;

int main() {
    Circle* p = new Circle[10];
    cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << "\n";
    delete[] p;
    cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << "\n";

    Circle a;
    cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << "\n";
    Circle b;
    cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << "\n";
    return 0;
}
