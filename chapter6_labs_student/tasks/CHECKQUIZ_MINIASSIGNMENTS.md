# C++ 6장 실습 체크퀴즈 & 미니과제 (학생용)

각 lab마다 체크퀴즈 2개 + 미니과제 1개.
(정답은 1개가 아니며, 의도 충족이 우선입니다.)

---

## lab01_sum_overload_ok
### 체크퀴즈
1) 오버로딩 구분 기준은 무엇인가요?  
2) 리턴 타입은 오버로딩 구분 기준이 될 수 있나요?

### 미니과제
- sum(long long, long long) 버전을 추가해서 큰 수 합도 안전하게 처리해보세요.

---

## lab02_overload_fail_return_type
### 체크퀴즈
1) 왜 컴파일이 실패하나요?  
2) 이런 상황을 해결하려면 어떤 방법이 있나요? (함수 이름 변경, 템플릿 등)

### 미니과제
- 두 함수 이름을 바꿔서(예: sumInt, sumDouble) 컴파일이 되게 만들고 비교 출력해보세요.

---

## lab03_big_overload
### 체크퀴즈
1) big(array,5)는 어떤 함수가 호출되나요?  
2) 배열 버전에서 size가 0이면 어떤 문제가 생길까요?

### 미니과제
- size<=0이면 -1을 리턴하도록 방어 코드를 추가해보세요.

---

## lab04_sum_range_overload
### 체크퀴즈
1) sum(3)과 sum(3,5)는 어떤 차이가 있나요?  
2) 오버로딩이지만 의미가 비슷해서 헷갈릴 수 있는 이유는?

### 미니과제
- sum(a,b)에서 a>b인 경우도 처리하도록 (swap 후 계산 등) 개선해보세요.

---

## lab05_default_param_basic
### 체크퀴즈
1) 디폴트 값은 보통 선언부(원형)에 두는 이유는?  
2) star() 호출은 어떤 함수 호출로 해석되나요?

### 미니과제
- msg(id,text="") 대신 msg(id, prefix="ID:", text="") 형태로 확장해보세요.

---

## lab06_default_param_rules
### 체크퀴즈
1) 왜 디폴트 매개변수는 뒤쪽부터만 가능한가요?  
2) calc(10,5,20,30)의 각 인수는 어디에 들어가나요?

### 미니과제
- calc를 수정해서 calc(10, /*b 생략*/, 20) 같은 호출이 가능하게 설계를 고민해보세요(오버로딩/함수 분리 등).

---

## lab07_ambiguity_default_param
### 체크퀴즈
1) msg(6)이 왜 모호한가요?  
2) 모호성을 없애는 방법 2가지를 제시해보세요.

### 미니과제
- msg(6) 호출이 되도록 함수 구성을 바꿔보세요(오버로딩 제거, 디폴트 제거 등).

---

## lab08_ambiguity_cast
### 체크퀴즈
1) square(3)은 왜 모호할 수 있나요?  
2) 명시적 캐스팅으로 해결하는 방법은?

### 미니과제
- square(3) 호출을 캐스팅으로 해결한 버전을 작성해보세요.

---

## lab09_ambiguity_ref_param
### 체크퀴즈
1) 왜 값/참조 오버로딩은 위험할까요?  
2) 대안은 무엇인가요?

### 미니과제
- addInPlace(int a, int& b)처럼 이름을 분리해 설계를 개선해보세요.

---

## lab10_fillline_default
### 체크퀴즈
1) 디폴트 매개변수로 어떤 “중복”이 사라졌나요?  
2) fillLine(10)만 호출하려면 어떤 선언이 필요할까요?

### 미니과제
- fillLine(n)만 주면 문자를 '-'로 출력하도록 디폴트를 조정해보세요.

---

## lab11_myvector_default_ctor
### 체크퀴즈
1) 이 설계가 어떤 중복을 줄이나요?  
2) 이 클래스는 복사 시 어떤 위험이 있을까요? (5장 연결)

### 미니과제
- size만큼 0으로 초기화하는 코드를 추가해보세요.

---

## lab12_static_member_basic
### 체크퀴즈
1) sharedMoney는 객체마다 따로인가요, 공유인가요?  
2) static 멤버 변수를 클래스 밖에서 정의하지 않으면 어떤 오류가 날까요?

### 미니과제
- sharedMoney를 증가시키는 함수를 하나 더 만들고, 여러 객체에서 호출해도 공유됨을 보여주세요.

---

## lab13_static_access_classscope
### 체크퀴즈
1) ClassName:: 접근이 가능한 이유는?  
2) non-static 멤버는 왜 ClassName::로 못 접근하나요?

### 미니과제
- Person::sharedMoney를 출력하는 printShared() static 함수를 만들어보세요.

---

## lab14_math_static_class
### 체크퀴즈
1) static 함수를 쓰는 이유는?  
2) 전역 함수를 줄이면 어떤 장점이 있나요?

### 미니과제
- Math::clamp(x, lo, hi) 함수를 추가해보세요.

---

## lab15_count_objects_static
### 체크퀴즈
1) new Circle[10]에서 생성자는 몇 번 호출되나요?  
2) delete[]에서 소멸자는 몇 번 호출되나요?

### 미니과제
- 스코프 블록 { }을 써서 지역 Circle이 생겼다 사라질 때 개수가 변하는지 확인해보세요.

---

## lab16_static_cannot_access_this
### 체크퀴즈
1) static 함수에 this가 없는 이유는?  
2) static에서 non-static 멤버에 접근하려면 어떤 정보가 필요할까요?

### 미니과제
- static 함수에 PersonError*를 인자로 받아 money를 읽는 형태로 설계를 바꿔보세요.
