# C++ 5장 실습 패키지 (학생용)
주제: **함수 / 참조 / 복사 생성자**

## 폴더 구조
- `src/` : 실습 코드(랩별 폴더)
- `tasks/` : 체크퀴즈 + 미니과제
- `answers/` : 제출 템플릿
- `docs/` : LaTeX 핸드아웃(원본)

## 권장 실습 순서
1. lab01_swap_by_value
2. lab02_swap_by_address
3. lab03_pass_object_by_value
4. lab04_pass_object_by_address
5. lab05_return_object_and_assign
6. lab06_reference_basics
7. lab07_swap_by_reference
8. lab08_average_ref_out
9. lab09_pass_object_by_reference
10. lab10_reference_return_global
11. lab11_reference_return_array_elem
12. lab12_chaining_ref_return
13. lab13_copy_ctor_called
14. lab14_shallow_copy_demo
15. lab15_deep_copy_ok

## 컴파일/실행 (g++)
각 lab 폴더로 이동 후 컴파일합니다.

예) lab01
```bash
cd src/lab01_swap_by_value
g++ -std=c++17 main.cpp -o run
./run
```

## 제출(선택)
- `answers/` 폴더에 수정한 lab 폴더를 복사해 제출하거나,
- `answers/NOTES.md`에 간단 설명 + 스크린샷을 넣어 제출하세요.
