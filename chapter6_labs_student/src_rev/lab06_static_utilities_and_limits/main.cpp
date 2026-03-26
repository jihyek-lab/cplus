#include <iostream>
using namespace std;

/*
[Lab06] static 활용과 제한 묶음
------------------------------------------------------------
강의 핵심
1) 객체 상태가 필요 없는 함수는 static 멤버 함수로 묶어 유틸리티처럼 사용할 수 있다.
2) static 변수는 객체 수와 상관없이 하나만 존재하므로 개수 세기 같은 역할에 적합하다.
3) static 함수는 객체 없이 호출되므로 this 포인터가 없다.
4) 따라서 static 함수는 non-static 멤버를 직접 읽을 수 없고, 객체를 따로 받아야 한다.
------------------------------------------------------------
*/

class Math {
public:
    // 객체 상태가 필요 없는 함수는 static으로 묶어 두면 사용이 분명해진다.
    static int abs(int a) {
        return (a >= 0) ? a : -a;
    }

    static int max(int a, int b) {
        return (a > b) ? a : b;
    }

    static int min(int a, int b) {
        return (a < b) ? a : b;
    }

    static int clamp(int x, int lo, int hi) {
        if (x < lo) {
            return lo;
        }
        if (x > hi) {
            return hi;
        }
        return x;
    }
};

class Circle {
private:
    static int numOfCircles;
    int radius;

public:
    // 생성자에서 증가시키면 현재 살아 있는 객체 수를 셀 수 있다.
    Circle(int r = 1) : radius(r) {
        ++numOfCircles;
    }

    // 소멸자에서 감소시키면 객체 생명주기와 카운터가 연결된다.
    ~Circle() {
        --numOfCircles;
    }

    static int getNumOfCircles() {
        return numOfCircles;
    }

    int getRadius() const {
        return radius;
    }
};

int Circle::numOfCircles = 0;

class PersonError {
private:
    int money;

public:
    PersonError() : money(0) {}

    void setMoney(int value) {
        money = value;
    }

    // static 함수에는 this가 없으므로 non-static 멤버를 직접 읽을 수 없다.
    // static int getMoney() { return money; }
    // 위 줄을 풀면 static 함수에는 this가 없어서 non-static 멤버에
    // 직접 접근할 수 없다는 컴파일 에러를 확인할 수 있다.

    // 필요한 객체를 인자로 받으면 그 객체의 값을 읽는 것은 가능하다.
    static int getMoney(const PersonError& person) {
        return person.money;
    }
};

int main() {
    // 전역 함수처럼 보이는 기능을 클래스 안으로 정리한 예다.
    cout << "[1] static 유틸리티 함수\n";
    cout << "Math::abs(-5) = " << Math::abs(-5) << "\n";
    cout << "Math::max(10, 8) = " << Math::max(10, 8) << "\n";
    cout << "Math::min(-3, -8) = " << Math::min(-3, -8) << "\n";
    cout << "Math::clamp(25, 0, 10) = " << Math::clamp(25, 0, 10) << "\n";

    // static 변수는 객체 수와 무관하게 하나만 있으므로 카운터 역할에 적합하다.
    cout << "\n[2] 살아있는 객체 수 세기\n";
    cout << "처음 개수 = " << Circle::getNumOfCircles() << "\n";
    {
        Circle a;
        Circle b(5);
        cout << "블록 안 개수 = " << Circle::getNumOfCircles() << "\n";
        cout << "b.radius = " << b.getRadius() << "\n";
    }
    // 블록을 벗어나면 지역 객체가 소멸하면서 카운터도 줄어든다.
    cout << "블록 밖 개수 = " << Circle::getNumOfCircles() << "\n";

    // 배열 생성/삭제는 생성자와 소멸자가 여러 번 호출된다는 점을 보여준다.
    Circle* arr = new Circle[3];
    cout << "배열 생성 후 개수 = " << Circle::getNumOfCircles() << "\n";
    delete[] arr;
    cout << "배열 삭제 후 개수 = " << Circle::getNumOfCircles() << "\n";

    // static 함수의 한계와 우회 방법을 함께 확인한다.
    cout << "\n[3] static 함수의 제한\n";
    PersonError person;
    person.setMoney(100);
    cout << "getMoney(person) = " << PersonError::getMoney(person) << "\n";

    return 0;
}
