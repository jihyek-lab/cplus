/*
 * 실습용 starter code
 * 문제: 추상 클래스와 상속
 *
 * 학생용 가이드:
 * - README.md 에 문제 설명과 체크리스트가 정리되어 있습니다.
 * - 아래 코드의 TODO 위치를 중심으로 구현을 진행하세요.
 * - 필요하면 main 함수는 그대로 두고, 클래스/함수 구현만 채워 넣는 방식으로 연습해 보세요.
 */

#include <iostream>
#include <string>
using namespace std;
class LoopAdder { // 추상 클래스
    string name; // 루프 이름
    int x, y, sum;
    void read(); // x, y 값을 읽는 함수
    void write(); // sum을 출력하는 함수
protected:
    // 루프의 이름을 받으며, 디폴트 값은 ""
    LoopAdder(string name = "") { this->name = name; }
    int getX() { return x; }
    int getY() { return y; }
    virtual int calculate() = 0; // 순수 가상 함수, 루프를 돌며 합을 구하는 함수
public:
    void run(); // 연산을 진행하는 함수
};
// x, y 입력
void LoopAdder::read() { cin >> x >> y; }
// 결과를 출력
void LoopAdder::write() {
    cout << name << ":" << endl;
    cout << x << " 부터 " << y << "까지의 합 = " << sum << " 입니다." << endl;
}
void LoopAdder::run() {
    read(); // x, y를 읽는다.
    sum = calculate(); // 루프를 돌며 계산한다.
    write(); // 결과를 출력한다.
}
class ForLoopAdder : public LoopAdder {
protected:
    int calculate() override;
public:
    ForLoopAdder(string name = "");
};
class WhileLoopAdder : public LoopAdder {
protected:
    // while 반복문을 통해 [x, y] 구간의 합을 구한다.
public:
};
class DoWhileLoopAdder : public LoopAdder {
protected:
    // do-while 반복문을 통해 [x, y] 구간의 합을 구한다.
public:
};
int main() {
    // LoopAdder 추상 클래스를 상속하는
    // ForLoopAdder, WhileLoopAdder, DowhileLoopAdder 객체를 생성
    ForLoopAdder forLoop("For Loop");
    WhileLoopAdder whileLoop("While Loop");
    DoWhileLoopAdder doWhileLoop("Do while Loop");
    // 각 객체를 실행
    forLoop.run();
    whileLoop.run();
    doWhileLoop.run();
}
