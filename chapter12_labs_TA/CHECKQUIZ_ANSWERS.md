# CHECKQUIZ_ANSWERS (12장)

핵심만 맞으면 정답.

## Text vs Binary
- 텍스트: 문자 해석/줄바꿈 변환 가능(Windows: \r\n).
- 바이너리: 바이트 그대로, 변환 없음(ios::binary 필요).

## Streams / Modes
- ifstream/ofstream/fstream 차이: 읽기/쓰기/읽기+쓰기.
- ios::app: 항상 끝에 추가, ios::trunc: 기존 내용 삭제 후 새로 쓰기, ios::binary: 바이트 그대로.

## Read patterns
- get/put: 1바이트 단위(느릴 수 있음).
- read/write: 블록 단위(빠름), gcount로 실제 읽은 바이트 확인.

## State
- if(!fin): fail 상태 포함.
- eof(): EOF를 '만난 뒤' true (읽기 시도 이후) -> 루프 조건으로 직접 쓰기 위험.
- 안전 패턴: while(getline(fin,line)) / while(read(...), gcount()>0)

## Random Access
- tellg/seekg: 읽기 포인터 위치/이동, 바이너리 모드에서 바이트 오프셋이 직관적.
- 텍스트 모드는 줄바꿈 변환으로 오프셋이 덜 직관적일 수 있음.
