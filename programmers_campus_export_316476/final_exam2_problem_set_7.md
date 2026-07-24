# 기말고사 2 문제 정리

- 문제 수: 7
- 출처: Safari에서 열린 `프로그래머스 스쿨 > 파트16.기말고사 > 기말고사 2 > 문제정보` 화면 기준 정리

## 1. 객체지향 프로그래밍 [7-6 ~ 7-7] 연산자 정의와 프렌드 함수2

- 상태: PRIVATE | 권장 시간: 60분 | 입출력 방식: stdio | 타입: 일반 | 출제자: Jihye Kim

### 문제

2 X 2 행렬을 추상화한 matrix 클래스를 구현하라.
class matrix {
int e[2][2];
public:
matrix(int e11 = 0, int e12 = 0, int e21 = 0, int e22 = 0);
void show() {
cout << "matrix [[";
cout << e[0][0] << ", " << e[0][1] << "], [";
cout << e[1][0] << ", " << e[1][1] << "]]" << endl;
}
// TODO (+, - ,+=, -=, ==, >>, <<)
};
이 때, 다음과 같은 연산자 함수를 제공한다.
덧셈 연산 (멤버 함수)
+ 연산으로 matrix 값을 더한 새로운 matrix 를 반환
+= 연산으로 matirx 값을 더하여 저장
뺄셈 연산 (외부 함수)
- 연산으로 matrix 값을 뺀 새로운 matrix 를 반환
-= 연산으로 matirx 값을 빼서 저장
같음 연산
matrix 의 각 원소가 같은지 비교
입출력 연산
>> 연산으로 matrix 값을 배열에 복사 (멤버 함수)
<< 연산으로 배열의 값을matrix 에 복사 (외부 함수)
main 함수 수정 시 0점 처리
입출력 예시
입력으로 각 줄에 걸쳐 4 개의 원소를 5 번 받는다.
입력 1
1 2 3 4
1 1 1 1
2 2 2 2
11 11 11 11
4 4 4 4
출력 1
matrix [[1, 2], [3, 4]]
a 행렬과 d 행렬을 더한 값은 c 행렬과 같습니다.
matrix [[7, 7], [7, 7]]
array [[7, 7], [7, 7]]
matrix [[-5, -5], [-5, -5]]
array [[-5, -5], [-5, -5]]

### 초기 코드

```cpp
#include <iostream>
using namespace std;
class matrix {
int e[2][2];
public:
matrix(int e11 = 0, int e12 = 0, int e21 = 0, int e22 = 0);
void show() {
cout << "matrix [[";
cout << e[0][0] << ", " << e[0][1] << "], [";
cout << e[1][0] << ", " << e[1][1] << "]]" << endl;
}
// TODO (+, - ,+=, -=, ==, >>, <<)
matrix operator+(matrix &m);
matrix &operator+=(matrix &m);
friend matrix operator-(matrix &lhs, matrix &rhs);
friend matrix &operator-=(matrix &lhs, matrix &rhs);
bool operator==(matrix &m);
matrix &operator>>(int m[][2]);
friend matrix &operator<<(matrix &lhs, int rhs[][2]);
};
// TODO
///////
// 2 X 2 배열 입력
void input2x2(int m[][2]) {
for (int row = 0; row < 2; row++)
for (int col = 0; col < 2; col++)
cin >> m[row][col];
}
// 2 X 2 배열 출력
void output2x2(int m[][2]) {
cout << "array [[";
cout << m[0][0] << ", " << m[0][1] << "], [";
cout << m[1][0] << ", " << m[1][1] << "]]" << endl;
}
int main() {
int e11, e12, e21, e22;
cin >> e11 >> e12 >> e21 >> e22; // 행렬의 네 원소를 입력
matrix m(e11, e12, e21, e22); // 생성자를 통한 행렬 생성
m.show();
int x[2][2], y[2][2], z[2][2], w[2][2];
input2x2(x); // x 배열 입력
input2x2(y); // y 배열 입력
input2x2(z); // z 배열 입력
input2x2(w); // w 배열 입력
matrix a, b, c, d;
a << x; // x 의 각 원소를 a 에 복사
b << y; // y 의 각 원소를 b 에 복사
c << z; // z 의 각 원소를 c 에 복사
d << w; // w 의 각 원소를 d 에 복사
a += b;
c -= d;
matrix add = a + d;
matrix sub = b - c;
if (add == c)
cout << "a 행렬과 d 행렬을 더한 값은 c 행렬과 같습니다." << endl;
if (sub == d)
cout << "b 행렬과 c 행렬을 뺀 값은 d 행렬과 같습니다." << endl;
add >> x; // add 의 각 원소를 x 에 복사
add.show();
output2x2(x); // x 배열 출력
sub >> y; // add 의 각 원소를 x 에 복사
sub.show();
output2x2(y); // y 배열 출력
return 0;
}
```

