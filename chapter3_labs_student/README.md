# C++ 3장 실습 패키지 (학생용)
주제: **클래스와 객체** (클래스/객체, 캡슐화, 생성자·소멸자, 접근지정자, 인라인, struct, 파일 분리, include guard)

---

## 폴더 구조
- `src/` : 실습 코드(실습별 폴더로 분리)
- `tasks/` : 체크퀴즈 + 미니과제
- `answers/` : 제출 템플릿(수정한 파일을 여기에 저장)
- `docs/` : 실습 핸드아웃 LaTeX(원본)

---

## 권장 실습 순서
1. `lab01_basic_class_object`
2. `lab02_encapsulation_private_public`
3. `lab03_constructor_overloading`
4. `lab04_delegating_ctor_init_list`
5. `lab05_default_ctor_cases`
6. `lab06_destructor_order`
7. `lab07_access_specifier_errors`
8. `lab08_inline_functions`
9. `lab09_struct_vs_class`
10. `lab10_file_split_circle`  (여러 파일 컴파일)
11. `lab11_mini_project_calculator` (여러 파일 컴파일)

---

## 실행 방법(터미널, g++)
각 lab 폴더로 이동 후 컴파일합니다.

### macOS / Linux
예: lab01
```bash
cd src/lab01_basic_class_object
g++ -std=c++17 main.cpp -o run
./run
```

예: 여러 파일(lab10)
```bash
cd src/lab10_file_split_circle
g++ -std=c++17 main.cpp Circle.cpp -o run
./run
```

### Windows (MinGW)
```bat
cd src\lab01_basic_class_object
g++ -std=c++17 main.cpp -o run.exe
run.exe
```

---

## 제출(선택)
- `answers/` 폴더에 본인이 수정한 실습 폴더를 복사해서 제출하세요.
- 또는 `answers/NOTES.md`에 간단 설명 + 스크린샷.
