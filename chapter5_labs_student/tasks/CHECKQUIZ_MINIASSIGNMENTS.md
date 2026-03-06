# C++ 5장 실습 체크퀴즈 & 미니과제 (학생용)

각 lab마다 **체크퀴즈 2개 + 미니과제 1개**가 있습니다.

---

## lab01_swap_by_value
### 체크퀴즈
1) 왜 swapByValue는 m,n을 바꾸지 못하나요?  
2) a,b는 m,n과 메모리 주소가 같나요?

### 미니과제
- swapByValue 안에서 a,b가 바뀌는 과정을 출력으로 보여주세요(함수 안 출력 추가).

---

## lab02_swap_by_address
### 체크퀴즈
1) swapByAddress는 왜 m,n을 바꿀 수 있나요?  
2) &m은 무엇을 의미하나요?

### 미니과제
- 포인터 값(a,b)과 역참조 값(*a,*b)을 출력해서 “주소 vs 값”을 보여주세요.

---

## lab03_pass_object_by_value
### 체크퀴즈
1) increase(waffle) 호출 시 복사 생성이 발생하나요? 왜 그런가요?  
2) waffle 반지름이 바뀌지 않는 이유는?

### 미니과제
- increase 함수에 `cout`을 넣어 함수 안에서 c의 반지름이 바뀌는지 출력해보세요.

---

## lab04_pass_object_by_address
### 체크퀴즈
1) 포인터 전달은 왜 복사본이 생기지 않나요?  
2) p->setRadius는 어떤 의미인가요?

### 미니과제
- increase 함수에 nullptr 방어 코드를 추가해보세요. (p==nullptr이면 return)

---

## lab05_return_object_and_assign
### 체크퀴즈
1) c = getCircle()에서 “대입”은 무엇을 복사하나요?  
2) 객체 리턴에서 복사가 생길 수도/안 생길 수도 있는 이유는?

### 미니과제
- Circle에 생성자/소멸자 메시지를 추가하고, 리턴/대입 과정에서 호출 흐름을 관찰해보세요.

---

## lab06_reference_basics
### 체크퀴즈
1) 참조는 새로운 변수를 만드는 건가요, 별명인가요?  
2) 참조는 왜 반드시 선언과 동시에 초기화해야 하나요?

### 미니과제
- refn의 주소와 n의 주소를 출력해서 같음을 확인하세요.

---

## lab07_swap_by_reference
### 체크퀴즈
1) swapByRef에서 a,b는 무엇의 별명인가요?  
2) 포인터 swap보다 문법상 어떤 장점이 있나요?

### 미니과제
- swapByRef를 이용해 int 3개를 순환 교환하는 함수를 만들어보세요(예: a<-b, b<-c, c<-a).

---

## lab08_average_ref_out
### 체크퀴즈
1) 평균 결과를 리턴으로 주지 않고 참조로 주는 장점은?  
2) size<=0이면 왜 false를 리턴하나요?

### 미니과제
- sum이 커질 수 있으니 sum을 long long으로 바꿔보세요.

---

## lab09_pass_object_by_reference
### 체크퀴즈
1) Circle&로 받으면 복사가 발생하나요?  
2) 소멸자 출력은 몇 번 찍힐까요? 이유는?

### 미니과제
- increaseCircle을 두 번 호출해 반지름이 2 증가하도록 해보세요.

---

## lab10_reference_return_global
### 체크퀴즈
1) 참조 리턴은 “값”을 리턴하나요 “공간”을 리턴하나요?  
2) 지역 변수 참조를 리턴하면 왜 위험한가요?

### 미니과제
- getValue()로 받은 값에 대입해도 g가 바뀌지 않는 걸 코드로 보여주세요.

---

## lab11_reference_return_array_elem
### 체크퀴즈
1) findAt(name,0) = 'S' 가 가능한 이유는?  
2) s[index]는 “값”인가요 “공간”인가요?

### 미니과제
- index를 입력받아 해당 위치 문자를 바꾸는 프로그램으로 확장해보세요.

---

## lab12_chaining_ref_return
### 체크퀴즈
1) return *this 는 무엇을 리턴하나요?  
2) 참조 리턴이 체이닝에 왜 필요하나요?

### 미니과제
- plus 대신 minus를 추가하고 a.plus(5).minus(2) 같은 체이닝을 해보세요.

---

## lab13_copy_ctor_called
### 체크퀴즈
1) 복사 생성자가 자동 호출되는 상황 2가지를 쓰세요.  
2) g()에서 CopyCtor가 출력되지 않을 수도 있는 이유는?

### 미니과제
- f(Person p) 대신 f(const Person& p)로 바꾸고 CopyCtor 출력이 어떻게 달라지는지 확인해보세요.

---

## lab14_shallow_copy_demo
### 체크퀴즈
1) 왜 딸(daughter) 생성에서 얕은 복사가 발생하나요?  
2) double delete는 왜 위험한가요?

### 미니과제
- 크래시가 무섭다면 소멸자에서 delete[]를 주석 처리하고, father/daughter가 같은 메모리를 공유하는 현상을 출력으로 설명해보세요(주소 출력).

---

## lab15_deep_copy_ok
### 체크퀴즈
1) 깊은 복사는 무엇이 달라지나요?  
2) 왜 double delete가 사라지나요?

### 미니과제
- 복사 생성자에서 name 메모리 주소를 출력해, father와 daughter가 다른 주소를 갖는지 확인해보세요.
