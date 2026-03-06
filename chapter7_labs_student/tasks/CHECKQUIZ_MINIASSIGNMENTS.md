# C++ 7장 실습 체크퀴즈 & 미니과제 (학생용)

각 lab마다 체크퀴즈 2개 + 미니과제 1개.

---

## lab01_friend_global_equals
### 체크퀴즈
1) friend 함수는 멤버 함수인가요?  
2) 전방 선언(class Rect;)이 필요한 이유는?

### 미니과제
- equals에 const 참조를 적용해 `bool equals(const Rect& r, const Rect& s)`로 바꿔보세요.

---

## lab02_friend_other_class_member
### 체크퀴즈
1) RectManager 전체를 friend로 주는 것과 차이는?  
2) friend bool RectManager::equals(...) 문법이 왜 필요한가요?

### 미니과제
- RectManager에 `area(Rect)` 함수를 추가하고, 그 함수만 friend로 초대해 넓이를 출력해보세요.

---

## lab03_friend_whole_class
### 체크퀴즈
1) friend class RectManager의 장점/단점 1개씩  
2) 캡슐화 관점에서 왜 위험할까요?

### 미니과제
- copy 대신 `swap(Rect&,Rect&)`를 RectManager에 추가해 두 Rect를 바꿔보세요.

---

## lab04_power_plus_member
### 체크퀴즈
1) a+b는 어떤 형태로 변환되나요?  
2) 멤버 operator+에서 매개변수는 어떤 피연산자에 해당하나요?

### 미니과제
- operator+의 인자를 `const Power&`로 바꾸고 내부 로직을 수정해보세요.

---

## lab05_power_equal_member
### 체크퀴즈
1) operator==는 보통 const 멤버로 만드는 이유는?  
2) const&로 받는 이유는?

### 미니과제
- operator!= 를 추가하고, a!=b 테스트를 해보세요.

---

## lab06_power_plus_equal
### 체크퀴즈
1) +=가 참조를 리턴하는 이유는?  
2) const 멤버로 만들 수 있나요? 왜?

### 미니과제
- `a += b += c;` 가 되게 테스트 코드를 추가해보세요(되게/안되게 둘 다 관찰).

---

## lab07_power_plus_int_member
### 체크퀴즈
1) 왜 a+2는 멤버로 되나요?  
2) 왜 2+a는 멤버로 안 되나요?

### 미니과제
- a+2 뿐 아니라 a-2도 되도록 operator-를 추가해보세요.

---

## lab08_power_int_plus_friend
### 체크퀴즈
1) friend로 구현하면 좋은 점은?  
2) friend 없이 구현하려면 어떤 설계가 필요할까요?

### 미니과제
- friend 없이 구현해보기(예: getter 제공 후 외부 operator+ 작성).

---

## lab09_prefix_inc_member
### 체크퀴즈
1) 전위 ++ 시그니처는?  
2) 전위가 보통 참조를 리턴하는 이유는?

### 미니과제
- 전위 ++를 두 번 적용해 결과를 출력해보세요(++(++a)).

---

## lab10_not_operator_member
### 체크퀴즈
1) ! 연산자 리턴 타입은 보통 무엇인가요?  
2) 이 예제에서 !의 의미는?

### 미니과제
- Power가 0이면 true가 아니라 false가 되게 의미를 바꿔보고, 혼동 포인트를 NOTES에 적어보세요.

---

## lab11_postfix_inc_member
### 체크퀴즈
1) 후위 ++는 왜 int 매개변수가 들어가나요?  
2) 후위는 보통 무엇을 리턴하나요?

### 미니과제
- a++과 ++a의 차이를 한 번 더 명확히 출력하는 테스트를 추가해보세요.

---

## lab12_inc_friend
### 체크퀴즈
1) friend로 구현한 ++에서 매개변수 구조는?  
2) 전위/후위 리턴 타입은 보통 어떻게 다르나요?

### 미니과제
- friend로 --(전위/후위)를 구현해보세요.

---

## lab13_shiftleft_chain
### 체크퀴즈
1) 체이닝을 위해 왜 참조 리턴이 필요한가요?  
2) <<를 이렇게 재정의하면 어떤 오해가 생기나요?

### 미니과제
- 의미가 덜 헷갈리도록 `add(int)` 멤버 함수를 만들고 체이닝(add(3).add(5))으로 바꿔보세요.
