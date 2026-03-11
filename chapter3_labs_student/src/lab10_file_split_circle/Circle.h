#ifndef CIRCLE_H  
// include guard 시작, 헤더 파일 여러번 포함되어도 내부 선언이 중복되지 않도록 보호
// 즉, 헤더를 여러 .cpp에서 혹은 다른 헤더들이 교차로 include할 때 중복 선언·재정의 문제를 막는 C/C++ 표준 관행입니다.

// CIRCLE_H라는 매크로가 정의되어 있지 않다면 아래 코드 실행.
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
