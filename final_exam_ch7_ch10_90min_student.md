# C++ 기말고사

- 범위: Chapter 7 ~ Chapter 10
- 시험시간: 90분
- 총점: 100점

## 응시 정보

- 학번: ____________________
- 이름: ____________________

## 유의사항

- 객관식은 정답 번호를 쓰고, 단답형은 핵심이 드러나도록 짧게 쓰시오.
- 실행 결과 문제는 공백과 줄바꿈을 구분하여 쓰시오.
- 설명 문제는 핵심 개념이 드러나도록 짧고 분명하게 쓰시오.
- 코드 작성 문제는 `main()`을 수정하지 않는다고 가정하고, 필요한 클래스/함수의 핵심 부분을 작성하시오.
- 특별한 언급이 없으면 `#include <iostream>`, `#include <string>`, `#include <vector>`, `#include <map>`, `#include <algorithm>`, `using namespace std;`는 이미 있다고 가정한다.

---

## A. 짧은 판단 / 단답 / 실행 결과 (29점)

### 1번 (4점)
다음 코드에서 `Power p(5);`라고 할 때 `3 + p`가 가능하도록 빈칸을 채우시오. 여기서 `p`는 오른쪽 피연산자인 `Power` 객체이다.

```cpp
class Power {
    int value;
public:
    Power(int value = 0) : value(value) { }
    int get() const { return value; }

    (1) __________
};

(2) __________ {
    return Power(n + p.value);
}
```

### 2번 (4점)
다음 코드의 출력 결과를 쓰시오.

```cpp
class Num {
    int value;
public:
    Num(int value = 0) : value(value) { }
    Num& operator+=(const Num& other) {
        value += other.value;
        return *this;
    }
    int get() const { return value; }
};

int main() {
    Num a(1), b(2), c(3);
    a += b += c;
    cout << a.get() << " " << b.get();
}
```

답: ____________________

### 3번 (6점)
다음 `Num` 클래스에서 전위 증가 `++a`와 후위 증가 `a++`가 모두 동작하도록 두 연산자 함수를 완성하시오.

- 전위 증가 `++a`: 값을 1 증가시킨 뒤, 증가된 현재 객체를 반환한다.
- 후위 증가 `a++`: 증가 전 객체를 반환하고, 현재 객체의 값은 1 증가시킨다.

```cpp
class Num {
    int value;
public:
    Num(int value = 0) : value(value) { }
    int get() const { return value; }

    // 전위 증가 연산자 함수 전체를 작성하시오.
    (1)
    ____________________________________________________________
    ____________________________________________________________
    ____________________________________________________________

    // 후위 증가 연산자 함수 전체를 작성하시오.
    (2)
    ____________________________________________________________
    ____________________________________________________________
    ____________________________________________________________
    ____________________________________________________________
};
```

### 4번 (2점)
상속 관계에서 생성자 호출 순서로 옳은 것은?

1. 파생 클래스 생성자 본문 -> 기본 클래스 생성자
2. 기본 클래스 생성자 -> 파생 클래스 생성자 본문
3. 멤버 함수 호출 순서에 따라 달라진다
4. 포인터 타입에 따라 달라진다

답: __________

### 5번 (2점)
다음 코드의 실행 결과를 쓰시오.

```cpp
class Shape {
public:
    void draw() { cout << "Shape"; }
};
class Circle : public Shape {
public:
    void draw() { cout << "Circle"; }
};

int main() {
    Circle c;
    Shape* p = &c;
    p->draw();
}
```

답: ____________________

### 6번 (2점)
다음 코드의 실행 결과를 쓰시오.

```cpp
class Base {
public:
    virtual ~Base() { cout << "B"; }
};

class Derived : public Base {
public:
    ~Derived() { cout << "D"; }
};

int main() {
    Base* p = new Derived;
    delete p;
}
```

답: ____________________

### 7번 (2점)
다음 코드에서 객체를 직접 생성할 수 없는 클래스를 모두 쓰시오.

```cpp
class A {
public:
    virtual void f() = 0;
};

class B : public A {
public:
    void f() override { }
};

class C : public A {
};
```

답: ____________________

