# 객체지향 프로그래밍 [8-5] 상속과 protected, 파생 클래스(큐)

- 학습 주제: 상속과 protected 멤버 활용
- 실습 목표: BaseArray를 상속해 정수 큐를 직접 구현하는 문제입니다.

## 구현 체크리스트

- 생성자에서 head, tail, size 초기화하기
- enqueue에서 가득 찬 경우를 처리하기
- dequeue에서 비어 있는 경우 -1을 반환하기
- capacity와 length를 정확히 반환하기

## 실습 힌트

원형 큐로 구현하면 enqueue와 dequeue가 일정한 시간에 동작합니다.

## 원문 문제 설명

BaseArray를 상속받아, 다음과 같은 멤버를 갖는 정수를 저장하는 큐 MyQueue 클래스를 작성하라.
(단, 최대로 저장 가능한 정수의 갯수는 10으로 한다.)
정수를 입력받아 큐에 삽입하는 enqueue() (꽉 차있으면 변화 없음)
최대 용량을 반환하는 capacity()
현재 크기를 반환하는 length()
큐에서 저장된 정수를 꺼내는 dequeue(), (비어있으면 -1 반환)
입출력 예시
입력은 첫 줄에 총 입력받을 명령의 갯수가 주어진 후, 다음 줄부터 다음과 같은 명령들이 주어진다.
enqueue n: 큐에 n을 삽입
dequeue: 큐에서 정수를 꺼내 출력
length: 큐에 저장된 정수의 갯수 출력
capacity: 큐의 최대 저장 용량 출력
입력 1
6
capacity
enqueue 1
enqueue 2
dequeue
dequeue
length
출력 1
10
1
2
0

## 파일 안내

- `main.cpp`: 학생 실습용 starter code
- 이 파일을 기준으로 TODO를 채우면서 연습하면 됩니다.
