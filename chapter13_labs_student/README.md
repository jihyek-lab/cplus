# C++ 13장 실습 패키지 (학생용)
주제: **예외 처리(Exception Handling) / C 링크 지정(extern "C")**

## 폴더 구조
- `src/` : 실습 코드(랩별 폴더, 주석 포함)
- `tasks/` : 체크퀴즈 + 미니과제
- `answers/` : 제출 템플릿
- `docs/` : LaTeX 핸드아웃(Verbatim 안정판)

## 권장 실습 순서
1. lab01_getexp_no_handling
2. lab02_getexp_return_error
3. lab03_getexp_bool_out
4. lab04_average_divide_exception
5. lab05_getexp_throw
6. lab06_stringToInt
7. lab07_mystack_exceptions
8. lab08_nested_try
9. lab09_exception_classes
10. lab10_externC_multi *(멀티파일 빌드)*

## 컴파일/실행
대부분 lab은 폴더 안에서:
```bash
g++ -std=c++17 main.cpp -o run
./run
```

### lab10_externC_multi (extern "C" 멀티파일)
```bash
g++ -std=c++17 main.cpp g.cpp f.c -o run
./run
```
