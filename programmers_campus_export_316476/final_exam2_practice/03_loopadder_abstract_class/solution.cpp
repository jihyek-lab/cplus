/*
 * Reference solution
 * 문제 3: 추상 클래스 상속
 *
 * 문제 요약:
 * - 추상 클래스 LoopAdder 를 상속해 세 파생 클래스를 만든다.
 * - 같은 구간 합을 for, while, do-while 세 방식으로 계산한다.
 */

#include <iostream>
#include <string>
using namespace std;

class LoopAdder {
    string name;
    int x, y, sum;
    void read();
    void write();

protected:
    LoopAdder(string name = "") { this->name = name; }
    int getX() { return x; }
    int getY() { return y; }
    virtual int calculate() = 0;

public:
    void run();
};

void LoopAdder::read() { cin >> x >> y; }

void LoopAdder::write() {
    cout << name << ":" << endl;
    cout << x << " 부터 " << y << "까지의 합 = " << sum << " 입니다." << endl;
}

void LoopAdder::run() {
    read();
    // 실제 계산 방식은 파생 클래스의 calculate()가 결정한다.
    sum = calculate();
    write();
}

class ForLoopAdder : public LoopAdder {
protected:
    int calculate() override;

public:
    ForLoopAdder(string name = "");
};

class WhileLoopAdder : public LoopAdder {
protected:
    int calculate() override;

public:
    WhileLoopAdder(string name = "");
};

class DoWhileLoopAdder : public LoopAdder {
protected:
    int calculate() override;

public:
    DoWhileLoopAdder(string name = "");
};

ForLoopAdder::ForLoopAdder(string name) : LoopAdder(name) {}

int ForLoopAdder::calculate() {
    int sum = 0;
    for (int i = getX(); i <= getY(); i++) {
        sum += i;
    }
    return sum;
}

WhileLoopAdder::WhileLoopAdder(string name) : LoopAdder(name) {}

int WhileLoopAdder::calculate() {
    int sum = 0;
    int i = getX();
    while (i <= getY()) {
        sum += i;
        i++;
    }
    return sum;
}

DoWhileLoopAdder::DoWhileLoopAdder(string name) : LoopAdder(name) {}

int DoWhileLoopAdder::calculate() {
    int sum = 0;
    int i = getX();
    // do-while 특성상 본문을 최소 한 번 실행한다.
    do {
        sum += i;
        i++;
    } while (i <= getY());
    return sum;
}

int main() {
    ForLoopAdder forLoop("For Loop");
    WhileLoopAdder whileLoop("While Loop");
    DoWhileLoopAdder doWhileLoop("Do while Loop");

    forLoop.run();
    whileLoop.run();
    doWhileLoop.run();
}
