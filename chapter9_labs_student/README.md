# C++ 9장 실습 패키지 (학생용)
주제: **가상 함수(virtual) / 오버라이딩 / 동적 바인딩 / 가상 소멸자 / 순수 가상 함수 / 추상 클래스**

## 폴더 구조
- `src/` : 실습 코드(랩별 폴더, 주석으로 설명 포함)
- `tasks/` : 체크퀴즈 + 미니과제
- `answers/` : 제출 템플릿
- `docs/` : LaTeX 핸드아웃(Verbatim 안정판)

## 권장 실습 순서
1. lab01_redefine_no_virtual
2. lab02_virtual_overriding
3. lab03_paint_draw_dynamic
4. lab04_grandderived_dynamic
5. lab05_scope_resolution_virtual
6. lab06_virtual_destructor
7. lab07_pure_virtual_intro
8. lab08_goodcalc_abstract
9. lab09_adder_subtractor_template_method

## 컴파일/실행
각 lab 폴더에서:
```bash
g++ -std=c++17 main.cpp -o run
./run
```

주의:
- delete가 등장하면 Base 소멸자가 virtual인지 반드시 확인하세요.
- (에러 확인용) 코드는 주석을 풀면 일부러 에러가 나도록 되어 있습니다.