### 8번 (2점)
다음 함수 템플릿 호출 중 컴파일 오류 가능성이 가장 큰 것은?

```cpp
template <class T>
void myswap(T& a, T& b);
```

1. `int a=1, b=2; myswap(a, b);`
2. `double a=1.1, b=2.2; myswap(a, b);`
3. `int a=1; double b=2.2; myswap(a, b);`
4. `char a='x', b='y'; myswap(a, b);`

답: __________

### 9번 (2점)
다음 코드 실행 후 출력 결과를 쓰시오.

```cpp
map<string, int> scores;
scores["kim"] = 90;

if (scores.find("lee") == scores.end()) {
    cout << "none ";
}

cout << scores.size() << " ";
cout << scores["lee"] << " ";
cout << scores.size();
```

답: ____________________

### 10번 (3점)
다음 코드에서 `vector<int>`의 기본 반복자(iterator)를 사용하여 모든 원소를 순서대로 출력하도록 빈칸을 채우시오.

```cpp
vector<int> v = { 3, 1, 2 };

for ((1) __________ it = (2) __________; it != (3) __________; ++it) {
    cout << *it;
}
```

---

## B. 코드 읽기 / 개념 설명 (24점)

### 11번 (4점)
다음 코드의 실행 결과를 쓰시오.

```cpp
class Base {
public:
    Base() { cout << "B"; }
    ~Base() { cout << "b"; }
};

class Derived : public Base {
public:
    Derived() { cout << "D"; }
    ~Derived() { cout << "d"; }
};

int main() {
    Derived x;
}
```

답: ____________________

### 12번 (6점)
다음 코드에서 주석으로 표시된 각 문장이 가능한지 독립적으로 판단하시오.

```cpp
class Base {
public:
    int pub;
protected:
    int pro;
private:
    int pri;
};

class Derived : public Base {
public:
    void f() {
        pub = 1;   // A
        pro = 2;   // B
        pri = 3;   // C
    }
};

class ProtectedD : protected Base { };
class PrivateD : private Base { };

int main() {
    Derived a;
    ProtectedD b;
    PrivateD c;

    a.pub = 1;     // D
    b.pub = 2;     // E
    c.pub = 3;     // F
}
```

- A: __________
- B: __________
- C: __________
- D: __________
- E: __________
- F: __________

### 13번 (5점)
다음 코드의 실행 결과를 쓰고, 그 이유를 한 문장으로 설명하시오.

```cpp
class Shape {
public:
    virtual void draw() { cout << "Shape"; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Circle"; }
};

void paint(Shape* p) {
    p->draw();
}

int main() {
    Circle c;
    paint(&c);
}
```

- 실행 결과: ____________________
- 이유: ____________________________________________________________

### 14번 (4점)
다음 코드가 위험하거나 잘못된 이유를 설명하시오.

```cpp
class Point { };
class ColorPoint : public Point {
    string color;
public:
    void setColor(string color) { this->color = color; }
};

int main() {
    Point p;
    Point* base = &p;
    ColorPoint* cp = (ColorPoint*)base;
    cp->setColor("red");
}
```

답: ____________________________________________________________

### 15번 (5점)
다음 `Student` 객체들을 `sort(v.begin(), v.end())`로 정렬하려고 한다. **점수 오름차순**으로 정렬되도록 `Student` 클래스 안에 `operator<` 함수 전체를 작성하시오.

```cpp
class Student {
public:
    string name;
    int score;

    Student(string name, int score) : name(name), score(score) { }

    ____________________________________________________________
    ____________________________________________________________
    ____________________________________________________________
};
```

---

## C. 코드 완성 / 구현 (47점)

### 16번 (6점)
다음 `Point` 클래스에서 두 점의 좌표가 모두 같으면 같은 객체로 판단하도록 `operator==`와 `operator!=`를 완성하시오.

```cpp
class Point {
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) { }

    bool operator==(const Point& p) const {
        return (1) __________;
    }

    bool operator!=(const Point& p) const {
        return (2) __________;
    }
};
```

### 17번 (6점)
다음 코드가 동작하도록 `BaseArray`를 상속받는 `MyStack` 클래스를 완성하시오. 스택이 꽉 찼을 때 `push()`는 아무 일도 하지 않고, 비었을 때 `pop()`은 `-1`을 반환한다.

