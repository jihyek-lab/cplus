/*
 * 실습용 starter code
 * 문제: 가상 함수와 연결 리스트 기반 다형성
 *
 * 학생용 가이드:
 * - README.md 에 문제 설명과 체크리스트가 정리되어 있습니다.
 * - 아래 코드의 TODO 위치를 중심으로 구현을 진행하세요.
 * - 필요하면 main 함수는 그대로 두고, 클래스/함수 구현만 채워 넣는 방식으로 연습해 보세요.
 */

#include <iostream>
#include <string>
using namespace std;
// UI 기능을 제공 (입출력 기능)
class UI {
public:
    static int getInt();
    static void println(string);
    static void print(string);
    static void print(int);
};
int UI::getInt() {
    int k;
    cin >> k;
    return k;
}
void UI::println(string msg) { cout << msg << endl; }
void UI::print(string msg) { cout << msg; }
void UI::print(int msg) { cout << msg; }
class Shape {
    Shape *next;
protected:
    virtual void draw() = 0;
public:
    Shape() { next = NULL; }
    virtual ~Shape() {}
    void paint();
    Shape *getNext() { return next; }
    Shape *setNext(Shape *p) { return next = p; }
};
// TODO: Shape::paint
// TODO: Line 클래스
// TODO: Circle 클래스
// TODO: Rectangle 클래스
class GraphicEditor {
    enum { LINE = 1, CIRCLE = 2, RECT = 3 };
    enum { ADD = 1, ERASE = 2, SHOW = 3, EXIT = 4 };
    Shape *pStart;
    Shape *pLast;
protected:
    void add();
    void erase();
    void show();
public:
    GraphicEditor();
    ~GraphicEditor();
    void run();
};
// TODO: GraphicEditor 클래스
int main() {
    GraphicEditor *g = new GraphicEditor(); // 그래픽 에디터 객체 생성
    g->run(); // 에디터 실행
    delete g;
}
