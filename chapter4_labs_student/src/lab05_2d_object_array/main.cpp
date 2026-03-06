#include <iostream>
using namespace std;

/*
[Lab05] 2차원 객체 배열: circles[2][3]
------------------------------------------------------------
핵심
1) 2차원도 결국 "객체가 여러 개"다. => 기본 생성자가 원소 개수만큼 호출된다.
2) 접근: circles[i][j].member()
3) 중첩 for문으로 초기화/출력을 연습하자.
------------------------------------------------------------
*/

class Circle {
    int radius;
public:
    Circle() : radius(1) {}
    void setRadius(int r) { radius = r; }
    double getArea() const { return 3.14 * radius * radius; }
};

int main() {
    Circle circles[2][3];

    int r = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            circles[i][j].setRadius(r++);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            cout << "Circle[" << i << "," << j << "] area = " << circles[i][j].getArea() << "\n";

    return 0;
}
