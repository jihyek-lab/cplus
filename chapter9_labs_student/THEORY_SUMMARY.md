# C++ Chapter 9 Theory Summary

주제: `virtual`, 오버라이딩, 동적 바인딩, 가상 소멸자, 순수 가상 함수, 추상 클래스

## 1. 이 장의 큰 그림

9장의 핵심은 "부모 타입으로 다루더라도, 실제 객체에 맞는 함수가 실행되게 만드는 것"이다.

예를 들어:

```cpp
Base* p = new Derived();
p->f();
```

- `virtual`이 없으면: `Base::f()`
- `virtual`이 있으면: `Derived::f()`

즉, 이 장은 "상속" 자체보다 "다형성(polymorphism)"을 제대로 쓰는 방법을 다룬다.

## 2. redefine vs override

### redefine

파생 클래스가 부모와 같은 이름의 함수를 다시 만드는 것 자체는 가능하다.
하지만 부모 함수가 `virtual`이 아니면, 부모 포인터로 호출할 때 부모 버전이 선택된다.

```cpp
class Base {
public:
    void f() {}
};

class Derived : public Base {
public:
    void f() {}
};
```

이 경우 `Base* p = new Derived(); p->f();` 는 `Base::f()`를 호출한다.

### override

부모 함수가 `virtual`이고, 파생 클래스가 같은 시그니처로 다시 구현하면 오버라이딩이다.

```cpp
class Base {
public:
    virtual void f() {}
};

class Derived : public Base {
public:
    void f() override {}
};
```

이 경우 `Base* p = new Derived(); p->f();` 는 `Derived::f()`를 호출한다.

`override`는 생략 가능하지만, 붙이는 것이 좋다.
이유는 함수 이름 오타나 매개변수 실수를 컴파일러가 잡아주기 때문이다.

## 3. static binding vs dynamic binding

### static binding

컴파일 시점에 어떤 함수를 호출할지 결정한다.
기준은 "포인터나 참조의 타입"이다.

- `virtual`이 없는 일반 함수 호출
- `Base*`로 보면 `Base` 함수가 선택됨

### dynamic binding

실행 시점에 실제 객체 타입을 보고 함수를 결정한다.
기준은 "가리키는 실제 객체"이다.

- `virtual` 함수 호출
- `Base*`라도 실제 객체가 `Derived`면 `Derived` 함수가 실행됨

## 4. Base 함수 안에서 virtual 호출

부모 클래스 함수 안에서 `virtual` 함수를 호출해도 동적 바인딩이 일어난다.

```cpp
class Shape {
public:
    void paint() { draw(); }
    virtual void draw() {}
};
```

`Shape* p = new Circle(); p->paint();` 라면
`paint()` 안의 `draw()`는 `Circle::draw()`로 연결된다.

이 패턴은 "공통 흐름은 부모가 제공하고, 세부 동작은 자식이 바꾸는 구조"로 자주 사용된다.

## 5. 여러 단계 상속에서의 virtual

상속이 `Base -> Derived -> GrandDerived`처럼 여러 단계여도,
`virtual` 함수는 가장 마지막에 오버라이딩한 구현이 선택된다.

즉:

```cpp
Base* p = new GrandDerived();
p->f();
```

결과는 `GrandDerived::f()`다.

포인터 타입이 무엇이든, 실제 객체가 `GrandDerived`라면 가장 구체적인 구현이 실행된다.

## 6. 범위 지정 연산자로 부모 버전 강제 호출

`virtual` 함수라도 `::`를 사용하면 부모 버전을 직접 부를 수 있다.

```cpp
Shape::draw();
```

이건 동적 바인딩이 아니라, 특정 클래스의 함수를 명시적으로 호출하는 것이다.

이 패턴은 자식 클래스가:

- 부모 기능을 먼저 실행하고
- 그 뒤 자기 기능을 덧붙일 때

자주 쓴다.

## 7. 가상 소멸자(virtual destructor)

이 장에서 가장 중요한 실무 포인트 중 하나다.

```cpp
Base* p = new Derived();
delete p;
```

이 코드가 가능하다면, `Base`의 소멸자는 반드시 `virtual`이어야 한다.

왜냐하면:

- 소멸자가 `virtual`이 아니면 `Base` 소멸자만 호출될 수 있음
- `Derived` 쪽 정리 코드가 빠질 수 있음
- 결국 메모리 누수나 자원 해제 누락 위험이 생김

