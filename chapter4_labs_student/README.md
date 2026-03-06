# C++ 4장 실습 패키지 (학생용)
주제: **객체 포인터/객체 배열, 동적 생성(new/delete), this 포인터, string**

## 폴더 구조
- `src/` : 실습 코드(랩별 폴더)
- `tasks/` : 체크퀴즈 + 미니과제
- `answers/` : 제출 템플릿
- `docs/` : LaTeX 핸드아웃(원본)

## 권장 실습 순서
1. lab01_object_pointer
2. lab02_object_array
3. lab03_array_needs_default_ctor
4. lab04_array_init
5. lab05_2d_object_array
6. lab06_new_delete_int
7. lab07_delete_pitfalls
8. lab08_new_delete_array
9. lab09_dynamic_object
10. lab10_dynamic_object_array
11. lab11_this_pointer
12. lab12_string_basics
13. lab13_stoi
14. lab14_string_array_lexico
15. lab15_rotate_string
16. lab16_parse_sum_expression
17. lab17_find_replace_multiline

## 컴파일/실행 (g++)
각 lab 폴더로 이동 후 컴파일합니다.

### macOS / Linux
예) lab01
```bash
cd src/lab01_object_pointer
g++ -std=c++17 main.cpp -o run
./run
```

예) 여러 파일은 없음(4장 실습은 모두 단일 파일) — 단, 입력이 있는 예제는 콘솔 입력이 필요합니다.

### Windows (MinGW)
```bat
cd src\lab01_object_pointer
g++ -std=c++17 main.cpp -o run.exe
run.exe
```

## 제출(선택)
- `answers/` 폴더에 수정한 lab 폴더를 복사해 제출하거나,
- `answers/NOTES.md`에 간단 설명 + 스크린샷을 넣어 제출하세요.
