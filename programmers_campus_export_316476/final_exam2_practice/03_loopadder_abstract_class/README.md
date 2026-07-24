# 객체지향 프로그래밍 [9-3 ~ 9-4] 추상 클래스 상속

- 학습 주제: 추상 클래스와 상속
- 실습 목표: 추상 클래스 LoopAdder를 상속해 for, while, do-while 버전을 각각 구현하는 문제입니다.

## 구현 체크리스트

- 세 파생 클래스의 생성자 작성하기
- calculate()를 각 반복문 스타일에 맞게 구현하기
- 기본 클래스의 protected getter 활용하기

## 실습 힌트

세 클래스가 하는 일은 같고 반복문의 형태만 다릅니다. 같은 로직을 반복문만 바꿔서 구현해 보세요.

## 원문 문제 설명

다음 추상 클래스 LoopAdder 가 있다.
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
main() 함수를 통해 실행 결과를 올바르게 출력하도록 LoopAdder 를 상속받는 ForLoopAdder, WhileLoopAdder, 그리고 DoWhileLoopAdder 클래스를 작성하라. 각각 for, while, 그리고 do-while 반복문을 통해 합을 구하도록 calculate() 함수를 작성하라.
main 함수 수정 시 0점 처리
입출력 예시
총 세 줄의 입력이 주어지며, 각 줄의 입력으로 read() 에 대한 두 수 x 와 y 가 주어진다.
입력 1
3 10
3 5
10 20
출력 1
For Loop:
3 부터 10까지의 합 = 52 입니다.
While Loop:
3 부터 5까지의 합 = 12 입니다.
Do while Loop:
10 부터 20까지의 합 = 165 입니다.

## 파일 안내

- `main.cpp`: 학생 실습용 starter code
- 이 파일을 기준으로 TODO를 채우면서 연습하면 됩니다.