## 2. 객체지향 프로그래밍 [8-5] 상속과 protected, 파생 클래스(큐)

- 상태: PRIVATE | 권장 시간: 60분 | 입출력 방식: stdio | 타입: 일반 | 출제자: Jihye Kim

### 문제

BaseArray를 상속받아, 다음과 같은 멤버를 갖는 정수를 저장하는 큐 MyQueue 클래스를 작성하라.
(단, 최대로 저장 가능한 정수의 갯수는 10으로 한다.)
정수를 입력받아 큐에 삽입하는 enqueue() (꽉 차있으면 변화 없음)
최대 용량을 반환하는 capacity()
현재 크기를 반환하는 length()
큐에서 저장된 정수를 꺼내는 dequeue(), (비어있으면 -1 반환)
입출력 예시
입력은 첫 줄에 총 입력받을 명령의 갯수가 주어진 후, 다음 줄부터 다음과 같은 명령들이 주어진다.
enqueue n: 큐에 n을 삽입
dequeue: 큐에서 정수를 꺼내 출력
length: 큐에 저장된 정수의 갯수 출력
capacity: 큐의 최대 저장 용량 출력
입력 1
6
capacity
enqueue 1
enqueue 2
dequeue
dequeue
length
출력 1
10
1
2
0

### 초기 코드

```cpp
#include <iostream>
using namespace std;
class BaseArray {
private:
int capacity; // 동적 할당된 메모리 용량
int *mem; // 동적 할당된 배열
protected:
BaseArray(int capacity=10) {
// capacity 크기의 동적 메모리 할당
this->capacity = capacity; mem = new int [capacity];
}
~BaseArray() { delete [] mem; }
void put(int index, int val) { mem[index] = val; }
int get(int index) { return mem[index]; }
int getCapacity() { return capacity; }
};
class MyQueue : public BaseArray {
int head, tail;
int size; // 현재 큐 안에 있는 데이터의 개수
public:
MyQueue(int capacity);
void enqueue(int n);
int dequeue();
int capacity();
int length();
};
// TODO
int main() {
MyQueue mQ(10);
int n;
int input;
string cmd;
cin >> n; // 명령의 갯수 입력
for (int i=0; i<n; i++) {
cin >> cmd; // 명령 입력
if (cmd == "enqueue") {
cin >> input; // 데이터 입력
mQ.enqueue(input); // 큐 객체에 데이터 추가
}
else if (cmd == "dequeue") {
cout << mQ.dequeue() << endl; // 큐 객체의 가장 먼저 저장된 원소를 꺼냄
}
else if (cmd == "length") {
cout << mQ.length() << endl; // 큐의 길이
}
else if (cmd == "capacity") {
cout << mQ.capacity() << endl; // 큐의 동적 배열의 크기
}
}
}
```

## 3. 객체지향 프로그래밍 [9-3 ~ 9-4] 추상 클래스 상속

- 상태: PRIVATE | 권장 시간: 60분 | 입출력 방식: stdio | 타입: 일반 | 출제자: Jihye Kim

### 문제

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

### 초기 코드

```cpp
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
public:
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
```

## 4. 객체지향 프로그래밍 [9-10] 가상 함수, 상속 종합 응용 2

- 상태: PRIVATE | 권장 시간: 60분 | 입출력 방식: stdio | 타입: 일반 | 출제자: Jihye Kim

### 문제

