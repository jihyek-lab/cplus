#include <iostream>
using namespace std;

/*
[Lab02] 객체 배열: 기본 생성자 호출 + 포인터 순회
------------------------------------------------------------
핵심
1) Circle arr[3]; 은 객체 3개를 만들며, 각 원소에 대해 "기본 생성자"가 호출된다.
2) 배열 원소 접근: arr[i].member()
3) 배열 이름은 첫 원소의 주소로 변환될 수 있어 Circle* p = arr; 가능
4) p++ 로 다음 원소로 이동하며 p->member()로 접근할 수 있다.
------------------------------------------------------------
*/

class Circle {
    int radius;
public:
    Circle() : radius(1) {} // 배열 생성 시 3번 호출됨
    void setRadius(int r) { radius = r; }
    double getArea() const { return 3.14 * radius * radius; }
};

int main() {
    Circle circleArray[3]; // (1) 기본 생성자 3번

    circleArray[0].setRadius(10);
    circleArray[1].setRadius(20);
    circleArray[2].setRadius(30);

    for (int i = 0; i < 3; i++)
        cout << "Circle " << i << " area = " << circleArray[i].getArea() << "\n";

    Circle* p = circleArray; // (2) 첫 원소 주소
    for (int i = 0; i < 3; i++) {
        cout << "Circle " << i << " area(by ptr) = " << p->getArea() << "\n";
        p++; // (3) 다음 원소
    }
    return 0;
}
