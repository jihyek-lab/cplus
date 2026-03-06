# C++ 10장 실습 체크퀴즈 & 미니과제 (학생용)

각 lab마다 체크퀴즈 2개 + 미니과제 1개.

---

## lab01_myswap_overload_problem
### 체크퀴즈
1) 왜 중복 함수가 문제인가요?  
2) 이런 중복이 많아지면 유지보수에서 어떤 일이 생기나요?

### 미니과제
- myswap(char&,char&)를 추가해보고, “복붙 증가” 문제를 느껴보세요.

---

## lab02_myswap_template
### 체크퀴즈
1) 템플릿에서 T는 무엇인가요?  
2) 구체화(instantiation)는 언제 일어나나요?

### 미니과제
- myswap(string&,string&)이 자동으로 되는지 테스트해보세요.

---

## lab03_myswap_with_class
### 체크퀴즈
1) 클래스 타입이 템플릿 swap이 되려면 어떤 연산이 가능해야 하나요?  
2) 포인터 멤버가 있는 클래스에서 주의할 점은? (5장 연결)

### 미니과제
- Circle에 이름(string) 멤버를 추가해도 swap이 되는지 확인해보세요.

---

## lab04_myswap_type_mismatch
### 체크퀴즈
1) myswap(int,double)이 왜 실패하나요?  
2) 해결하려면 템플릿을 어떻게 바꿔야 할까요?

### 미니과제
- myswap을 T1,T2로 받는 버전으로 직접 설계해보세요(힌트: mcopy처럼).

---

## lab05_bigger_template
### 체크퀴즈
1) bigger에서 T가 만족해야 하는 조건은?  
2) 사용자 정의 타입에서 bigger를 쓰려면 무엇이 필요할까요?

### 미니과제
- Circle을 비교하도록 operator>를 구현하고 bigger(Circle,Circle)을 테스트해보세요.

---

## lab06_add_array_template
### 체크퀴즈
1) sum 초기화에서 T sum=0의 문제점은?  
2) 더 일반적인 초기화는 무엇일까요?

### 미니과제
- sum 초기화를 T()로 바꾸고, int/double에서 결과가 같은지 확인해보세요.

---

## lab07_mcopy_two_types
### 체크퀴즈
1) 왜 타입 매개변수가 2개 필요한가요?  
2) (T2) 캐스팅의 위험은?

### 미니과제
- double 배열을 int 배열로 복사할 때 손실이 생기는 예를 만들어보세요.

---

## lab08_mystack_template_class
### 체크퀴즈
1) 템플릿 클래스는 어떻게 사용하는가(MyStack<int> 등)?  
2) pop이 빈 스택에서 T()를 리턴하면 어떤 문제가 있나요?

### 미니과제
- bool pop(T& out) 형태로 바꿔서 “성공/실패 + 결과” 패턴으로 개선해보세요.

---

## lab09_vector_basic
### 체크퀴즈
1) []와 at() 차이는?  
2) vector는 배열과 비교해 어떤 장점이 있나요?

### 미니과제
- v.at(100) 같은 코드를 넣어 예외/오류를 관찰하고 NOTES에 기록하세요.

---

## lab10_vector_string_lexico
### 체크퀴즈
1) string 비교는 어떤 기준인가요?  
2) 공백 포함 입력은 어떤 함수가 필요한가요?

### 미니과제
- 이름이 5개가 아니라 N개(사용자 입력)로 동작하도록 바꿔보세요.

---

## lab11_vector_iterator_double
### 체크퀴즈
1) iterator는 무엇인가요(포인터와 비슷한 점)?  
2) *it는 무엇을 의미하나요?

### 미니과제
- iterator 대신 range-based for로 같은 작업을 해보세요(비교).

---

## lab12_map_dictionary
### 체크퀴즈
1) find(key)==end()의 의미는?  
2) dic[key]가 위험할 수 있는 이유는?

### 미니과제
- dic[eng] 대신 find 결과 iterator를 사용해 출력하도록 바꿔보세요.

---

## lab13_map_inventory
### 체크퀴즈
1) erase(key)가 돌려주는 값은?  
2) stock[name]가 삽입을 일으킬 수 있는 이유는?

### 미니과제
- “입고 시 기존 상품이면 재고 누적” 기능을 추가해보세요.

---

## lab14_printMap_iterator
### 체크퀴즈
1) it->first / it->second는 무엇인가요?  
2) map은 왜 “정렬된” 순서로 출력될까요?

### 미니과제
- 가격이 가장 비싼 항목을 찾아 출력하세요.

---

## lab15_sort_vector_algorithm
### 체크퀴즈
1) sort의 범위는 어떤 형태인가요([begin,end))?  
2) sort가 기본적으로 사용하는 비교는?

### 미니과제
- 내림차순 정렬을 구현해보세요(greater<int> 또는 비교자 함수).
