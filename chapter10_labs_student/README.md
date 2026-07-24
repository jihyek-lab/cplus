# C++ 10장 실습 패키지 (학생용)
주제: **템플릿(Templates) & STL(vector/map/iterator/algorithm)**

추천: 실습 전에 [`THEORY_SUMMARY.md`](./THEORY_SUMMARY.md)를 먼저 읽으면 흐름이 더 잘 잡힙니다.

## 폴더 구조
- `src/` : 실습 코드(랩별 폴더, 주석으로 설명 포함)
- `src_rev/` : 핵심 개념을 묶어서 다시 설명하는 보강 예제
- `tasks/` : 체크퀴즈 + 미니과제
- `answers/` : 제출 템플릿
- `docs/` : LaTeX 핸드아웃(Verbatim 안정판)

## 권장 실습 순서
1. lab01_myswap_overload_problem
2. lab02_myswap_template
3. lab03_myswap_with_class
4. lab04_myswap_type_mismatch *(에러 확인용)*
5. lab05_bigger_template
6. lab06_add_array_template
7. lab07_mcopy_two_types
8. lab08_mystack_template_class
9. lab09_vector_basic
10. lab10_vector_string_lexico
11. lab11_vector_iterator_double
12. lab12_map_dictionary
13. lab13_map_inventory
14. lab14_printMap_iterator
15. lab15_sort_vector_algorithm

## 추가 보강 예제 (`src_rev`)
기본 lab을 본 뒤, 흐름을 다시 정리하고 싶다면 아래 예제를 이어서 보세요.

1. `lab01_function_template_basics`
2. `lab02_template_two_types`
3. `lab03_template_class_stack`
4. `lab04_vector_and_iterator`
5. `lab05_map_and_algorithm`
6. `lab06_template_vector_helpers`
7. `lab07_vector_score_processing`
8. `lab08_map_count_and_search`

## 컴파일/실행
각 lab 폴더에서:
```bash
g++ -std=c++17 main.cpp -o run
./run
```

팁:
- 템플릿 에러는 메시지가 길어요. "어떤 타입 T로 구체화(instantiation)되었는지"부터 찾으세요.
- map에서 dic[key]는 key가 없으면 삽입될 수 있어요(find 습관 권장).
