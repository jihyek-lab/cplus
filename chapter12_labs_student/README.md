# C++ 12장 실습 패키지 (학생용)
주제: **파일 입출력(Text/Binary) / 파일 모드 / 스트림 상태 / 임의 접근**

## 폴더 구조
- `src/` : 실습 코드(랩별 폴더, 주석 포함)
- `tasks/` : 체크퀴즈 + 미니과제
- `answers/` : 제출 템플릿
- `docs/` : LaTeX 핸드아웃(Verbatim 안정판)
- `data/` : 실습용 샘플 파일(sample.txt, words.txt, src.bin)

## 권장 실습 순서
1. lab01_write_student_text
2. lab02_read_student_text
3. lab03_append_mode
4. lab04_get_text_count
5. lab05_concat_text_files
6. lab06_getline_charbuf
7. lab07_getline_string_search
8. lab08_copy_binary_getput
9. lab09_copy_binary_readwrite
10. lab10_save_load_binary_numbers
11. lab11_stream_state
12. lab12_random_access_binary

## 준비
- `data/` 폴더가 이미 포함되어 있습니다.
- 실행은 프로젝트 루트에서 하는 것을 추천합니다(상대 경로 ./data/... 사용).

## 컴파일/실행
각 lab 폴더에서:
```bash
g++ -std=c++17 main.cpp -o run
./run
```

핵심 주의:
- 텍스트 모드 vs 바이너리 모드에서 줄바꿈 처리 차이(특히 Windows)를 관찰하세요.
- eof()는 “읽기 시도 이후”에 true가 될 수 있어 루프 조건으로 바로 쓰기 위험합니다.
