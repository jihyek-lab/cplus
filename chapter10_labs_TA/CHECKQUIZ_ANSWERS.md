# CHECKQUIZ_ANSWERS (10장)

핵심만 맞으면 정답 처리.

## Templates
- T는 타입 매개변수(타입 변수).
- 구체화는 컴파일 시 호출/사용 지점에서 일어난다.
- 템플릿은 '암묵적 제약'이 있다: 사용한 연산(>, +=, 대입 등)이 가능해야 함.
- myswap(T&,T&)는 동일한 T가 필요 -> int/double 혼합은 타입 추론 실패.

## STL
- STL 3요소: 컨테이너/이터레이터/알고리즘.
- vector: 동적 배열, size/push_back, []는 범위 체크 없음, at는 체크(예외 가능).
- iterator: 컨테이너 원소를 가리키는 포인터 유사 객체.
- map: 키-값 저장, find/end로 존재 확인, operator[]는 없으면 삽입 가능.
- sort: <algorithm>의 전역 함수, [begin,end) 범위, 기본 비교는 operator<.
