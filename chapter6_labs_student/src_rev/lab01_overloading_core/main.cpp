#include <iostream>
using namespace std;

/*
[Lab01] 오버로딩 핵심 묶음
------------------------------------------------------------
강의 핵심
1) 함수 이름이 같아도 매개변수의 개수나 타입이 다르면 공존할 수 있다.
2) 컴파일러는 "호출하는 모양"을 보고 어떤 함수를 부를지 결정한다.
3) 리턴 타입은 호출 시점에 보이지 않으므로 오버로딩 기준이 될 수 없다.
4) 같은 이름으로 묶는 것이 가능하더라도, 의미를 너무 많이 섞으면 설계가 불분명해질 수 있다.
------------------------------------------------------------
*/

void printTitle(const char* title) {
    cout << "\n[" << title << "]\n";
}

namespace BasicSum {
// 가장 기본적인 오버로딩 예제다.
// 컴파일러가 매개변수 개수와 타입으로 함수를 고른다는 점을 보여준다.
int sum(int a, int b) { return a + b; }
int sum(int a, int b, int c) { return a + b + c; }
double sum(double a, double b) { return a + b; }
}

namespace BadReturnTypeOnly {
// 아래 코드는 리턴 타입만 다르기 때문에 동시에 둘 수 없다.
// 호출 시점에는 리턴 타입이 보이지 않으므로 컴파일러가 구분할 수 없다.
//
// int sum(int a, int b) { return a + b; }
// double sum(int a, int b) { return static_cast<double>(a + b); }
}

namespace BigExample {
// 같은 이름이라도 호출 모양이 분명히 다르면 다른 작업을 연결할 수 있다.
int big(int a, int b) {
    return (a > b) ? a : b;
}

int big(const int values[], int size) {
    // 예외 상황을 간단히 막아 두면 실습 중 동작을 해석하기가 쉬워진다.
    if (size <= 0) {
        return -1;
    }

    int result = values[0];
    for (int i = 1; i < size; ++i) {
        if (result < values[i]) {
            result = values[i];
        }
    }
    return result;
}
}

namespace RangeExample {
// 매개변수 1개: 0부터 last까지의 합
int sum(int last) {
    int total = 0;
    for (int i = 0; i <= last; ++i) {
        total += i;
    }
    return total;
}

// 매개변수 2개: first부터 last까지의 구간합
// 가능한 오버로딩이지만, 이름 하나에 의미를 너무 많이 넣지 않는 것이 좋다.
int sum(int first, int last) {
    // a > b라도 동작하게 만들어 실습 중 실수에 덜 민감하게 했다.
    if (first > last) {
        int temp = first;
        first = last;
        last = temp;
    }

    int total = 0;
    for (int i = first; i <= last; ++i) {
        total += i;
    }
    return total;
}
}

int main() {
    // 여기서는 컴파일러가 호출 모양을 어떻게 해석하는지 보는 것이 핵심이다.
    printTitle("기본 오버로딩");
    cout << "sum(2, 6) = " << BasicSum::sum(2, 6) << "\n";
    cout << "sum(2, 5, 33) = " << BasicSum::sum(2, 5, 33) << "\n";
    cout << "sum(12.5, 33.6) = " << BasicSum::sum(12.5, 33.6) << "\n";

    // 배열 버전은 매개변수 형태가 완전히 다르므로 다른 함수로 구분된다.
    printTitle("호출 모양이 다른 오버로딩");
    int values[5] = {1, 9, -2, 8, 6};
    cout << "big(2, 3) = " << BigExample::big(2, 3) << "\n";
    cout << "big(values, 5) = " << BigExample::big(values, 5) << "\n";
    cout << "big(values, 0) = " << BigExample::big(values, 0) << "\n";

    // 가능한 설계와 좋은 설계가 항상 같은 것은 아니라는 점도 함께 본다.
    printTitle("의미가 다른 sum 오버로딩");
    cout << "RangeExample::sum(3) = " << RangeExample::sum(3) << "\n";
    cout << "RangeExample::sum(3, 5) = " << RangeExample::sum(3, 5) << "\n";
    cout << "RangeExample::sum(8, 5) = " << RangeExample::sum(8, 5) << "\n";

    printTitle("에러 확인 포인트");
    cout << "BadReturnTypeOnly namespace의 주석을 풀면,\n";
    cout << "\"리턴 타입만 다르면 안 된다\"는 규칙을 직접 확인할 수 있다.\n";

    return 0;
}
