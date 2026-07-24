# 객체지향 프로그래밍 [10-13] map 활용

- 학습 주제: map 컨테이너 활용
- 실습 목표: map<string, int>으로 이름과 성적을 관리하는 문제입니다.

## 구현 체크리스트

- insert에서 중복 이름 검사하기
- search에서 존재 여부 확인 후 결과 출력하기
- map::find 결과를 안전하게 사용하는 습관 익히기

## 실습 힌트

scoreMap.find(name) == scoreMap.end() 형태를 먼저 익히면 대부분의 분기 처리가 자연스럽게 풀립니다.

## 원문 문제 설명

map 컨테이너를 활용하여 (이름, 성적)을 저장하는 GradeManager 클래스가 있다.
이름, 성적을 map에 저장하는 insert() 멤버함수와, 이름으로 성적을 검색하여 출력하는 search() 멤버함수를 작성하여 프로그램을 완성하라.
입출력 예시
1 : insert() 를 수행하며, 존재하는 name 을 받은 경우 " already exsits" 를 출력한다.
2 : search()를 수행하며, name 을 찾을 수 없는 경우 " doesn't exists" 를 출력한다.
3: 종료
입력 1
1 kim 100
2 kim
3
출력 1
kim: 100

## 파일 안내

- `main.cpp`: 학생 실습용 starter code
- 이 파일을 기준으로 TODO를 채우면서 연습하면 됩니다.