안전한 형태:

```cpp
class Base {
public:
    virtual ~Base() {}
};
```

정리:

- 부모 포인터로 `delete`할 가능성이 있으면
- 부모 소멸자는 거의 항상 `virtual`

## 8. 순수 가상 함수(pure virtual function)

```cpp
virtual void draw() = 0;
```

이렇게 `= 0`을 붙이면 순수 가상 함수다.

의미:

- "이 함수는 부모에서 완성하지 않겠다"
- "자식이 반드시 구현해야 한다"

이런 함수를 하나라도 가진 클래스는 추상 클래스가 된다.

## 9. 추상 클래스(abstract class)

추상 클래스는 객체를 직접 만들 수 없는 클래스다.

```cpp
Shape s;   // 불가
```

하지만 포인터나 참조는 만들 수 있다.

```cpp
Shape* p = new Circle();
```

추상 클래스는 보통 "공통 인터페이스" 역할을 한다.

예:

- 계산기 인터페이스
- 도형 인터페이스
- 장치 드라이버 인터페이스

## 10. 추상 클래스의 장점

- 공통 규약을 강제할 수 있다
- 부모 타입 하나로 여러 자식 객체를 다룰 수 있다
- 확장에 유리하다

예를 들어 `Calculator*` 타입 하나로:

- `GoodCalc`
- `SmartCalc`
- `SafeCalc`

같은 여러 구현체를 바꿔 끼울 수 있다.

## 11. Template Method 느낌의 구조

부모가 전체 흐름을 가지고 있고,
자식이 일부 단계만 구현하는 구조다.

예:

```cpp
void run() {
    input();
    cout << calc(a, b);
}
```

여기서:

- `run()`은 부모가 제공
- `calc()`는 자식이 구현

이렇게 하면 "공통 흐름"과 "바뀌는 부분"이 분리된다.

이 장 후반의 계산기 예제가 바로 그 구조다.

## 12. 꼭 기억할 규칙

1. 부모 포인터로 자식 함수를 다르게 실행하고 싶으면 `virtual`
2. 오버라이딩에는 `override`를 붙이는 습관
3. 부모 포인터로 `delete`할 가능성이 있으면 부모 소멸자는 `virtual`
4. `= 0` 이 붙으면 순수 가상 함수
5. 순수 가상 함수가 하나라도 있으면 추상 클래스
6. 추상 클래스는 객체 생성 불가, 포인터/참조는 가능

## 13. 자주 헷갈리는 포인트

### Q1. 함수 이름만 같으면 무조건 오버라이딩인가?

아니다.
부모 함수가 `virtual`이어야 다형성 관점의 오버라이딩 효과가 난다.

### Q2. `virtual`은 자식 쪽에만 붙이면 되나?

아니다.
보통 부모 선언이 기준이다.
부모에서 `virtual`이어야 부모 포인터/참조를 통한 동적 바인딩이 생긴다.

### Q3. `override`는 왜 쓰나?

실수 방지 때문이다.
오버라이딩 의도인데 실제로는 시그니처가 달라 새 함수가 만들어지는 사고를 줄여준다.

### Q4. 추상 클래스에도 소멸자가 필요한가?

그렇다.
부모 타입으로 삭제할 가능성이 있으므로 보통 `virtual ~Base() {}` 형태로 둔다.

## 14. Lab 연결

- `lab01_redefine_no_virtual`
  - `virtual`이 없을 때 정적 바인딩 확인
- `lab02_virtual_overriding`
  - `virtual` + `override` + 동적 바인딩
- `lab03_paint_draw_dynamic`
  - 부모 함수 내부에서의 `virtual` 호출
- `lab04_grandderived_dynamic`
  - 다단계 상속에서 최종 오버라이딩 선택
- `lab05_scope_resolution_virtual`
  - `::`로 부모 버전 직접 호출
- `lab06_virtual_destructor`
  - 가상 소멸자의 필요성
- `lab07_pure_virtual_intro`
  - 순수 가상 함수와 추상 클래스
- `lab08_goodcalc_abstract`
  - 추상 클래스 인터페이스 구현
- `lab09_adder_subtractor_template_method`
  - 공통 흐름 + 가변 단계 분리

## 15. 한 줄 요약

9장은 "상속받은 클래스를 부모 타입으로 다루면서도, 실제 객체에 맞는 동작을 안전하게 호출하는 방법"을 배우는 장이다.
