# C++ 2장 실습 패키지 (학생용)

이 폴더는 **C++ 2장(기본 입출력/네임스페이스/문자열)** 실습을 “복사 → 실행”할 수 있게 만든 예제 모음입니다.  
각 파일은 **독립 실행** 가능하도록 작성되어 있습니다.

## 권장 실습 순서
1. `01_hello.cpp` → `02_cout_chain.cpp` (출력 기본)
2. `03_std_namespace.cpp` → `04_custom_namespace.cpp` (네임스페이스)
3. `05_cin_numbers.cpp` → `06_cin_fail.cpp` (입력 + 실패 상태)
4. `07_cstring_cin.cpp` → `08_cstring_getline.cpp` → `09_cin_then_getline.cpp` (**버퍼 문제 해결**)
5. `10_string_basic.cpp` → `11_string_getline.cpp` → `12_password_strcmp.cpp` → `13_password_string.cpp` (C-스트링 vs string)
6. `14_header_function_demo.cpp` (헤더/표준 함수)

---

## 실행 방법 A: VS Code (추천)
1. 폴더(`chapter2_labs_student`)를 VS Code로 엽니다.
2. `src/` 아래에서 실행하고 싶은 `.cpp` 파일을 하나 고릅니다.
3. 터미널에서 아래처럼 컴파일 후 실행합니다.

### macOS / Linux (g++)
```bash
cd src
g++ -std=c++17 01_hello.cpp -o run
./run
```

### Windows (MinGW g++)
```bash
cd src
g++ -std=c++17 01_hello.cpp -o run.exe
run.exe
```

> 다음 파일을 실행할 땐 `01_hello.cpp` 부분만 바꿔서 컴파일하면 됩니다.

---

## 실행 방법 B: Visual Studio
- 프로젝트 생성 후 `src`의 파일을 하나 추가해서 실행하거나,
- 파일별로 새 프로젝트에 붙여넣어 실행해도 됩니다.
- **주의:** 한 프로젝트에 여러 `main()`이 동시에 있으면 컴파일 에러가 납니다.  
  → 실행할 파일만 남기고 나머지는 “Exclude from Build(빌드 제외)” 처리하세요.

---

## 체크 포인트 (꼭 기억!)
- `cin >>` 다음에 `getline()`을 쓰면, 버퍼에 남은 `\n` 때문에 빈 줄이 들어갈 수 있습니다.  
  → `cin.ignore(..., '\n')`로 해결 (예제: `09_cin_then_getline.cpp`)
- `char[]` 문자열은 `==`로 내용 비교하면 안 됩니다.  
  → `strcmp(a, b) == 0` 사용 (예제: `12_password_strcmp.cpp`)
- 공백 포함 문자열 입력은 `getline()`이 정석입니다.  
  → `string`과 함께 쓰면 가장 편합니다.

즐겁게 실습하세요!


---

## 체크퀴즈/미니과제
- `tasks/CHECKQUIZ_MINIASSIGNMENTS.md` 를 확인하세요. 예제별로 체크퀴즈 2개 + 미니과제 1개가 있습니다.
