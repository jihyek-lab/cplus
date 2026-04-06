# C++ 중간고사 하이브리드 샘플

- 범위: Chapter 1 ~ Chapter 6
- 목적: 채점 편차를 줄이면서도 이해도를 확인하는 혼합형 시험지
- 구성: 객관식 + 빈칸 채우기 + 출력/판단 + 제한된 주관식
- 총점: 100점

## 유의사항

- 객관식은 정답 번호만 쓰시오.
- 빈칸 문제는 빈칸에 들어갈 코드 또는 단어만 쓰시오.
- 출력 문제는 공백과 줄바꿈을 구분해서 쓰시오.
- 주관식은 문제에 제시된 항목 순서대로 짧게 답하시오.
- 특별한 언급이 없으면 `#include <iostream>`, `#include <string>`, `using namespace std;`는 이미 있다고 가정한다.

---

## A. 객관식 (8문항 x 2점 = 16점)

### 1번.
`getline(cin, s)`를 가장 적절하게 설명한 것은?

1. 정수만 입력받는다
2. 공백 전까지만 입력받는다
3. 한 줄 전체를 입력받는다
4. 문자열 길이를 반환한다

### 2번.
`class`의 기본 접근 지정자는?

1. `public`
2. `protected`
3. `private`
4. `static`

### 3번.
다음 중 객체 배열에서 기본 생성자가 필요한 가장 직접적인 이유는?

1. 배열은 항상 동적으로 생성되기 때문에
2. 배열의 각 원소 객체를 인수 없이 생성해야 할 수 있기 때문에
3. 기본 생성자는 소멸자를 대신하기 때문에
4. 포인터 연산이 필요하기 때문에

### 4번.
다음 중 원본 값이 바뀔 수 있는 전달 방식만 올바르게 묶은 것은?

1. 값 전달
2. 값 전달, 주소 전달
3. 주소 전달, 참조 전달
4. 값 전달, 참조 전달

### 5번.
복사 생성자가 호출될 수 있는 경우로 가장 적절한 것은?

1. 객체를 값으로 전달할 때
2. 객체를 값으로 반환할 때
3. 기존 객체로 새 객체를 초기화할 때
4. 위 모두

### 6번.
함수 오버로딩을 구분하는 기준은?

1. 리턴 타입
2. 함수 본문 길이
3. 매개변수 개수와 타입
4. 주석 내용

### 7번.
디폴트 매개변수 선언 규칙으로 맞는 것은?

1. 중간 매개변수에만 줄 수 있다
2. 아무 위치에나 줄 수 있다
3. 뒤에서부터 연속으로 줘야 한다
4. 생성자에서는 사용할 수 없다

### 8번.
static 멤버 함수에서 non-static 멤버 변수에 직접 접근할 수 없는 가장 직접적인 이유는?

1. static 함수는 리턴값이 없어서
2. static 함수에는 `this`가 없어서
3. static 함수는 public만 접근해서
4. static 함수는 항상 전역 함수라서

---

## B. 빈칸 채우기 (8문항 x 5점 = 40점)

### 9번. 문자열 입력

```cpp
string line;
__________(cin, line);
cout << __________ << '\n';
```

### 10번. 생성자와 getter

```cpp
class Circle {
private:
    int radius;
public:
    Circle(int r = 1) : radius(__________) {}
    int getRadius() __________ { return radius; }
};
```

### 11번. 동적 메모리 해제

```cpp
int* p = new int[5];
__________ p;
```

### 12번. this 포인터

```cpp
void setRadius(int radius) {
    __________ = radius;
}
```

### 13번. 참조 swap

```cpp
void swapByRef(int& a, int& b) {
    int temp = a;
    a = __________;
    b = __________;
}
```

### 14번. 참조 반환

```cpp
int& arrElem(int a[], int index) {
    return __________;
}
```

### 15번. 오버로딩

```cpp
int sum(int a, int b) { return a + b; }
double sum(__________, __________) { return a + b; }
```

### 16번. static count

```cpp
class Counter {
private:
    static int count;
public:
    Counter() { __________; }
    ~Counter() { __________; }
    static int getCount() { return count; }
};

int Counter::count = 0;
```

---

## C. 출력 / 판단형 (4문항 x 6점 = 24점)

### 17번. 출력 결과

```cpp
int a = 3, b = 5;
cout << a + b << ' ' << a * b << '\n';
```

출력을 쓰시오.

### 18번. 출력 결과

```cpp
class A {
public:
    A() { cout << "C\n"; }
    ~A() { cout << "D\n"; }
};

int main() {
    A x;
    {
        A y;
    }
    A z;
}
```

출력 순서를 줄 단위로 쓰시오.

### 19번. 함수 선택

다음 코드에서 `sum(3)` 호출은 어떤 함수가 선택되는가?

```cpp
int sum(int a) { return a; }
int sum(int a, int b = 0) { return a + b; }
```

답안 형식:

- `선택 결과: __________`
- `판단: 정상 호출 / 모호함`

### 20번. 출력 결과

```cpp
class Person {
public:
    int money;
    static int sharedMoney;
};

int Person::sharedMoney = 10;

int main() {
    Person a, b;
    a.money = 100;
    b.money = 200;
    a.sharedMoney = 300;
    cout << a.money << ' ' << b.money << '\n';
    cout << a.sharedMoney << ' ' << b.sharedMoney << '\n';
}
```

출력 결과를 줄 단위로 쓰시오.

---

## D. 제한된 주관식 (2문항 x 10점 = 20점)

### 21번. 얕은 복사와 깊은 복사 (10점)

동적 메모리를 가진 객체에서 얕은 복사가 왜 문제가 되는지 설명하시오.

답안은 아래 3항목 순서대로 쓰시오.

- 1) 얕은 복사가 무엇인지
- 2) 어떤 문제가 생기는지
- 3) 깊은 복사가 무엇인지

### 22번. 오버로딩과 디폴트 매개변수, static (10점)

다음 4개를 짧게 설명하시오.

- 1) 오버로딩을 구분하는 기준
- 2) 리턴 타입만 다른 함수가 안 되는 이유
- 3) 디폴트 매개변수 규칙
- 4) static 멤버 변수의 뜻

각 항목은 1~2문장 이내로 작성하시오.
