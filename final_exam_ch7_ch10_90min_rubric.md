# C++ 기말고사 채점기준안

대상 시험지: [`final_exam_ch7_ch10_90min_student.md`](/Users/narim1pro/Documents/workspace/cplus/final_exam_ch7_ch10_90min_student.md)

- 범위: Chapter 7 ~ Chapter 10
- 시험시간: 90분
- 총점: 100점

## 채점 원칙

- 표현이 달라도 핵심 개념이 정확하면 정답으로 인정한다.
- 코드 작성 문제는 사소한 세미콜론 누락보다 설계 의도와 핵심 문법을 우선 평가한다.
- 단, `virtual`, `override`, `friend`, 참조 반환, 상속 생성자 호출처럼 개념을 드러내는 키워드가 빠지면 해당 부분 점수를 제한한다.
- 실행 결과 문제는 출력 순서가 중요하다.

---

## A. 짧은 판단 / 단답 / 실행 결과 (29점)

### 1번 (4점)

정답:

```cpp
(1) friend Power operator+(int n, const Power& p);
(2) Power operator+(int n, const Power& p)
```

- `friend` 선언에서 반환형과 함수명이 맞으면 1점
- `friend` 선언에서 매개변수 `int n, const Power& p`가 맞으면 1점
- 외부 연산자 함수 정의의 반환형과 함수명이 맞으면 1점
- 외부 연산자 함수 정의의 매개변수가 맞으면 1점
- `p.value`를 직접 사용하므로 `friend` 없이 작성하면 최대 2점

### 2번 (4점)

정답:

```text
6 5
```

- `b += c`가 먼저 평가됨을 반영하면 1점
- `b`의 최종 값 `5` 1점
- `a += b` 결과를 반영하면 1점
- `a`의 최종 값 `6` 1점

### 3번 (6점)

정답:

```cpp
(1)
Num& operator++() {
    value++;
    return *this;
}

(2)
Num operator++(int) {
    Num old = *this;
    value++;
    return old;
}
```

- 전위 증가 함수의 선언 `Num& operator++()`가 맞으면 1.5점
- 전위 증가에서 `value++` 후 `*this`를 반환하면 1.5점
- 후위 증가 함수의 선언 `Num operator++(int)`가 맞으면 1점
- 후위 증가에서 증가 전 객체를 `old` 등에 복사하면 1점
- 후위 증가에서 `value++` 후 증가 전 객체를 반환하면 1점

### 4번 (2점)

정답: 2

### 5번 (2점)

정답:

```text
Shape
```

- `draw()`가 `virtual`이 아니므로 정적 바인딩되어 `Shape::draw()`가 호출됨을 이해하면 정답.

### 6번 (2점)

정답:

```text
DB
```

- 파생 클래스 소멸자 `D`가 먼저 호출됨 1점
- 기본 클래스 소멸자 `B`가 나중에 호출됨 1점

### 7번 (2점)

정답:

```text
A, C
```

- `A`는 순수 가상 함수가 있어 직접 객체 생성 불가 1점
- `C`는 `f()`를 구현하지 않았으므로 여전히 추상 클래스 1점

### 8번 (2점)

정답: 3

### 9번 (2점)

정답:

```text
none 1 0 2
```

- `find("lee")`가 삽입 없이 실패해 `none`을 출력함 0.5점
- `find()` 이후에도 크기가 `1`임 0.5점
- 없는 키 `"lee"`를 `operator[]`로 조회하면 기본값 `0`이 출력됨 0.5점
- `scores["lee"]`가 새 원소를 삽입해 마지막 크기가 `2`가 됨 0.5점

### 10번 (3점)

정답:

```cpp
(1) vector<int>::iterator
(2) v.begin()
(3) v.end()
```

- 반복자 타입 `vector<int>::iterator` 1점
- 시작 위치 `v.begin()` 1점
- 종료 비교 위치 `v.end()` 1점

---

## B. 코드 읽기 / 개념 설명 (24점)

### 11번 (4점)

정답:

```text
BDdb
```

- 생성 순서 `Base -> Derived` 1.5점
- 소멸 순서 `Derived -> Base` 1.5점
- 전체 출력 정확성 1점

### 12번 (6점)

정답:

- A: 가능
- B: 가능
- C: 불가능
- D: 가능
- E: 불가능
- F: 불가능

배점:

- A 판단 1점
- B 판단 1점
- C 판단 1점
- D 판단 1점
- E 판단 1점
- F 판단 1점

