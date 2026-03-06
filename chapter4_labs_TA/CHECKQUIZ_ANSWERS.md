# CHECKQUIZ_ANSWERS (4장)

> 학생 답이 표현이 달라도 핵심이 맞으면 정답 처리하세요.

## lab01_object_pointer
1) `p->getArea()`와 `(*p).getArea()` 관계  
- 동일 의미. `->`는 `(*p).`의 축약 문법. `(*p)` 괄호 필수.

2) `&donut`에서 `&` 의미  
- 변수/객체의 **주소(address)**를 얻는 연산자.

## lab02_object_array
1) 기본 생성자 호출 횟수  
- 3번(원소 3개).

2) `Circle* p = circleArray;` 가능한 이유  
- 배열 이름은 첫 원소의 주소로 변환(decay)되기 때문.

## lab03_array_needs_default_ctor
1) 기본 생성자 없으면 배열 생성 불가 이유  
- 배열의 각 원소를 매개변수 없이 생성해야 하므로 `Circle()`이 필요.

2) waffle은 왜 되나  
- `Circle(int)` 생성자가 존재하고 해당 생성자로 직접 생성하기 때문.

## lab04_array_init
1) 각 원소 생성자  
- Circle(10) → Circle(int), Circle(20) → Circle(int), Circle() → 기본 생성자.

2) 기본 생성자 필요한 경우/불필요한 경우  
- 배열 초기화 목록에 `Circle()` 같은 기본 생성이 포함되면 필요.
- 모든 원소가 `Circle(int)` 등 매개변수 생성자로 채워지면 기본 생성자 없이도 가능.

## lab05_2d_object_array
1) 기본 생성자 호출 횟수  
- 2*3 = 6번.

2) 저장 형태  
- 보통 row-major로 연속 메모리에 저장(2차원도 내부적으로 연속 배열).

## lab06_new_delete_int
1) new로 할당한 메모리 위치  
- 힙(heap).

2) delete 후 접근 위험  
- 해제된 메모리를 가리켜 댕글링 포인터/정의되지 않은 동작.

## lab07_delete_pitfalls
1) &n을 delete 위험 이유  
- n은 스택(자동) 메모리. delete는 new로 할당한 메모리에만 사용해야 함.

2) double free 위험  
- 같은 메모리를 두 번 해제하면 메모리 관리자 상태가 깨져 크래시/보안 취약점 가능.

## lab08_new_delete_array
1) delete[] 필요한 이유  
- 배열 요소 수/해제 방식이 단일 객체와 달라 올바른 해제/소멸 처리 위해.

2) 배열 접근 방식  
- p[i] 또는 *(p+i).

## lab09_dynamic_object
1) new Circle(r) 순서  
- (a) 메모리 할당 (b) 생성자 호출.

2) delete p 순서  
- (a) 소멸자 호출 (b) 메모리 해제.

## lab10_dynamic_object_array
1) 생성자 호출 횟수/종류  
- n번, 기본 생성자(매개변수 없는 생성자).

2) delete[] 소멸자 호출 순서  
- 일반적으로 역순(LIFO)으로 각 원소 소멸자 호출 후 해제.

## lab11_this_pointer
1) this 의미/사용 위치  
- 현재 멤버 함수를 실행 중인 **객체 자신**을 가리키는 포인터. 멤버 함수 내부에서만 의미.

2) this->radius = radius; 왼쪽/오른쪽  
- 왼쪽: 멤버 변수 radius, 오른쪽: 매개변수 radius.

## lab12_string_basics
1) string 장점 2가지  
- 길이 자동 관리(버퍼 오버플로우 위험 감소), +/==/append 등 편리한 연산, 복사/대입 쉬움 등.

2) append 기능  
- 문자열 뒤에 다른 문자열을 덧붙임.

## lab13_stoi
1) stoi 기능  
- string을 int로 변환.

2) 숫자 아닌 문자열이면  
- 예외가 발생할 수 있음(예: invalid_argument).

## lab14_string_array_lexico
1) getline 유리한 입력  
- 공백 포함 한 줄/문장/주소 등.

2) string 비교 기준  
- 사전순(lexicographical) 비교.

## lab15_rotate_string
1) substr 반환  
- 문자열의 부분 문자열.

2) len번 회전하면  
- 원래 문자열로 돌아옴(순환).

## lab16_parse_sum_expression
1) find가 -1 의미  
- 더 이상 패턴(+)이 없음.

2) startIndex 갱신 이유  
- 다음 토큰을 찾기 위해 진행 위치를 이동(무한 루프 방지).

## lab17_find_replace_multiline
1) getline(cin,s,'&') 동작  
- '&'가 나올 때까지 입력(여러 줄 포함 가능)하여 s에 저장.

2) replace 후 startIndex 이동 이유  
- 방금 치환한 부분 다음부터 검색하여 무한 반복/중복 치환 방지.