```cpp
class BaseArray {
    int capacity;
    int* mem;
protected:
    BaseArray(int capacity = 10) {
        this->capacity = capacity;
        mem = new int[capacity];
    }
    ~BaseArray() { delete[] mem; }
    void put(int index, int val) { mem[index] = val; }
    int get(int index) const { return mem[index]; }
    int getCapacity() const { return capacity; }
};

class MyStack : public BaseArray {
    int top;
public:
    MyStack(int capacity = 10) : (1) __________, (2) __________ { }

    void push(int n) {
        if (top == getCapacity()) return;
        (3) __________;
        top++;
    }

    int pop() {
        if (top == 0) return -1;
        top--;
        return (4) __________;
    }

    int length() const {
        return (5) __________;
    }
};
```

### 18번 (7점)
다음 조건을 만족하도록 추상 클래스와 파생 클래스를 완성하시오.

- `Notifier`는 추상 클래스이다.
- `Notifier`는 기본 클래스 포인터로 삭제해도 안전하도록 가상 소멸자를 가진다.
- `send()`는 순수 가상 함수이다.
- `notify()`는 공통 흐름을 제공하며, 내부에서 `send()`를 호출한다.
- `EmailNotifier`는 `send()`를 오버라이딩하여 `Email: 메시지` 형식으로 출력한다.

```cpp
class Notifier {
protected:
    string message;
public:
    Notifier(string message) : message(message) { }

    // 가상 소멸자를 한 줄로 작성하시오.
    (1) ________________________________________

    // 순수 가상 함수 send()를 한 줄로 선언하시오.
    (2) ________________________________________

    void notify() {
        cout << "[start]" << '\n';
        send();
        cout << "[end]" << '\n';
    }
};

class EmailNotifier : public Notifier {
public:
    EmailNotifier(string message) : (3) __________ { }

    void send() (4) __________ {
        cout << "Email: " << message << '\n';
    }
};
```

### 19번 (8점)
다음 `MyStack<T>` 클래스 템플릿을 완성하시오. 스택이 비었을 때 `pop()`은 기본값 `T()`를 반환한다고 가정한다.

```cpp
template <class T>
class MyStack {
    vector<T> data;
public:
    void push(const T& value) {
        (1) __________;
    }

    T pop() {
        if ((2) __________) return (3) __________;
        T value = (4) __________;
        (5) __________;
        return value;
    }

    int size() const {
        return (6) __________;
    }
};
```

### 20번 (10점)
학생 이름과 점수를 여러 줄 입력받아 평균 이상인 학생 이름만 사전순으로 출력하려고 한다. 빈칸을 채우시오.
단, 학생 이름은 중복되지 않는다고 가정한다.

입력 형식:

```text
3
park 60
lee 100
kim 80
```

출력 예:

```text
kim
lee
```

코드:

```cpp
int n;
cin >> n;

map<string, int> score;
int sum = 0;

for (int i = 0; i < n; i++) {
    string name;
    int s;
    cin >> name >> s;
    // 이름과 점수를 map에 저장
    (1) __________;
    // 합계 누적
    (2) __________;
}

// 평균 계산
double avg = (3) __________;

for (map<string, int>::iterator it = (4) __________; it != (5) __________; ++it) {
    // 평균 이상인지 검사
    if ((6) __________) {
        // 학생 이름 출력
        cout << (7) __________ << '\n';
    }
}
```

### 21번 (10점)
정수 `n`개를 입력받아 `vector`에 저장한 뒤, 오름차순으로 정렬하고 짝수만 출력하려고 한다. 빈칸을 채우시오.

입력 예:

```text
5
3 8 1 4 7
```

출력 예:

```text
4
8
```

코드:

```cpp
int n;
cin >> n;

vector<int> v;

for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    // vector에 입력값 저장
    (1) __________;
}

// 오름차순 정렬
(2) __________;

for (int i = 0; i < v.size(); i++) {
    // 짝수인지 검사
    if ((3) __________) {
        // 짝수 출력
        cout << (4) __________ << '\n';
    }
}
```
