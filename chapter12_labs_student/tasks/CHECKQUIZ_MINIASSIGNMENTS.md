# C++ 12장 실습 체크퀴즈 & 미니과제 (학생용)

각 lab마다 체크퀴즈 2개 + 미니과제 1개.

---

## lab01_write_student_text
### 체크퀴즈
1) 텍스트로 저장한다는 것은 무슨 뜻인가요?  
2) 상대 경로를 쓰면 어떤 장점이 있나요?

### 미니과제
- student.txt에 이메일(email) 항목도 추가해 저장해보세요.

---

## lab02_read_student_text
### 체크퀴즈
1) >> 로 읽을 때 공백 포함 문자열은 어떻게 해야 하나요?  
2) open 실패의 흔한 원인은?

### 미니과제
- 저장 형식을 바꿔(예: 한 줄에 name sid dept) 읽고 쓰기 둘 다 수정해보세요.

---

## lab03_append_mode
### 체크퀴즈
1) ios::app의 의미는?  
2) ios::trunc와 차이는?

### 미니과제
- 여러 번 실행해도 파일이 어떻게 변하는지 관찰해서 NOTES에 기록하세요.

---

## lab04_get_text_count
### 체크퀴즈
1) 텍스트 모드에서 \r\n이 \n처럼 처리될 수 있다는 의미는?  
2) count가 OS마다 달라질 수 있는 이유는?

### 미니과제
- 같은 파일을 바이너리 모드로 열어 count를 비교해보세요.

---

## lab05_concat_text_files
### 체크퀴즈
1) 왜 출력 파일을 ios::app로 열어야 하나요?  
2) get/put로 복사하면 어떤 단점이 있나요?

### 미니과제
- sample.txt를 student.txt “앞”에 붙이는 방식도 설계해보세요(도전).

---

## lab06_getline_charbuf
### 체크퀴즈
1) fin.getline(char*,n)의 장점/단점은?  
2) 줄이 n보다 길면 무슨 일이 생기나요?

### 미니과제
- buf 크기를 10으로 줄이고 긴 줄을 넣어 어떤 현상이 생기는지 관찰하세요.

---

## lab07_getline_string_search
### 체크퀴즈
1) getline(fin,line)과 getline(cin,line)의 차이는?  
2) find의 리턴값이 npos이면 무슨 뜻?

### 미니과제
- 대소문자 구분 없이 검색하도록 개선해보세요.

---

## lab08_copy_binary_getput
### 체크퀴즈
1) 왜 ios::binary가 필요한가요?  
2) 텍스트 파일도 바이너리 모드로 복사할 수 있나요?

### 미니과제
- src.bin 대신 sample.txt를 binary 모드로 복사해도 잘 되는지 확인하세요.

---

## lab09_copy_binary_readwrite
### 체크퀴즈
1) gcount()는 무엇을 의미하나요?  
2) eof()를 while 조건으로 쓰면 왜 위험할까요?

### 미니과제
- 버퍼 크기를 7로 바꿔 여러 번 read가 일어나게 하고, 루프 횟수를 출력해보세요.

---

## lab10_save_load_binary_numbers
### 체크퀴즈
1) 바이너리 저장의 장점은?  
2) 호환성 이슈의 원인은?

### 미니과제
- float 하나를 추가 저장/복원하도록 코드를 확장해보세요.

---

## lab11_stream_state
### 체크퀴즈
1) if(!fin) 체크는 무엇을 의미하나요?  
2) eof()는 언제 true가 되나요?

### 미니과제
- 파일이 없을 때/있을 때 메시지를 더 친절하게 바꿔보세요.

---

## lab12_random_access_binary
### 체크퀴즈
1) tellg/seekg의 의미는?  
2) 텍스트 파일에서 임의 접근이 까다로운 이유는?

### 미니과제
- 8번째 int(index 7)을 읽도록 seek 오프셋을 바꿔보세요.
