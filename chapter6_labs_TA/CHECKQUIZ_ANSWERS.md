# CHECKQUIZ_ANSWERS (6장)

표현은 달라도 핵심이 맞으면 정답 처리.

## lab01_sum_overload_ok
1) 구분 기준: 매개변수의 타입/개수(시그니처).
2) 리턴 타입은 기준이 될 수 없음.

## lab02_overload_fail_return_type
1) 매개변수 동일이라 호출이 구분 불가.
2) 함수 이름 분리/템플릿/매개변수 변경 등.

## lab03_big_overload
1) int[] 버전 호출.
2) size=0이면 a[0] 접근이 위험(UB).

## lab04_sum_range_overload
1) 하나는 구간합, 하나는 0부터 합.
2) 의미가 비슷해 오해 가능.

## lab05_default_param_basic
1) 분리 컴파일 시 중복 선언 방지, 한 곳에서 기본값 관리.
2) star(5)로 해석.

## lab06_default_param_rules
1) 중간을 비우면 뒤 인수를 전달할 방법이 없음.
2) a=10,b=5,c=20,d=30.

## lab07_ambiguity_default_param
1) msg(6)이 두 함수 모두에 매칭 가능.
2) 오버로딩 제거/디폴트 제거/호출 형태 변경 등.

## lab08_ambiguity_cast
1) int->float/double 둘 다 가능.
2) square(3.0) 또는 (float)3 등 명시 변환.

## lab09_ambiguity_ref_param
1) 호출 문법상 값/참조 구분 불가.
2) 함수명 분리, 설계 변경.

## lab10_fillline_default
1) fillLine() / fillLine(n,c) 중복 제거.
2) fillLine(int n, char c='-') 같은 형태.

## lab11_myvector_default_ctor
1) 기본/매개변수 생성자 중복 제거.
2) 얕은 복사 위험(Rule of 3).

## lab12_static_member_basic
1) 공유.
2) 링크 에러(정의 누락).

## lab13_static_access_classscope
1) 객체 없이 존재.
2) 객체가 있어야 값이 의미 있음.

## lab14_math_static_class
1) 객체 없이 기능 제공.
2) 전역 오염/충돌 감소, 응집도 증가.

## lab15_count_objects_static
1) 10번(기본 생성자).
2) 10번(역순 소멸).

## lab16_static_cannot_access_this
1) 객체 없이 호출 가능해서 this 없음.
2) 어느 객체의 money인지 정보(포인터/참조)가 필요.
