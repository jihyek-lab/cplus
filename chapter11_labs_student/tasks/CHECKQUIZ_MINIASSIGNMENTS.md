# C++ 11장 실습 체크퀴즈 & 미니과제 (학생용)

각 lab마다 체크퀴즈 2개 + 미니과제 1개.

---

## lab01_ostream_put_write
### 체크퀴즈
1) put과 write의 차이는?  
2) flush는 왜 필요할 때가 있나요?

### 미니과제
- write로 문자열 중간 부분만 출력하는 예를 2개 더 만들어보세요.

---

## lab02_istream_get_line
### 체크퀴즈
1) cin.get()이 int를 리턴하는 이유는?  
2) '
'을 만났을 때 루프를 끝내는 이유는?

### 미니과제
- Enter를 만나기 전까지 “문자 개수”를 세어서 출력해보세요.

---

## lab03_get_charptr_ignore
### 체크퀴즈
1) get(buf,n)이 '
'을 버퍼에 남기는 이유는?  
2) ignore(1)을 안 하면 어떤 문제가 생기나요?

### 미니과제
- ignore(1) 대신 ignore(80,'
')로 바꿔 차이를 관찰하세요.

---

## lab04_getline_echo
### 체크퀴즈
1) getline은 '
'을 버퍼에 남기나요?  
2) 공백 포함 입력을 왜 안정적으로 할 수 있나요?

### 미니과제
- 입력이 빈 문자열이면 “빈 줄입니다”를 출력하도록 바꿔보세요.

---

## lab05_gcount_ignore
### 체크퀴즈
1) gcount는 무엇을 리턴하나요?  
2) ignore(n,delim)의 의미는?

### 미니과제
- ignore를 (n, delim) 버전으로 바꿔서 특정 문자까지 건너뛰는 예를 만들어보세요.

---

## lab06_setf_unsetf
### 체크퀴즈
1) setf로 설정한 플래그는 왜 다음 출력에도 영향을 주나요?  
2) showbase/uppercase의 효과는?

### 미니과제
- 출력을 다시 “원래 상태(10진, 기본)”로 되돌리는 코드를 추가해보세요.

---

## lab07_width_fill_precision
### 체크퀴즈
1) width가 1회성인 이유는?  
2) fill/precision이 유지되는 이유는?

### 미니과제
- precision을 2, 5, 10으로 바꿔 출력 차이를 NOTES에 정리하세요.

---

## lab08_manipulators_basic
### 체크퀴즈
1) 매개변수 없는 조작자와 있는 조작자 차이는?  
2) 왜 <iomanip>이 필요한가요?

### 미니과제
- 표 출력을 0~100까지 확장하고, 3진수(직접 변환)도 한 열 추가해보세요(도전).

---

## lab09_point_ostream
### 체크퀴즈
1) operator<<가 ostream&를 리턴해야 하는 이유는?  
2) friend가 필요한 이유는?

### 미니과제
- Point를 “x=3,y=4” 형태로도 출력하는 모드를 추가해보세요(조작자 아이디어).

---

## lab10_book_ostream
### 체크퀴즈
1) << 오버로딩이 클래스 설계에 주는 장점은?  
2) CSV처럼 출력할 때 주의할 점은?

### 미니과제
- Book에 페이지 수(int pages) 추가하고 출력 형식을 업데이트하세요.

---

## lab11_point_istream_ostream
### 체크퀴즈
1) operator>>가 Point&를 받는 이유는?  
2) istream&를 리턴해야 체이닝이 되는 이유는?

### 미니과제
- 입력 형식을 “(x,y)” 형태로 받도록 파싱을 도전해보세요.

---

## lab12_custom_manipulators
### 체크퀴즈
1) 사용자 정의 조작자 시그니처는?  
2) beep가 항상 소리를 내지 않는 이유는?

### 미니과제
- 10개 별을 출력하는 tenstar 조작자를 만들어보세요.

---

## lab13_istream_manipulator_question
### 체크퀴즈
1) 입력 조작자 시그니처는?  
2) cin >> question >> answer에서 question은 실제로 무엇을 하나요?

### 미니과제
- question 조작자가 “(yes/no)” 같은 프롬프트를 띄우고, 입력을 검사하는 형태로 확장해보세요.
