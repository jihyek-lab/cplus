# CHECKQUIZ_ANSWERS (7장)

핵심 의미가 맞으면 정답 처리.

## friend
- friend 함수는 멤버 함수가 아니다(외부 함수)지만 private 접근 권한을 받는다.
- 전방 선언은 클래스 이름을 미리 알려 타입을 사용할 수 있게 한다.
- 특정 멤버 함수만 friend로 주면 최소 권한 원칙에 가깝다.
- friend class는 강력하지만 캡슐화를 약화.

## operator overloading
- 멤버 연산자: a+b => a.operator+(b), 왼쪽 피연산자는 this
- friend 연산자: operator+(a,b) 형태로 양쪽 피연산자를 모두 매개변수로 받음
- 2+a 같은 형태는 friend/외부 함수로 구현해야 함(왼쪽이 기본형)
- 전위++: operator++() / 보통 참조 리턴
- 후위++: operator++(int) / 증가 전 값을 값으로 리턴
- += 는 보통 *this 참조 리턴(체이닝)
