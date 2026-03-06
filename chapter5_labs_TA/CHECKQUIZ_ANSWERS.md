# CHECKQUIZ_ANSWERS (5장)

> 핵심 의미가 맞으면 정답 처리하세요.

## lab01_swap_by_value
1) 왜 바뀌지 않나?  
- a,b는 m,n의 복사본이라 원본을 변경하지 못함.
2) 주소가 같은가?  
- 아니다. a,b는 별도 매개변수 공간.

## lab02_swap_by_address
1) 왜 바뀌나?  
- 주소를 받아 *a,*b로 원본 공간을 직접 변경.
2) &m 의미  
- m의 주소.

## lab03_pass_object_by_value
1) 복사 생성 발생?  
- 값 전달이면 매개변수 객체가 복사로 만들어짐(복사 생성자 호출 가능).
2) 왜 안 바뀌나?  
- 복사본만 변경했기 때문.

## lab04_pass_object_by_address
1) 왜 복사본 없음?  
- 포인터(주소)만 전달.
2) p-> 의미  
- 포인터가 가리키는 객체의 멤버 접근.

## lab05_return_object_and_assign
1) 대입은 무엇 복사?  
- 기본적으로 멤버 단위 복사(대입 연산자).
2) 복사 생길 수도/안 생길 수도  
- RVO/NRVO 최적화로 복사가 생략될 수 있음.

## lab06_reference_basics
1) 별명인가?  
- 별명(alias). 새 공간 X.
2) 왜 즉시 초기화?  
- 참조는 대상을 반드시 가져야 하며 나중에 다른 대상으로 바꿀 수 없음.

## lab07_swap_by_reference
1) a,b는 무엇의 별명?  
- m,n의 별명.
2) 장점  
- 문법 간단, null 문제 없음, * / & 실수 감소.

## lab08_average_ref_out
1) 장점  
- 성공/실패와 결과를 분리 가능(0이 결과인지 오류인지 구분).
2) size<=0 false  
- 유효하지 않은 입력이므로 실패 처리.

## lab09_pass_object_by_reference
1) 복사 발생?  
- 없음(참조 전달).
2) 소멸자 몇 번?  
- 원본 객체에 대해서만 1번(복사본이 없으므로).

## lab10_reference_return_global
1) 값 vs 공간  
- 공간(변수).
2) 지역 참조 위험  
- 함수 종료 시 지역 변수 소멸 → 댕글링 참조.

## lab11_reference_return_array_elem
1) 가능한 이유  
- 배열 원소의 참조를 리턴 → 대입 대상이 됨.
2) 값/공간  
- 공간.

## lab12_chaining_ref_return
1) return *this  
- 현재 객체 자신에 대한 참조.
2) 왜 필요  
- 다음 호출이 같은 객체에 이어지게 하려면 참조(또는 포인터) 리턴 필요.

## lab13_copy_ctor_called
1) 자동 호출 상황  
- 초기화(son=father), 값 전달(f(father)), 객체 리턴(상황에 따라).
2) 출력이 없을 수도  
- NRVO/RVO로 복사 생성 생략.

## lab14_shallow_copy_demo
1) 왜 얕은 복사  
- 복사 생성자 미구현 → 디폴트 복사(포인터 값만 복사).
2) double delete 위험  
- 두 객체가 같은 메모리 해제 시도.

## lab15_deep_copy_ok
1) 무엇이 달라지나  
- 복사 시 새 메모리 할당 후 내용 복사(포인터 공유 X).
2) double delete 사라짐  
- 서로 다른 메모리를 각자 해제.
