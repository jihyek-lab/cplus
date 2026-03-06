# C++ 6장 실습 패키지 (학생용)
주제: **함수 중복(오버로딩) / 디폴트 매개변수 / 모호성 / static 멤버**

## 폴더 구조
- `src/` : 실습 코드(랩별 폴더, 주석으로 설명 포함)
- `tasks/` : 체크퀴즈 + 미니과제
- `answers/` : 제출 템플릿
- `docs/` : LaTeX 핸드아웃(Verbatim 안정판)

## 권장 실습 순서
1. lab01_sum_overload_ok
2. lab02_overload_fail_return_type *(에러 확인용)*
3. lab03_big_overload
4. lab04_sum_range_overload
5. lab05_default_param_basic
6. lab06_default_param_rules *(에러 확인용 포함)*
7. lab07_ambiguity_default_param *(에러 확인용)*
8. lab08_ambiguity_cast *(에러 확인용)*
9. lab09_ambiguity_ref_param *(에러 확인용)*
10. lab10_fillline_default
11. lab11_myvector_default_ctor
12. lab12_static_member_basic
13. lab13_static_access_classscope
14. lab14_math_static_class
15. lab15_count_objects_static
16. lab16_static_cannot_access_this *(에러 확인용 포함)*

## 컴파일/실행
각 lab 폴더로 이동해서 컴파일:
```bash
g++ -std=c++17 main.cpp -o run
./run
```

에러 확인용 lab은 주석을 풀면 일부러 컴파일 에러가 나도록 되어 있습니다.
