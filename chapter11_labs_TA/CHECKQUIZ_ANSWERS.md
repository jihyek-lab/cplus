# CHECKQUIZ_ANSWERS (11장)

핵심만 맞으면 정답.

## ostream
- put: 문자 1개 출력(ASCII 코드 int도 가능).
- write: 배열에서 n개 문자 출력(널문자 자동 처리 아님).
- flush: 출력 버퍼를 강제로 비움.

## istream
- cin.get()이 int인 이유: EOF(-1)와 구분.
- get(buf,n)은 '\n'을 버퍼에 남김 -> ignore/get으로 제거 필요.
- getline은 '\n'을 읽고 버퍼에서 제거(배열에 저장 X).
- gcount는 직전 입력 함수가 읽은 문자 수.

## formatting
- setf/unsetf: 플래그 설정/해제, 상태 유지.
- width: 다음 출력 1회성.
- fill/precision: 상태 유지.
- manipulator: << 또는 >>와 함께 쓰는 함수.
  - 매개변수 없는 조작자: hex, dec, showbase, boolalpha...
  - 매개변수 있는 조작자: setw, setfill, setprecision (iomanip 필요)

## operator overloading
- operator<<(ostream&, const T&): ostream& 리턴 -> 체이닝.
- operator>>(istream&, T&): istream& 리턴 -> 체이닝, 입력 대상은 참조.
- 사용자 정의 조작자: ostream&(ostream&) / istream&(istream&)
