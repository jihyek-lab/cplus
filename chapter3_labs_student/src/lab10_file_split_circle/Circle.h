#ifndef CIRCLE_H
#define CIRCLE_H

/*
[Lab10] 파일 분리 + include guard
------------------------------------------------------------
이 헤더로 알아야 할 것(핵심 체크)
1) .h(헤더): 클래스 선언(설계도)만 둔다. (보통 구현은 두지 않음)
2) include guard(#ifndef/#define/#endif):
   - 같은 헤더가 여러 번 include될 때 중복 선언 에러를 막는다.
------------------------------------------------------------
*/

class Circle {
private:
    int radius;

public:
    Circle();
    Circle(int r);
    double getArea() const;
};

#endif // CIRCLE_H
