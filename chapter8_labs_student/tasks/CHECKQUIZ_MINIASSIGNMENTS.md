# C++ 8장 실습 체크퀴즈 & 미니과제 (학생용)

각 lab마다 체크퀴즈 2개 + 미니과제 1개.

---

## lab01_point_colorpoint
### 체크퀴즈
1) 파생 클래스 객체가 기본 클래스 멤버를 포함한다는 말은 무슨 뜻?  
2) base의 private 멤버를 derived가 직접 접근할 수 없는 이유는?

### 미니과제
- Point에 getX/getY를 추가하고 ColorPoint가 이를 이용해 출력하도록 바꿔보세요.

---

## lab02_upcasting
### 체크퀴즈
1) 업캐스팅이 자동인 이유는?  
2) Base*로는 왜 derived 멤버를 호출할 수 없나요?

### 미니과제
- Base*로 showPoint를 호출했을 때와 Derived*로 showColorPoint 호출 결과를 비교 출력해보세요.

---

## lab03_downcasting
### 체크퀴즈
1) 다운캐스팅이 위험한 이유는?  
2) 안전하게 다운캐스팅하려면 어떤 기능이 필요할까요?

### 미니과제
- “잘못된 다운캐스팅”이 왜 위험한지 설명만 NOTES에 적으세요(코드로 재현은 금지).

---

## lab04_protected_access
### 체크퀴즈
1) protected는 누가 접근 가능한가요?  
2) 왜 파생 클래스 객체라도 외부에서 a.x는 불가능한가요?

### 미니과제
- equals에 color도 포함하지 않는 버전(좌표만 비교) 함수를 하나 더 만들어보세요.

---

## lab05_ctor_dtor_order
### 체크퀴즈
1) 생성 순서/소멸 순서를 적으세요.  
2) 왜 이런 순서인가요?

### 미니과제
- 생성자/소멸자에 id를 넣어 출력 흐름을 더 명확히 하세요.

---

## lab06_no_default_base_ctor_error
### 체크퀴즈
1) 왜 컴파일이 실패하나요?  
2) 해결은 어떻게 하나요?

### 미니과제
- 이 코드에 “해결”을 직접 적용해보세요(초기화 리스트 추가). (lab07 참고)

---

## lab07_fix_with_init_list
### 체크퀴즈
1) : A(x+3)는 무엇을 의미하나요?  
2) B 생성자 본문보다 A 생성자가 먼저 실행되는 이유는?

### 미니과제
- A(x+3) 대신 A(x*2)로 바꿔 결과를 비교해보세요.

---

## lab08_tv_wide_smart
### 체크퀴즈
1) SmartTV 생성 시 어떤 생성자들이 순서대로 호출되나요?  
2) WideTV(size,true)에서 true 의미는?

### 미니과제
- SmartTV에 “모델명(model)” 멤버를 추가하고 출력해보세요.

---

## lab09_inheritance_modes
### 체크퀴즈
1) public/protected/private 상속의 차이는?  
2) D2/D3에서 pub()가 외부에서 안 되는 이유는?

### 미니과제
- D2에서 pub()를 외부에서 쓰고 싶다면 어떤 방식으로 래핑할 수 있나요? (힌트: public wrapper)

---

## lab10_multiple_inheritance_calculator
### 체크퀴즈
1) 다중 상속의 장점은?  
2) 단점/위험성 1가지는?

### 미니과제
- 곱셈을 지원하는 Multiplier 클래스를 추가해 Calculator가 '*'도 처리하게 해보세요.

---

## lab11_diamond_virtual_inheritance
### 체크퀴즈
1) D_bad에서 e.x가 모호한 이유는?  
2) virtual 상속이 이를 어떻게 해결하나요?

### 미니과제
- D_good에서 Bv/Cv 각각을 통해 A::x에 접근 가능한지 실험하고 NOTES에 결과를 적으세요.
