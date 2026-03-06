# C++ 7장 실습 패키지 (학생용)
주제: **프렌드(friend) / 연산자 중복(operator overloading)**

## 폴더 구조
- `src/` : 실습 코드(랩별 폴더, 주석으로 설명 포함)
- `tasks/` : 체크퀴즈 + 미니과제
- `answers/` : 제출 템플릿
- `docs/` : LaTeX 핸드아웃(Verbatim 안정판)

## 권장 실습 순서
1. lab01_friend_global_equals
2. lab02_friend_other_class_member
3. lab03_friend_whole_class
4. lab04_power_plus_member
5. lab05_power_equal_member
6. lab06_power_plus_equal
7. lab07_power_plus_int_member
8. lab08_power_int_plus_friend
9. lab09_prefix_inc_member
10. lab10_not_operator_member
11. lab11_postfix_inc_member
12. lab12_inc_friend
13. lab13_shiftleft_chain

## 컴파일/실행
각 lab 폴더로 이동해서:
```bash
g++ -std=c++17 main.cpp -o run
./run
```

주의: 연산자 오버로딩은 의미가 명확할 때만 쓰세요. 헷갈리는 오버로딩은 감점 포인트가 될 수 있습니다.
