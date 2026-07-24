# C++ 기말고사 예상문제

- 범위: `Chapter 7 ~ Chapter 10`
- 시간: `100분`
- 총 문항: `30문항`
- 구성: 객관식 `12문항`, 단답형 `8문항`, 부분코드 작성 `10문항`

## 유의사항

- 모든 문제는 별도의 답안지에 작성하시오.
- 객관식은 가장 알맞은 답 `1개만` 고르시오.
- 단답형은 핵심어 중심으로 간결하게 쓰시오.
- 부분코드 작성 문제는 전체를 새로 쓰기보다, 빈칸 또는 핵심 부분을 정확히 작성하시오.

## I. 객관식

### 1.
다음에서 `Power`는 클래스 이름이라고 하자.  
다음 중 `friend` 함수로 구현하는 것이 가장 자연스러운 것은?

A. `Power + Power`  
B. `Power + int`  
C. `int + Power`  
D. `Power.show()`

### 2.
다음 중 연산자 중복에 대한 설명으로 옳은 것은?

A. 모든 연산자는 새로 만들 수 있다  
B. `.` 연산자는 일반적으로 사용자 정의 중복이 가능하다  
C. 기존 연산자의 의미와 너무 동떨어진 중복은 바람직하지 않다  
D. 연산자 중복은 반드시 `friend` 함수로만 작성해야 한다

### 3.
다음 중 상속에서 생성자 호출 순서로 옳은 것은?

A. Derived 생성자 본문 -> Base 생성자  
B. Base 생성자 -> Derived 생성자 본문  
C. 멤버 함수 호출 순서에 따라 달라진다  
D. 컴파일러가 임의로 정한다

### 4.
다음 코드를 보고, `main()`에서 가능한 문장을 고르시오.

```cpp
class Base {
public:
    int x;
protected:
    int y;
};

class Derived : protected Base {
public:
    void set() {
        x = 10;
        y = 20;
    }
};

int main() {
    Derived d;
    // ?
}
```

A. `d.x = 1;` 만 가능하다  
B. `d.y = 2;` 만 가능하다  
C. `d.x = 1;`, `d.y = 2;` 둘 다 가능하다  
D. 둘 다 불가능하다

### 5.
다음 코드에서 `p->draw();` 호출 시 `Derived::draw()`가 실행되게 하는 가장 핵심 조건은?

```cpp
class Base {
public:
    void draw();
};
class Derived : public Base {
public:
    void draw();
};
Base* p = new Derived;
p->draw();
```

A. `draw()`를 `friend`로 선언한다  
B. `draw()`를 `virtual`로 선언한다  
C. `Derived`에 생성자를 추가한다  
D. `p`를 참조형으로 바꾼다

### 6.
기본 클래스 소멸자를 `virtual`로 선언해야 하는 대표 이유는?

A. 생성 속도를 높이기 위해  
B. 파생 클래스 객체를 기본 클래스 포인터로 `delete`할 때 올바른 소멸 순서를 보장하기 위해  
C. 다운캐스팅을 허용하기 위해  
D. `friend` 함수 사용을 허용하기 위해

### 7.
다음 중 추상 클래스에 대한 설명으로 옳은 것은?

A. 객체를 직접 생성할 수 있다  
B. 순수 가상 함수가 하나라도 있으면 추상 클래스가 된다  
C. 파생 클래스를 만들 수 없다  
D. 가상 함수가 있으면 모두 추상 클래스다

### 8.
다음 함수 템플릿 호출 중 컴파일 오류가 날 가능성이 가장 큰 것은?

```cpp
template <class T>
void myswap(T& a, T& b);
```

A. `int a=1, b=2; myswap(a,b);`  
B. `double a=1.1, b=2.2; myswap(a,b);`  
C. `int a=1; double b=2.2; myswap(a,b);`  
D. `char a='x', b='y'; myswap(a,b);`

### 9.
`vector`에 대한 설명으로 옳은 것은?

A. 크기가 절대 변하지 않는다  
B. `at()`은 범위 확인을 하지 않는다  
C. `push_back()`은 맨 뒤에 원소를 추가한다  
D. `[]`는 항상 예외를 발생시킨다

### 10.
`map<string,int> m;` 에서 조회만 하려는 상황에 `m[key]` 대신 `m.find(key)`를 더 권장하는 이유는?

A. `find()`만 반복자를 반환하기 때문에  
B. `m[key]`는 없는 key에 대해 새 원소를 삽입할 수 있기 때문에  
C. `find()`가 항상 더 빠르기 때문에  
D. `m[key]`는 `int` 타입에서만 동작하기 때문에

### 11.
다음 중 `v.end()`에 대한 설명으로 옳은 것은?

A. 마지막 원소를 가리킨다  
B. 첫 번째 원소를 가리킨다  
C. 마지막 원소의 다음 위치를 가리킨다  
D. 빈 벡터에서만 사용한다

### 12.
`vector<int> v;`를 내림차순 정렬하는 코드로 옳은 것은?

A. `sort(v.begin(), v.end(), less<int>());`  
B. `sort(v.begin(), v.end(), greater<int>());`  
C. `sort(v.end(), v.begin());`  
D. `reverse(v.begin(), v.end(), greater<int>());`

