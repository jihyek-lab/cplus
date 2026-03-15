#include <iostream>
using namespace std;

/*
[Lab01~05] 객체 포인터 + 객체 배열 + 배열 초기화 + 2차원 배열
------------------------------------------------------------
이 파일에서 순서대로 확인할 것
1) 객체 포인터: -> 와 (*p).
2) 객체 배열: 기본 생성자 호출 + 배열 접근
3) 기본 생성자 필요성: 배열 생성 시 Circle() 호출
4) 배열 초기화: 원소별 생성자 지정
5) 2차원 객체 배열: circles[2][3]
------------------------------------------------------------
*/

class Circle {
    int radius;
public:
    Circle() : radius(1) {}
    Circle(int r) : radius(r) {}
    void setRadius(int r) { radius = r; }
    double getArea() const { return 3.14 * radius * radius; }
};

int main() {
    cout << "[1] object pointer\n";
    // 같은 포인터 변수 p라도 무엇을 가리키느냐에 따라 호출 결과가 달라진다.
    Circle donut;
    Circle pizza(30);

    cout << "[obj] donut area = " << donut.getArea() << "\n";

    Circle* p = &donut; // donut의 주소 저장
    cout << "[ptr] donut area = " << p->getArea() << "\n";
    cout << "[ptr] donut area = " << (*p).getArea() << "\n";

    p = &pizza; // 이제 pizza를 가리킴
    cout << "[ptr] pizza area = " << p->getArea() << "\n\n";

    cout << "[2] object array\n";
    // 배열을 만들면 기본 생성자가 원소 개수만큼 호출된다.
    Circle circleArray[3];
    circleArray[0].setRadius(10);
    circleArray[1].setRadius(20);
    circleArray[2].setRadius(30);

    for (int i = 0; i < 3; i++)
        cout << "Circle " << i << " area = " << circleArray[i].getArea() << "\n";

    // 배열 이름은 첫 원소의 주소로 변환될 수 있다.
    Circle* ap = circleArray;
    for (int i = 0; i < 3; i++) {
        cout << "Circle " << i << " area(by ptr) = " << ap->getArea() << "\n";
        ap++; // 다음 원소로 이동
    }
    cout << "\n";

    cout << "[3] default constructor requirement\n";
    // 배열을 만들 때는 Circle()이 필요하므로 기본 생성자가 있어야 한다.
    Circle waffle(15);
    cout << "waffle area = " << waffle.getArea() << "\n";
    // Circle arr[3]; // 기본 생성자가 없으면 배열 생성 불가
    cout << "\n";

    cout << "[4] array initialization\n";
    // 원소별 생성자를 직접 지정할 수 있다.
    Circle initArray[3] = { Circle(10), Circle(20), Circle() };
    for (int i = 0; i < 3; i++)
        cout << "Circle " << i << " area = " << initArray[i].getArea() << "\n";
    cout << "\n";

    cout << "[5] 2d object array\n";
    // 2차원도 결국 "객체가 여러 개"이므로 접근은 circles[i][j] 형태
    Circle circles[2][3];
    int r = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            circles[i][j].setRadius(r++);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            cout << "Circle[" << i << "," << j << "] area = "
                 << circles[i][j].getArea() << "\n";

    return 0;
}
