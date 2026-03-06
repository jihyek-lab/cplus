#include "Circle.h"

/*
[Lab10] 구현 파일(.cpp)
------------------------------------------------------------
이 파일로 알아야 할 것(핵심 체크)
1) .cpp(구현): 멤버 함수 정의(구현)를 둔다.
2) 구현에서 멤버 함수는 Circle::func 형태로 정의한다.
------------------------------------------------------------
*/

Circle::Circle() : radius(1) {}
Circle::Circle(int r) : radius(r) {}

double Circle::getArea() const {
    return 3.14 * radius * radius;
}
