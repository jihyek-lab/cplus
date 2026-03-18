#include <iostream>
#include <string>
using namespace std;

/*
[Lab03] 스트림 연산자 오버로딩(<<, >>)
------------------------------------------------------------
문제 설명
1) 객체 출력용 operator<< 를 구현한다.
2) 객체 입력용 operator>> 를 구현한다.
------------------------------------------------------------
핵심 요약
- operator<< 는 ostream&를 반환해야 체이닝 가능
- operator>> 는 입력 대상이 바뀌므로 참조로 받음
- private 접근이 필요하면 friend 선언
------------------------------------------------------------
주의 포인트
- operator>> 안에서 프롬프트를 넣는 방식은 교재 예시용이며,
  일반 라이브러리 스타일에서는 분리하는 편이 좋다.
------------------------------------------------------------
*/

class Point {
    int x, y;
public:
    Point(int x=0, int y=0) : x(x), y(y) {}
    friend ostream& operator<<(ostream& os, const Point& a);
    friend istream& operator>>(istream& ins, Point& a);
};

ostream& operator<<(ostream& os, const Point& a) {
    os << "(" << a.x << "," << a.y << ")";
    return os;
}

istream& operator>>(istream& ins, Point& a) {
    cout << "x 좌표>>";
    ins >> a.x;
    cout << "y 좌표>>";
    ins >> a.y;
    return ins;
}

class Book {
    string title, press, author;
public:
    Book(string title="", string press="", string author="")
        : title(title), press(press), author(author) {}
    friend ostream& operator<<(ostream& os, const Book& b);
};

ostream& operator<<(ostream& os, const Book& b) {
    os << b.title << "," << b.press << "," << b.author;
    return os;
}

int main() {
    Point p;
    cin >> p;
    cout << p << "\n";

    Book book("소유냐 존재냐", "한국출판사", "에리히프롬");
    cout << book << "\n";
}
