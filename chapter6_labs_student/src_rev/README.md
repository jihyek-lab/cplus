# chapter6 `src_rev` 안내

`src_rev`는 원본 `src`의 16개 lab을 학습 흐름 기준으로 다시 묶은 축약 실습 트랙입니다.

- 목표 1: 비슷한 개념을 한 파일에서 연속으로 비교할 수 있게 정리
- 목표 2: 컴파일 에러 확인용 예제는 "주석을 풀면 에러"가 나도록 유지
- 목표 3: 원본의 모든 핵심 개념을 빠짐없이 포함

## 권장 순서
1. `lab01_overloading_core`
2. `lab02_default_params_core`
3. `lab03_ambiguity_cases`
4. `lab04_default_ctor_vector`
5. `lab05_static_shared_members`
6. `lab06_static_utilities_and_limits`

## 원본 lab 대응표
- `lab01_overloading_core`
  원본 대응: `lab01_sum_overload_ok`, `lab02_overload_fail_return_type`, `lab03_big_overload`, `lab04_sum_range_overload`
- `lab02_default_params_core`
  원본 대응: `lab05_default_param_basic`, `lab06_default_param_rules`, `lab10_fillline_default`
- `lab03_ambiguity_cases`
  원본 대응: `lab07_ambiguity_default_param`, `lab08_ambiguity_cast`, `lab09_ambiguity_ref_param`
- `lab04_default_ctor_vector`
  원본 대응: `lab11_myvector_default_ctor`
- `lab05_static_shared_members`
  원본 대응: `lab12_static_member_basic`, `lab13_static_access_classscope`
- `lab06_static_utilities_and_limits`
  원본 대응: `lab14_math_static_class`, `lab15_count_objects_static`, `lab16_static_cannot_access_this`
