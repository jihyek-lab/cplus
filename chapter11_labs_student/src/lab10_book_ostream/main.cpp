#include <iostream>
#include <string>
using namespace std;

/*
[Lab10] operator<< 오버로딩: Book 출력
------------------------------------------------------------
핵심
- 객체를 한 줄 문자열로 직렬화(serialize)하듯 출력할 수 있다.
- CSV처럼 "title,press,author" 형태로 출력.

확장
- quotes 처리, 구분자 선택 등은 과제로 확장 가능
------------------------------------------------------------
*/

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
    Book book("소유냐 존재냐", "한국출판사", "에리히프롬");
    cout << book << "\n";
}
