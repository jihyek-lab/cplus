#include <iostream>
using namespace std;

/*
[Lab10] 동적 객체 배열: new Circle[n] / delete[]
------------------------------------------------------------
핵심
1) Circle* arr = new Circle[n];  => 객체 n개 생성(기본 생성자 n번)
2) arr[i]로 접근하여 멤버 함수 호출 가능
3) 반환은 delete[] arr;  (각 원소 소멸자 호출 후 해제)
------------------------------------------------------------
실습 포인트
- 넓이를 출력하고, 특정 범위(100~200)에 들어가는 개수를 센다.
*/

class Circle {
    int radius;
public:
    Circle() : radius(1) {}
    void setRadius(int r) { radius = r; }
    double getArea() const { return 3.14 * radius * radius; }
};

int main() {
    cout << "How many circles? ";
    int n;
    cin >> n;
    if (n <= 0) return 0;

    Circle* arr = new Circle[n]; // (1) 동적 객체 배열

    for (int i = 0; i < n; i++) {
        int r;
        cout << "circle " << (i + 1) << " radius: ";
        cin >> r;
        arr[i].setRadius(r);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        double area = arr[i].getArea();
        cout << area << " ";
        if (area >= 100 && area <= 200) count++;
    }
    cout << "\ncount(100~200) = " << count << "\n";

    delete[] arr; // (2) 배열 반환은 delete[]
    return 0;
}
