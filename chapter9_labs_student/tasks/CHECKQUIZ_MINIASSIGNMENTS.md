# C++ 9장 실습 체크퀴즈 & 미니과제 (학생용)

각 lab마다 체크퀴즈 2개 + 미니과제 1개.

---

## lab01_redefine_no_virtual
### 체크퀴즈
1) 왜 Base*로 f()를 호출하면 Base::f()가 실행되나요?  
2) 이 상황을 “정적 바인딩”이라고 부르는 이유는?

### 미니과제
- Derived에 f(int) 오버로딩을 추가한 뒤, Base*에서 호출이 어떻게 되는지 실험하고 NOTES에 정리하세요.

---

## lab02_virtual_overriding
### 체크퀴즈
1) virtual이 있으면 왜 Derived::f()가 실행되나요?  
2) override 키워드는 어떤 실수를 막아주나요?

### 미니과제
- Derived의 f 시그니처를 일부러 틀리게 만들고(예: f(int)), override가 어떤 에러를 주는지 확인하세요.

---

## lab03_paint_draw_dynamic
### 체크퀴즈
1) paint()는 Base 함수인데 왜 Circle::draw()가 실행되나요?  
2) “동적 바인딩”이 일어나는 지점은 어디인가요?

### 미니과제
- Rectangle 클래스를 추가하고 draw()를 오버라이드해서 p2를 Rectangle로 바꿔 실험하세요.

---

## lab04_grandderived_dynamic
### 체크퀴즈
1) 최종 오버라이딩이 선택된다는 말은?  
2) Base* / Derived*로 호출해도 같은 결과가 되는 이유는?

### 미니과제
- GrandDerived에서 f()를 제거하면 어떤 결과가 되는지 실험하고 NOTES에 정리하세요.

---

## lab05_scope_resolution_virtual
### 체크퀴즈
1) p->Shape::draw()는 왜 동적 바인딩이 아닌가요?  
2) 파생에서 부모 기능을 재사용하는 장점은?

### 미니과제
- Circle::draw()에서 Shape::draw()를 제거하고 출력이 어떻게 바뀌는지 비교하세요.

---

## lab06_virtual_destructor
### 체크퀴즈
1) Base 소멸자가 virtual이 아니면 어떤 문제가 생기나요?  
2) 왜 “Base*로 delete”가 핵심 위험 시나리오인가요?

### 미니과제
- Base 소멸자에서 virtual을 제거한 버전을 따로 만들어(새 파일) 문제를 설명만 하세요. (실제로 크래시 유도는 금지)

---

## lab07_pure_virtual_intro
### 체크퀴즈
1) 순수 가상 함수는 어떻게 선언하나요?  
2) 추상 클래스는 왜 객체 생성이 안 되나요?

### 미니과제
- Shape에 순수 가상 함수 하나를 더 추가하고, Circle이 모두 구현하도록 수정하세요.

---

## lab08_goodcalc_abstract
### 체크퀴즈
1) GoodCalc가 구현해야 하는 함수는 몇 개인가요?  
2) 왜 Calculator*로 GoodCalc를 가리키는 것이 유용한가요?

### 미니과제
- average에서 size==0이면 0을 리턴하도록 방어 코드를 추가하세요.

---

## lab09_adder_subtractor_template_method
### 체크퀴즈
1) run()이 제공하는 공통 흐름은 무엇인가요?  
2) calc()를 protected로 둔 이유는?

### 미니과제
- Multiplier 클래스를 추가해서 곱셈 버전도 run()으로 실행되게 하세요.
