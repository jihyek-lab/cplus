/*
 * Reference solution
 * 문제 4: 가상 함수, 상속 종합 응용 2
 *
 * 문제 요약:
 * - Shape 추상 클래스를 기반으로 Line, Circle, Rectangle 을 만든다.
 * - GraphicEditor 에서 도형 삽입, 삭제, 전체 출력, 종료를 처리한다.
 * - 도형들은 next 포인터로 연결된 단일 연결 리스트 구조로 관리한다.
 */

#include <iostream>
#include <string>
using namespace std;

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

void Shape::paint() { draw(); }

class Line : public Shape {
protected:
    void draw() override { UI::print("Line"); }
};

class Circle : public Shape {
protected:
    void draw() override { UI::print("Circle"); }
};

class Rectangle : public Shape {
protected:
    void draw() override { UI::print("Rectangle"); }
};

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

GraphicEditor::GraphicEditor() : pStart(NULL), pLast(NULL) {}

GraphicEditor::~GraphicEditor() {
    // 에디터가 끝날 때 남아 있는 모든 도형을 해제한다.
    while (pStart != NULL) {
        Shape *victim = pStart;
        pStart = pStart->getNext();
        delete victim;
    }
}

void GraphicEditor::add() {
    int shapeType = UI::getInt();
    Shape *shape = NULL;

    if (shapeType == LINE) {
        shape = new Line();
    } else if (shapeType == CIRCLE) {
        shape = new Circle();
    } else if (shapeType == RECT) {
        shape = new Rectangle();
    } else {
        UI::println("올바르지 않은 도형입니다.");
        return;
    }

    if (pStart == NULL) {
        pStart = pLast = shape;
    } else {
        // 리스트의 끝에 새 도형을 이어 붙인다.
        pLast->setNext(shape);
        pLast = shape;
    }
}

void GraphicEditor::erase() {
    int index = UI::getInt();
    if (index < 0 || pStart == NULL) {
        UI::println("올바르지 않은 인덱스입니다.");
        return;
    }

    Shape *prev = NULL;
    Shape *cur = pStart;
    int curIndex = 0;

    while (cur != NULL && curIndex < index) {
        prev = cur;
        cur = cur->getNext();
        curIndex++;
    }

    if (cur == NULL) {
        UI::println("올바르지 않은 인덱스입니다.");
        return;
    }

    if (prev == NULL) {
        // 첫 노드를 지우는 경우 시작 포인터를 갱신한다.
        pStart = cur->getNext();
    } else {
        prev->setNext(cur->getNext());
    }

    if (cur == pLast) {
        pLast = prev;
    }

    delete cur;
}

void GraphicEditor::show() {
    if (pStart == NULL) {
        UI::println("빈 캔버스입니다.");
        return;
    }

    Shape *cur = pStart;
    int index = 0;
    while (cur != NULL) {
        UI::print(index);
        UI::print(": ");
        cur->paint();
        UI::println("");
        cur = cur->getNext();
        index++;
    }
}

void GraphicEditor::run() {
    UI::println("그래픽 에디터를 시작합니다.");
    while (true) {
        int menu = UI::getInt();
        switch (menu) {
            case ADD:
                add();
                break;
            case ERASE:
                erase();
                break;
            case SHOW:
                show();
                break;
            case EXIT:
                UI::println("그래픽 에디터를 종료합니다.");
                return;
            default:
                UI::println("올바르지 않은 메뉴 접근입니다.");
                break;
        }
    }
}

int main() {
    GraphicEditor *g = new GraphicEditor();
    g->run();
    delete g;
}
