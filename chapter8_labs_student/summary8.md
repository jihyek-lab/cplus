# Chapter 8 핵심 요약

## 1. 상속이란?
- 상속은 기존 클래스의 멤버를 물려받아 새 클래스를 만드는 방법이다.
- 기반 클래스(base class, 부모 클래스)의 기능을 재사용하고, 파생 클래스(derived class, 자식 클래스)에서 새 기능을 추가할 수 있다.
- `public` 상속은 "기존 인터페이스를 유지한 채 확장한다"는 의미로 가장 자주 사용된다.

```cpp
class Point {
public:
    void set(int x, int y) { ... }
};

class ColorPoint : public Point {
public:
    void setColor(string c) { ... }
};
```

핵심:
- `ColorPoint` 객체는 `Point` 기능도 함께 가진다.
- 그래서 `cp.set(3, 4);`처럼 부모의 public 멤버를 그대로 사용할 수 있다.

---

## 2. 상속에서 접근 가능한 멤버
- `public` 멤버: 외부에서도 접근 가능
- `protected` 멤버: 외부에서는 접근 불가, 파생 클래스 내부에서는 접근 가능
- `private` 멤버: 오직 그 클래스 내부에서만 접근 가능

```cpp
class Point {
protected:
    int x, y;
};
```

핵심:
- `protected`는 "상속을 위해 열어 둔 멤버"라고 보면 된다.
- 외부 객체가 `a.x`처럼 직접 접근하는 것은 여전히 불가능하다.
- 하지만 파생 클래스의 멤버 함수 안에서는 `x`, `y`를 직접 사용할 수 있다.

---

## 3. 업캐스팅과 다운캐스팅
- 업캐스팅: 파생 클래스 포인터를 기반 클래스 포인터로 바꾸는 것
- 다운캐스팅: 기반 클래스 포인터를 파생 클래스 포인터로 바꾸는 것

```cpp
ColorPoint* pDer = &cp;
Point* pBase = pDer;      // 업캐스팅: 자동
ColorPoint* p2 = (ColorPoint*)pBase; // 다운캐스팅: 주의
```

핵심:
- 업캐스팅은 자동으로 허용된다.
- 업캐스팅 후에는 기반 클래스의 멤버만 보인다.
- 다운캐스팅은 실제 객체가 정말 그 파생 타입일 때만 안전하다.

즉:
- `Point* p = &cp;` 는 안전
- `ColorPoint* p = (ColorPoint*)basePtr;` 는 실제 객체 타입을 잘못 가정하면 위험

---

## 4. 생성자와 소멸자의 호출 순서
- 상속에서는 기반 클래스가 먼저 생성되고, 파생 클래스가 나중에 생성된다.
- 소멸은 반대로 파생 클래스부터, 그다음 기반 클래스 순서로 일어난다.

생성 순서:
1. Base
2. Derived

소멸 순서:
1. Derived
2. Base

이유:
- 파생 클래스는 기반 클래스 부분이 먼저 준비되어 있어야 안전하게 만들어질 수 있기 때문이다.

---

## 5. 부모 생성자 호출과 초기화 리스트
- 파생 클래스가 객체를 만들 때, 기반 클래스 생성자도 반드시 호출된다.
- 기반 클래스에 기본 생성자가 없으면, 파생 클래스가 초기화 리스트에서 어떤 생성자를 쓸지 직접 써야 한다.

```cpp
class A {
public:
    A(int x) { ... }
};

class B : public A {
public:
    B(int x) : A(x + 3) { ... }
};
```

핵심:
- `A()`가 없는데 `A(int)`만 있으면, `B`는 `: A(...)`를 반드시 써야 한다.
- 부모 생성자는 함수 본문이 아니라 초기화 리스트에서 호출한다.

---

## 6. 다단계 상속에서도 규칙은 같다
- 상속이 여러 단계여도 생성 규칙은 동일하다.
- 가장 위 부모부터 차례대로 초기화된다.

예:
- `TV -> WideTV -> SmartTV`

생성 순서:
1. `TV`
2. `WideTV`
3. `SmartTV`

핵심:
- `SmartTV`는 직접 `TV`를 초기화하지 않는다.
- 자신의 직접 부모인 `WideTV`를 초기화하고,
- `WideTV`가 다시 `TV`를 초기화한다.

---

## 7. 상속 방식에 따른 접근 수준 변화

### public 상속
- 기반 클래스의 `public`은 파생 클래스에서도 `public`
- 기반 클래스의 `protected`는 파생 클래스에서도 `protected`

### protected 상속
- 기반 클래스의 `public`과 `protected`가 파생 클래스에서 `protected`

### private 상속
- 기반 클래스의 `public`과 `protected`가 파생 클래스에서 `private`

핵심:
- 상속 방식은 "파생 클래스 안에서 쓸 수 있느냐"보다
- "외부에서 그 멤버가 어떤 수준으로 보이느냐"를 바꾼다.

예:
```cpp
class D1 : public Base {};
class D2 : protected Base {};
class D3 : private Base {};
```

- `D1` 객체는 외부에서 `pub()` 호출 가능
- `D2`, `D3` 객체는 외부에서 `pub()` 호출 불가

---

## 8. 다중 상속
- 하나의 클래스가 여러 부모 클래스를 동시에 상속받는 것

```cpp
class Calculator : public Adder, public Subtractor { ... };
```

핵심:
- 서로 다른 기능을 합칠 수 있다.
- 하지만 구조가 복잡해지고, 같은 이름의 멤버가 겹치면 혼란이 생길 수 있다.

---

## 9. 다이아몬드 상속 문제

구조:
- `A`
- `B : public A`
- `C : public A`
- `D : public B, public C`

이 경우 `D` 안에는 `A`가 두 개 들어간다.

문제:
- `D` 객체에서 `x`를 쓰면 어느 `A::x`인지 모호해진다.

```cpp
class D_bad : public B, public C {};
// D_bad e; e.x = 10; // 에러
```

---

## 10. virtual 상속으로 해결
- 다이아몬드 상속에서 공통 기반 클래스가 하나만 존재하도록 만드는 방법이 `virtual` 상속이다.

```cpp
class Bv : virtual public A {};
class Cv : virtual public A {};
class D_good : public Bv, public Cv {};
```

핵심:
- `virtual` 상속을 쓰면 `A`를 공유한다.
- 그래서 `D_good` 안에는 `A`가 하나만 들어간다.
- 결과적으로 `d.x` 같은 접근이 모호하지 않다.

---

## 꼭 기억할 문장
- 상속은 "부모 기능을 물려받아 확장하는 것"이다.
- 생성은 부모부터, 소멸은 자식부터 일어난다.
- 부모 생성자 호출은 초기화 리스트에서 한다.
- `protected`는 외부가 아니라 파생 클래스에게 허용된 접근이다.
- 업캐스팅은 안전하지만, 다운캐스팅은 실제 객체 타입을 잘 봐야 한다.
- 다이아몬드 상속 문제는 `virtual` 상속으로 해결한다.

---

## 추천 실습 순서
1. 상속 기본과 `protected`
2. 업캐스팅 / 다운캐스팅
3. 생성자 / 소멸자 순서
4. 초기화 리스트와 부모 생성자 호출
5. 상속 방식에 따른 접근 변화
6. 다중 상속
7. 다이아몬드 상속과 `virtual`
