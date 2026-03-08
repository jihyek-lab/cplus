# C++ 11장 실습 패키지 (학생용)
주제: **C++ 입출력 시스템(Streams) / 포맷 입출력 / 조작자(manipulator) / << >> 오버로딩**

## 폴더 구조
- `src/` : 실습 코드(랩별 폴더, 주석으로 설명 포함)
- `tasks/` : 체크퀴즈 + 미니과제
- `answers/` : 제출 템플릿
- `docs/` : LaTeX 핸드아웃(Verbatim 안정판)

## 권장 실습 순서
1. lab01_ostream_put_write
2. lab02_istream_get_line
3. lab03_get_charptr_ignore
4. lab04_getline_echo
5. lab05_gcount_ignore
6. lab06_setf_unsetf
7. lab07_width_fill_precision
8. lab08_manipulators_basic
9. lab09_point_ostream
10. lab10_book_ostream
11. lab11_point_istream_ostream
12. lab12_custom_manipulators
13. lab13_istream_manipulator_question

## 컴파일/실행
각 lab 폴더에서:
```bash
g++ -std=c++17 main.cpp -o run
./run
```

핵심 주의:
- get()/getline()/ignore()는 버퍼의 '\n' 처리 방식이 달라요. 반드시 관찰하세요.
- 포맷(setf, fill, precision 등)은 cout 상태로 "유지"되는 경우가 많습니다.
