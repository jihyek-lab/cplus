# C++ 8장 실습 패키지 (학생용)
주제: **상속(Inheritance)**

## 폴더 구조
- `src/` : 실습 코드(랩별 폴더, 주석으로 설명 포함)
- `tasks/` : 체크퀴즈 + 미니과제
- `answers/` : 제출 템플릿
- `docs/` : LaTeX 핸드아웃(Verbatim 안정판)

## 권장 실습 순서
1. lab01_point_colorpoint
2. lab02_upcasting
3. lab03_downcasting
4. lab04_protected_access
5. lab05_ctor_dtor_order
6. lab06_no_default_base_ctor_error *(에러 확인용)*
7. lab07_fix_with_init_list
8. lab08_tv_wide_smart
9. lab09_inheritance_modes
10. lab10_multiple_inheritance_calculator
11. lab11_diamond_virtual_inheritance

## 컴파일/실행
각 lab 폴더로 이동해서:
```bash
g++ -std=c++17 main.cpp -o run
./run
```

주의:
- 다운캐스팅은 위험합니다. (9장 가상 함수 이후 dynamic_cast 권장)
- (에러 확인용) lab은 주석을 풀면 일부러 컴파일 에러가 나도록 되어 있습니다.