간단한 그래픽 편집기를 콘솔 바탕으로 만들어 보자. 그래픽 편집기의 기능은 "삽입", "삭제", "모두 보기", "종료" 의 4 가지이며, "종료" 명령을 받기 전까지 반복 실행된다.
입출력 예시
입력은 각 줄에 명령이 주어진다.
1 : 삽입 기능을 수행한다. shape 는 숫자가 주어지며, 1은 선, 2는 원, 3은 사각형을 의미한다. 단, 그 외의 경우 "올바르지 않은 도형입니다." 를 출력한다.
2 : 삭제 기능을 수행한다. index 가 주어지며 도형을 지울 수 없는 경우 "올바르지 않은 인덱스입니다." 를 출력한다.
3: 모두 보기 기능을 수행한다. 에디터에 그려진 도형을 그려진 순서대로 출력하며, 도형이 없는 경우 "빈 캔버스입니다." 를 출력한다.
4: 종료 기능을 수행한다.
그 외: "올바르지 않은 메뉴 접근입니다." 를 출력한다.
이떼, 시작과 끝에 각각 "그래픽 에디터를 시작합니다." 와 "그래픽 에디터를 종료합니다." 를 출력한다.
입력 1
5
1 0
3
1 1
1 2
1 3
3
2 3
2 2
2 0
2 0
3
4
출력1
그래픽 에디터를 시작합니다.
올바르지 않은 메뉴 접근입니다.
올바르지 않은 도형입니다.
빈 캔버스입니다.
0: Line
1: Circle
2: Rectangle
올바르지 않은 인덱스입니다.
빈 캔버스입니다.
그래픽 에디터를 종료합니다.

### 초기 코드

```cpp
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
```

## 5. 객체지향 프로그래밍 [10-3 ~ 10-6] 템플릿 함수 종합

- 상태: PRIVATE | 권장 시간: 60분 | 입출력 방식: stdio | 타입: 일반 | 출제자: Jihye Kim

### 문제

다음 함수들을 템플릿 함수로 구현하라.
scanArray(): 배열의 크기가 주어졌을 때, 해당 길이만큼 동적 배열을 생성하여 입력받아 포인터를 반환한다.
reverseArray(): 배열의 포인터와 개수를 인자로 받는다. 배열의 모든 요소들을 거꾸로 뒤집는다.
concat(): 두개의 배열의 포인터와 개수를 인자로 받아 배열을 연결한 새로운 동적 배열 포인터를 반환한다.
remove(): 배열의 포인터, 개수, 그리고 제거하려는 원소 배열의 포인터와 개수, 새로운 동적배열의 크기 참조 매개변수를 인자로 받아, 해당하는 원소를 모두 제거한 새로운 동적 배열의 포인터를 반환한다.
search(): 배열의 포인터, 개수, 그리고 검색하려는 원소를 인자로 받아 인덱스를 반환한다. (단, 가장 먼저 찾는 인덱스를 반환하며, 해당 원소가 없는 경우 -1 을 반환한다.)
입출력 예시
입력으로 첫 줄에 데이터 타입(0: int, 1: char, 2: float) 이 주어진다.
둘째 줄에 배열 a 의 크기와 각 원소가 주어진다.
셋째 줄에 배열 b 의 크기와 각 원소가 주어진다.
넷째 줄에 배열 d 의 크기와 각 원소가 주어진다.
마지막 줄에 찾을 원소가 주어진다.
입력 1
0
10 1 2 3 4 5 6 7 8 9 10
5 11 12 13 14 15
7 2 4 6 8 10 12 14
11
출력 1
10 9 8 7 6 5 4 3 2 1
10 9 8 7 6 5 4 3 2 1 11 12 13 14 15
9 7 5 3 1 11 13 15
5

### 초기 코드

```cpp
#include <iostream>
using namespace std;
// TODO: scanArray
// TODO: reverseArray
// TODO: remove
// TODO: concat
// TODO: search
// 배열의 포인터와 길이를 인자로 받아 모든 원소를 출력
template <class T> void printArray(T *arr, int len) {
for (int i = 0; i < len; i++)
cout << arr[i] << " ";
cout << endl;
}
template <class T> void run() {
int aSize, bSize, cSize, dSize, eSize;
T *a, *b, *c, *d, *e;
// a 배열 입력 및 뒤집기
cin >> aSize;
a = scanArray<T>(aSize);
reverseArray(a, aSize);
printArray(a, aSize); // 뒤집을 배열 출력
// b 배열 입력
cin >> bSize;
b = scanArray<T>(bSize);
// a, b 배열 합치기
cSize = aSize + bSize;
c = concat(a, aSize, b, bSize);
printArray(c, cSize); // 합쳐진 배열 출력
// 제거할 배열 입력 및 제거
cin >> dSize;
d = scanArray<T>(dSize);
e = remove(c, cSize, d, dSize, eSize);
printArray(e, eSize); // 원소를 제거한 배열 출력
// 특정 원소가 저장된 인덱스 찾기
T element;
int find;
cin >> element;
find = search<T>(e, eSize, element);
cout << find << endl;
delete[] a;
delete[] b;
delete[] c;
if (d)
delete[] d;
delete[] e;
}
enum DATA_TYPE { INT, CHAR, FLOAT };
int main() {
int dtype;
cin >> dtype;
switch (dtype) {
case INT:
run<int>();
break;
case CHAR:
run<char>();
break;
case FLOAT:
run<float>();
break;
default:
break;
}
return 0;
}
```

