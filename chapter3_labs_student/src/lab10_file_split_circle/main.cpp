#include <iostream>
#include "Circle.h"
using namespace std;

/*
[Lab10] main.cpp (사용자)
------------------------------------------------------------
이 파일로 알아야 할 것(핵심 체크)
1) main.cpp는 클래스를 "사용"한다. (선언은 헤더에서 가져옴)
2) 컴파일 시 main.cpp만 빌드하면 구현(Circle.cpp)이 링크되지 않는다.
   -> 반드시 Circle.cpp를 함께 컴파일해야 한다.

컴파일 예시:
g++ -std=c++17 main.cpp Circle.cpp -o run
./run
------------------------------------------------------------
*/

int main() {
    Circle donut;
    Circle pizza(30);

    cout << "donut area = " << donut.getArea() << "\n";
    cout << "pizza area = " << pizza.getArea() << "\n";

    return 0;
}