### 13번 (5점)

정답:

```text
Circle
```

이유: `Shape::draw()`가 `virtual`이므로 `Shape*`로 호출해도 실제 객체 타입인 `Circle`의 오버라이딩 함수가 동적 바인딩된다.

- 출력 2점
- `virtual` 언급 1점
- 실제 객체 타입 기준 동적 바인딩 설명 2점

### 14번 (4점)

모범 답안:

`base`가 실제로 가리키는 객체는 `ColorPoint`가 아니라 `Point`인데, 이를 강제로 `ColorPoint*`로 다운캐스팅했기 때문에 `ColorPoint`의 멤버 `color` 영역이 존재하지 않는다. 따라서 `setColor()`로 파생 클래스 멤버를 수정하려는 동작은 안전하지 않으며 잘못된 동작이 된다.

- 실제 객체가 `Point`라는 판단 1.5점
- 다운캐스팅 위험성 설명 1.5점
- 존재하지 않는 파생 클래스 멤버 영역을 사용한다는 설명 1점

### 15번 (5점)

정답:

```cpp
bool operator<(const Student& s) const {
    return score < s.score;
}
```

배점:

- `bool operator<(const Student& s) const` 형태의 선언 2점
- `score`와 `s.score`를 비교함 2점
- 점수 오름차순이 되도록 `score < s.score` 방향으로 반환함 1점

---

## C. 코드 완성 / 구현 (47점)

### 16번 (6점)

정답:

```cpp
(1) x == p.x && y == p.y
(2) !(*this == p)
```

- `operator==`에서 `x` 비교 1.5점
- `operator==`에서 `y` 비교 1.5점
- 두 비교를 `&&`로 결합 1.5점
- `operator!=`에서 `operator==`를 반대로 재사용하거나 같은 의미로 부정 비교 1.5점

### 17번 (6점)

가능한 정답:

```cpp
(1) BaseArray(capacity)
(2) top(0)
(3) put(top, n)
(4) get(top)
(5) top
```

배점:

- 생성자 초기화 2점
- `push()`에서 `put(top, n)`으로 저장 1점
- `pop()`에서 감소 후 `get(top)` 반환 2점
- `length()`에서 `top` 반환 1점

### 18번 (7점)

가능한 정답:

```cpp
(1) virtual ~Notifier() { }
(2) virtual void send() = 0;
(3) Notifier(message)
(4) override
```

의도한 완성 예:

```cpp
class Notifier {
protected:
    string message;
public:
    Notifier(string message) : message(message) { }

    // 가상 소멸자를 한 줄로 작성하시오.
    virtual ~Notifier() { }

    // 순수 가상 함수 send()를 한 줄로 선언하시오.
    virtual void send() = 0;

    void notify() {
        cout << "[start]" << '\n';
        send();
        cout << "[end]" << '\n';
    }
};

class EmailNotifier : public Notifier {
public:
    EmailNotifier(string message) : Notifier(message) { }

    void send() override {
        cout << "Email: " << message << '\n';
    }
};
```

배점:

- 가상 소멸자 선언 2점
- 순수 가상 함수 선언 2점
- 기본 클래스 생성자 호출 2점
- `override` 1점

### 19번 (8점)

정답:

```cpp
(1) data.push_back(value)
(2) data.empty()
(3) T()
(4) data.back()
(5) data.pop_back()
(6) data.size()
```

배점:

- `push_back` 1점
- empty 체크 1.5점
- 기본값 `T()` 반환 1.5점
- `back()`으로 마지막 값 획득 1.5점
- `pop_back()` 1.5점
- 크기 반환 1점

### 20번 (10점)

가능한 정답:

```cpp
(1) score[name] = s
(2) sum += s
(3) (double)sum / n
(4) score.begin()
(5) score.end()
(6) it->second >= avg
(7) it->first
```

배점:

- map 저장 2점
- 합계 누적 1점
- 실수 평균 계산 2점
- 반복자 범위 2점
- 평균 이상 조건 2점
- 이름 출력 1점

### 21번 (10점)

가능한 정답:

```cpp
(1) v.push_back(x)
(2) sort(v.begin(), v.end())
(3) v[i] % 2 == 0
(4) v[i]
```

배점:

- vector 저장 2점
- `sort(v.begin(), v.end())` 호출 3점
- 짝수 조건 3점
- 출력값 `v[i]` 2점