## II. 단답형

### 13.
다음 코드에서 업캐스팅에 해당하는 문장을 그대로 쓰시오.

```cpp
class Base {};
class Derived : public Base {};

int main() {
    Derived d;
    Base* p = &d;
    Derived* q = &d;
}
```

### 14.
다음 코드가 위험한 이유를 한 줄로 쓰시오.

```cpp
class Base {};
class Derived : public Base {};

int main() {
    Base b;
    Base* p = &b;
    Derived* q = (Derived*)p;
}
```

### 15.
다음 코드의 출력 결과를 쓰시오.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void f() { cout << "Base"; }
};

class Derived : public Base {
public:
    void f() { cout << "Derived"; }
};

int main() {
    Base* p = new Derived;
    p->f();
}
```

### 16.
다음 클래스에서 `draw()`를 순수 가상 함수로 선언하는 한 줄을 쓰시오.

```cpp
class Shape {
public:
    // 여기에 작성
};
```

### 17.
다음 코드에서 빈칸에 들어갈 키워드를 쓰시오.

```cpp
class Base {
public:
    ______ ~Base() {}
};
```

조건: `Base* p = new Derived; delete p;` 상황을 고려한다.

### 18.
다음 코드가 컴파일 오류가 나는 이유를 간단히 쓰시오.

```cpp
template <class T>
void myswap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 3;
    double b = 4.5;
    myswap(a, b);
}
```

### 19.
다음 코드 실행 후 빈칸에 들어갈 값을 쓰시오.

```cpp
map<string, int> m;
m["lee"] = 80;
m["kim"] = 90;
m["park"] = 70;
map<string, int>::iterator it = m.begin();
```

- `it->first` 는 `__________`
- `it->second` 는 `__________`

### 20.
다음 코드에서 `v.end()`가 가리키는 위치를 짧게 설명하시오.

```cpp
vector<int> v;
v.push_back(10);
v.push_back(20);
v.push_back(30);
```

## III. 부분코드 작성

### 21.
다음 `Power` 클래스에서 `+` 연산자를 멤버 함수로 완성하시오.

```cpp
class Power {
    int kick;
    int punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    Power operator+(Power op2) {
        // 빈칸 완성
    }
};
```

### 22.
다음 `Power` 클래스에서 `int + Power`가 가능하도록 코드를 완성하시오.

```cpp
class Power {
    int kick;
    int punch;
public:
    Power(int k=0, int p=0) : kick(k), punch(p) {}
    // 클래스 안에서 필요한 선언 및 작성을 완성하시오.
    // op1을 kick, punch에 모두 더한 새 Power 객체를 반환해야 한다.
};
```

### 23.
다음 코드에서 Base 생성자를 올바르게 호출하도록 Derived 생성자를 완성하시오.

```cpp
class Base {
    int x;
public:
    Base(int x) : x(x) {}
};

class Derived : public Base {
    int y;
public:
    Derived(int x, int y)
        // 빈칸 완성
    {
    }
};
```

### 24.
동적 바인딩이 일어나도록 필요한 부분만 고쳐 쓰시오.

```cpp
class Base {
public:
    void f() { cout << "Base" << endl; }
};

class Derived : public Base {
public:
    void f() { cout << "Derived" << endl; }
};
```

조건: `Base* p = new Derived; p->f();` 호출 시 `Derived`가 출력되어야 한다.

### 25.
다음 코드에서 메모리 해제를 안전하게 하기 위해 필요한 선언을 쓰시오.

```cpp
class Base {
public:
    // 빈칸
};

class Derived : public Base {
public:
    ~Derived() { cout << "Derived destructor" << endl; }
};
```

조건: `Base* p = new Derived; delete p;` 를 고려한다.

### 26.
다음 추상 클래스와 파생 클래스를 완성하시오.

```cpp
class Calculator {
public:
    // 두 정수를 받아 결과를 돌려주는 순수 가상 함수 선언
};

class Adder : public Calculator {
public:
    // 오버라이딩 구현
};
```

조건: `Adder`는 두 수의 합을 반환해야 한다.

### 27.
다음 함수 템플릿 `bigger`를 완성하시오.

```cpp
template <class T>
T bigger(T a, T b) {
    // 큰 값을 반환하도록 작성
}
```

### 28.
다음 `vector<int>`를 오름차순 정렬한 뒤 `iterator`로 출력하는 코드를 완성하시오.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(4);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);

    // 1) sort 호출
    // 2) iterator를 사용해 출력
}
```

### 29.
다음 `map<string,int>`에서 `"kim"`의 점수를 `find()`로 조회하는 코드를 완성하시오.

```cpp
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string,int> score;
    score["lee"] = 90;
    score["kim"] = 80;

    // find를 사용해서 "kim"이 있으면 점수를 출력하고,
    // 없으면 "없음"을 출력하는 코드 작성
}
```

### 30.
다음 `vector<int>`에서 모든 원소를 `iterator`로 순회하며 2배로 만드는 코드를 완성하시오.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    // iterator를 사용하여 모든 원소를 2배로 만들기

    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << ' ';
}
```
