# C++ 4장 실습 체크퀴즈 & 미니과제 (학생용)

각 lab마다 **체크퀴즈 2개 + 미니과제 1개**가 있습니다.
정답은 한 가지가 아닙니다. 요구 의도를 충족하면 됩니다.

---

## lab01_object_pointer
### 체크퀴즈
1) `p->getArea()`와 `(*p).getArea()`는 어떤 관계인가요?  
2) `Circle* p = &donut;`에서 `&`는 무엇을 의미하나요?

### 미니과제
- `Circle* p`가 가리키는 객체의 넓이가 100 이상이면 `"big"`을 출력하도록 조건문을 추가해보세요.

---

## lab02_object_array
### 체크퀴즈
1) `Circle circleArray[3];`에서 기본 생성자는 몇 번 호출되나요?  
2) `Circle* p = circleArray;`가 가능한 이유는 무엇인가요?

### 미니과제
- 포인터 순회 부분에서 `p++` 대신 `p = p + 1` 형태로 바꿔도 동작하는지 확인해보세요.

---

## lab03_array_needs_default_ctor
### 체크퀴즈
1) 왜 기본 생성자가 없으면 객체 배열을 만들 수 없나요?  
2) `Circle waffle(15);`는 왜 되나요?

### 미니과제
- `Circle()` 기본 생성자를 추가해서 `Circle circleArray[3];`가 되도록 고쳐보세요.

---

## lab04_array_init
### 체크퀴즈
1) `{ Circle(10), Circle(20), Circle() }`에서 각 원소는 어떤 생성자를 호출하나요?  
2) 배열 초기화에서 기본 생성자가 필요한 경우/필요 없는 경우를 설명해보세요.

### 미니과제
- 배열을 `{ Circle(10), Circle(20), Circle(30) }`으로 바꾸고 기본 생성자를 제거해도 되는지 실험해보세요.

---

## lab05_2d_object_array
### 체크퀴즈
1) `Circle circles[2][3];`에서 기본 생성자는 총 몇 번 호출되나요?  
2) `circles[i][j]` 접근은 메모리 상에서 어떤 형태(연속 배열)로 저장될까요?

### 미니과제
- 반지름을 1~6 대신 사용자가 입력한 시작값부터 증가하도록 수정해보세요.

---

## lab06_new_delete_int
### 체크퀴즈
1) `new int`로 할당한 메모리는 어디(스택/힙)에 있나요?  
2) `delete p;` 후 `*p`에 접근하면 왜 위험한가요?

### 미니과제
- `delete p;` 다음에 `p = nullptr;`을 추가하고, `if (p == nullptr)` 체크로 안전함을 보여주세요.

---

## lab07_delete_pitfalls
### 체크퀴즈
1) `int* p1 = &n; delete p1;`이 왜 위험한가요?  
2) double free가 왜 위험한가요?

### 미니과제
- `p2`를 delete한 후 `p2 = nullptr;`을 넣고, 다시 delete하기 전에 nullptr인지 검사하는 방어 코드를 추가해보세요.

---

## lab08_new_delete_array
### 체크퀴즈
1) 배열 반환에 `delete[]`가 필요한 이유는?  
2) `new int[n]`로 만든 배열은 어떻게 접근하나요?

### 미니과제
- 평균뿐 아니라 최댓값(max)도 함께 출력하도록 수정해보세요.

---

## lab09_dynamic_object
### 체크퀴즈
1) `new Circle(r)`는 어떤 일을 순서대로 하나요? (할당 + 생성자)  
2) `delete p`는 어떤 일을 순서대로 하나요? (소멸자 + 반환)

### 미니과제
- `Circle`에 `setRadius`를 추가하고, 생성 후 반지름을 한 번 더 바꾼 뒤 넓이를 출력해보세요.

---

## lab10_dynamic_object_array
### 체크퀴즈
1) `new Circle[n]`은 생성자를 몇 번 호출하나요? 어떤 생성자죠?  
2) `delete[] arr`는 소멸자를 어떤 순서로 호출할까요?

### 미니과제
- 100~200 개수뿐 아니라, 그 조건을 만족하는 원의 인덱스도 출력해보세요.

---

## lab11_this_pointer
### 체크퀴즈
1) this는 무엇을 가리키나요? 어디에서만 사용 가능한가요?  
2) `this->radius = radius;`에서 왼쪽/오른쪽 radius는 각각 무엇인가요?

### 미니과제
- `Circle& setRadiusChain(int r)` 처럼 **자기 자신 참조를 반환**해서 `c.setRadiusChain(3).setRadiusChain(4);`가 되게 만들어보세요.

---

## lab12_string_basics
### 체크퀴즈
1) `string`이 `char[]`보다 좋은 점 2가지를 쓰세요.  
2) `append`는 무엇을 하나요?

### 미니과제
- 사용자가 입력한 이름을 받아 `"Hello, <name>!"`을 출력해보세요.

---

## lab13_stoi
### 체크퀴즈
1) stoi는 무엇을 하나요?  
2) 숫자가 아닌 문자열이면 어떤 일이 생길 수 있나요?

### 미니과제
- 두 문자열 숫자를 입력받아 합을 출력해보세요. (예: "12"와 "34" → 46)

---

## lab14_string_array_lexico
### 체크퀴즈
1) `getline`은 어떤 입력에 유리한가요?  
2) string 비교(`<`)는 어떤 기준인가요?

### 미니과제
- 가장 뒤 문자열뿐 아니라 가장 앞 문자열도 함께 출력해보세요.

---

## lab15_rotate_string
### 체크퀴즈
1) substr(pos,len)은 무엇을 반환하나요?  
2) 회전을 len번 반복하면 어떤 현상이 생기나요?

### 미니과제
- 오른쪽 회전(마지막 글자를 앞으로)으로 바꾸어 구현해보세요.

---

## lab16_parse_sum_expression
### 체크퀴즈
1) find가 -1을 반환하는 의미는?  
2) startIndex를 왜 갱신하나요?

### 미니과제
- 공백이 포함된 식(예: "7 + 23 + 5")도 처리되도록 공백을 제거하거나 건너뛰는 로직을 추가해보세요.

---

## lab17_find_replace_multiline
### 체크퀴즈
1) getline(cin, s, '&')는 어떤 동작을 하나요?  
2) replace 후 startIndex를 이동시키는 이유는?

### 미니과제
- 대소문자 구분 없이 찾기(예: 모두 소문자로 바꿔서 처리) 중 한 가지 방식으로 확장해보세요.