## 6. 객체지향 프로그래밍 [10-13] map 활용

- 상태: PRIVATE | 권장 시간: 60분 | 입출력 방식: stdio | 타입: 일반 | 출제자: Jihye Kim

### 문제

map 컨테이너를 활용하여 (이름, 성적)을 저장하는 GradeManager 클래스가 있다.
이름, 성적을 map에 저장하는 insert() 멤버함수와, 이름으로 성적을 검색하여 출력하는 search() 멤버함수를 작성하여 프로그램을 완성하라.
입출력 예시
1 : insert() 를 수행하며, 존재하는 name 을 받은 경우 " already exsits" 를 출력한다.
2 : search()를 수행하며, name 을 찾을 수 없는 경우 " doesn't exists" 를 출력한다.
3: 종료
입력 1
1 kim 100
2 kim
3
출력 1
kim: 100

### 초기 코드

```cpp
#include <iostream>
#include <string>
#include <map>
using namespace std;
class GradeManager {
map<string, int> scoreMap;
void insert();
void search();
public:
void run();
};
void GradeManager::insert() {
string name;
int score;
cin >> name >> score;
// TODO
// name이 이미 map에 있는 경우
// cout << name << " already exists" << endl;
// return;
//
// 맵에 없는 사람이 입력된 경우, 맵에 저장
}
void GradeManager::search() {
string name;
cin >> name;
// TODO
// name을 맵에서 찾을 수 없을 경우
// cout << name << " doesn't exist" << endl;
//
// 있는 경우
// cout << name << ": " << score << endl;
}
void GradeManager::run() {
int menu;
while (true) {
cin >> menu;
switch (menu) {
case 1: insert(); break;
case 2: search(); break;
case 3: return; // end
}
}
}
int main() {
GradeManager gm = GradeManager();
gm.run();
}
```

## 7. 객체지향 프로그래밍 [10-15] 객체 포인터를 vector에 삽입, 삭제

- 상태: PRIVATE | 권장 시간: 60분 | 입출력 방식: stdio | 타입: 일반 | 출제자: Jihye Kim

### 문제

circle 클래스가 다음과 같이 구현되어 있을때, CircleVectorManager 클래스를 완성하라.
void add(): radius 와 name을 입력받아서, v 에 마지막에 push 한다.
void remove(): name을 입력받아서, name과 같은 이름을 가지고 있는 circle을 모두 v에서 삭제한다.
void show() : v 에 저장되어있는 모든 원의 이름과 넓이를 출력한다.
힌트
vector v; 형식으로 벡터를 생성한다.
v.erase(it) 는 벡터 v 에서 it 를 가르키는 원소를 삭제하고 난 다음, 벡터 내에 삭제된 다음 지점의 첫 원소에 대한 포인터를 리턴한다. 그러므로 원소를 삭제한 후 다음 원소의 주소를 잡으려면 간단히 다음과 같이 하면 된다.
it = v.erase(it);
입출력 예시
1 : add 를 수행
2 : remove 를 수행
3: show 를 수행
4: 종료
입력 1
1 1 c1
1 2 c2
3
2 c1
3
4
출력 1
c1 3.14
c2 12.56
c2 12.56

### 초기 코드

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Circle {
string name;
int radius;
public:
Circle(int radius, string name) {
this->radius = radius;
this->name = name;
}
double getArea() { return 3.14*radius*radius; }
string getName() { return name; }
};
class CircleVectorManager {
vector<Circle*> v;
void add();
void remove();
void show();
public:
CircleVectorManager() { }
~CircleVectorManager() { }
void run();
};
// TODO
void CircleVectorManager::run() {
while(true) {
int menu;
cin >> menu;
switch(menu) {
case 1: //add
add(); break;
case 2: // remove;
remove(); break;
case 3: // paint
show(); break;
case 4: // end
return;
default:
break;
}
}
}
int main() {
CircleVectorManager cvm;
cvm.run();
}
```
