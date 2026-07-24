#include <iostream>
#include <string>
using namespace std;

/*
[Lab10] Campus Notification System
------------------------------------------------------------
프로젝트 설명
- 학교에서 학생과 교수에게 공지를 보내는 작은 알림 시스템을 만든다.
- 예를 들어 과제 마감, 보강 공지, 시험 일정 같은 메시지를 여러 방식으로 전달한다고 가정한다.
- 이 프로젝트는 "현실적인 상황" 안에서 chapter 8~9 개념을 연결해서 연습하기 위한 예제다.

클래스 전체 그림

    Person (abstract)
      |- Student
      |- Professor

    Notification (abstract)
      |- EmailNotification
      |- SMSNotification
      |- AppPushNotification

구조 설명
- Person 계열은 "알림을 받는 사람"을 표현한다.
- Notification 계열은 "알림을 보내는 방식"을 표현한다.
- 즉 이 프로젝트는 "사람"과 "전송 방식"을 분리해서 설계한다.
- 사람 종류가 늘어나도 Notification 쪽 코드는 그대로 둘 수 있다.
- 전송 방식이 늘어나도 Person 쪽 코드는 그대로 둘 수 있다.

실행 흐름
1) Student, Professor 객체를 만든다.
2) 이 객체들을 Person* 배열로 묶는다. -> 업캐스팅
3) Email, SMS, AppPush 객체를 만든다.
4) 이 객체들을 Notification* 배열로 묶는다. -> 다형성 준비
5) 모든 사람에게 모든 채널로 공지를 보낸다.
6) send() 호출 시 실제 채널 객체 타입에 따라 다른 결과가 나온다. -> 동적 바인딩

설계 포인트
- Person은 공통 정보(name, campusId)와 공통 인터페이스(role, showInfo)를 제공한다.
- Notification은 공통 인터페이스(send)만 제공하고 실제 전송 형식은 자식 클래스가 구현한다.
- 이 구조 덕분에 "무엇을 보낼지"와 "누구에게 보낼지"를 유연하게 조합할 수 있다.

학생들과 같이 만드는 순서
1) Person 부모 클래스를 만든다.
2) Student, Professor 자식 클래스를 만든다.
3) Notification 추상 클래스를 만든다.
4) Email, SMS, AppPush 전송 클래스를 만든다.
5) Person* / Notification* 배열로 묶어서 한 번에 처리한다.
6) 마지막에 왜 소멸자가 virtual이어야 하는지까지 확인한다.

이 프로젝트로 배우는 것
- chapter 8: 상속, 업캐스팅, 공통 속성/공통 함수 재사용
- chapter 9: virtual, override, 동적 바인딩, 추상 클래스, 가상 소멸자

학생들과 같이 할 질문 5개
1) 왜 Student, Professor를 따로만 두지 않고 Person으로 묶었을까?
   - 힌트: 공통 속성과 공통 동작을 한 곳에 모으면 무엇이 좋아질까?
   - 교사용 답변: name, campusId, showInfo 같은 공통 요소를 Person에 모아
     중복을 줄이고, Student와 Professor를 Person* 하나로 함께 다룰 수 있기 때문이다.
2) 왜 Notification은 일반 클래스가 아니라 추상 클래스로 만들었을까?
   - 힌트: send의 "형식"은 같지만 실제 동작은 채널마다 다르다.
   - 교사용 답변: "알림을 보낸다"는 공통 규약은 필요하지만,
     Email/SMS/AppPush마다 실제 전송 방식이 다르기 때문에 공통 인터페이스만 두는 것이 적절하다.
3) 왜 EmailNotification, SMSNotification, AppPushNotification을
   Notification* 배열에 함께 저장할 수 있을까?
   - 힌트: 자식 객체를 부모 포인터로 가리키는 것을 무엇이라고 하는가?
   - 교사용 답변: 세 클래스 모두 Notification을 상속하므로
     자식 객체를 부모 타입 포인터로 가리킬 수 있다. 이것이 업캐스팅이다.
4) channel->send(*person, message); 한 줄에서 왜 채널마다 다른 출력이 나올까?
   - 힌트: virtual 함수 호출은 컴파일 시점이 아니라 실행 시점에 결정된다.
   - 교사용 답변: send가 virtual 함수이기 때문에,
     Notification*로 호출해도 실제 객체가 Email인지 SMS인지 AppPush인지에 따라 알맞은 send가 실행된다.
5) 마지막 delete에서 왜 Person, Notification 소멸자를 virtual로 두는 것이 안전할까?
   - 힌트: 부모 포인터가 실제로는 자식 객체를 가리키고 있다.
   - 교사용 답변: 부모 포인터로 자식 객체를 delete할 때
     부모 소멸자만 호출되면 자식 쪽 정리 코드가 빠질 수 있다.
     virtual 소멸자를 두면 자식 소멸자부터 안전하게 호출된다.

이 예제는 chapter 8~9의 핵심을 한 번에 묶어 보는 통합 실습이다.

왜 이 예제가 의미 있는가?
- 학생/교수에게 공지를 보내는 상황은 실제 학교 생활과 가깝다.
- Person 상속 구조로 chapter 8의 "상속, 업캐스팅"을 복습할 수 있다.
- Notification 추상 클래스로 chapter 9의 "virtual, override, 다형성"을 연습할 수 있다.

이 수업에서 같이 짚을 포인트
1) Person* 하나로 Student, Professor를 함께 다룰 수 있다.
2) Notification* 하나로 Email, SMS, AppPush를 함께 다룰 수 있다.
3) 부모 타입은 같아도 실제 객체가 다르면 실행 결과가 달라진다.
4) delete를 부모 포인터로 할 것이므로 소멸자는 virtual이어야 안전하다.
------------------------------------------------------------
*/

class Person {
protected:
    string name;
    int campusId;

public:
    Person(const string& name, int campusId) : name(name), campusId(campusId) {}

    // "이 사람이 어떤 역할인가?"는 자식 클래스가 결정한다.
    virtual string role() const = 0;

    // Base 함수 안에서 virtual 함수(role)를 호출하는 구조도 같이 보여 준다.
    virtual void showInfo() const {
        cout << role() << " | " << name << " | ID: " << campusId;
    }

    const string& getName() const { return name; }
    int getCampusId() const { return campusId; }

    virtual ~Person() = default;
};

class Student : public Person {
    int grade;

public:
    Student(const string& name, int campusId, int grade)
        : Person(name, campusId), grade(grade) {}

    string role() const override { return "Student"; }

    void showInfo() const override {
        Person::showInfo();
        cout << " | Grade: " << grade << '\n';
    }
};

class Professor : public Person {
    string department;

public:
    Professor(const string& name, int campusId, const string& department)
        : Person(name, campusId), department(department) {}

    string role() const override { return "Professor"; }

    void showInfo() const override {
        Person::showInfo();
        cout << " | Dept: " << department << '\n';
    }
};

class Notification {
public:
    // 채널마다 전송 형식이 다르므로 send는 추상 함수로 둔다.
    virtual void send(const Person& receiver, const string& message) const = 0;

    virtual ~Notification() = default;
};

class EmailNotification : public Notification {
public:
    void send(const Person& receiver, const string& message) const override {
        cout << "[Email] to " << receiver.getName()
             << " (" << receiver.role() << "): "
             << message << '\n';
    }
};

class SMSNotification : public Notification {
public:
    void send(const Person& receiver, const string& message) const override {
        cout << "[SMS] to " << receiver.getName()
             << " (#" << receiver.getCampusId() << "): "
             << message << '\n';
    }
};

class AppPushNotification : public Notification {
public:
    void send(const Person& receiver, const string& message) const override {
        cout << "[AppPush] to " << receiver.getName()
             << ": New campus notice - "
             << message << '\n';
    }
};

void showRecipients(Person* people[], int peopleCount)
{
    cout << "=== Recipients ===\n";
    for (int i = 0; i < peopleCount; i++) {
        people[i]->showInfo();
    }
    cout << '\n';
}

void broadcast(Person* people[],
               int peopleCount,
               Notification* channels[],
               int channelCount,
               const string& message)
{
    cout << "=== Send Notice ===\n";

    for (int i = 0; i < peopleCount; i++) {
        Person* person = people[i];

        cout << '\n';
        cout << "Receiver: ";
        person->showInfo();

        // 같은 Notification* 배열 순회 코드지만 실제 객체 타입에 따라 send 결과가 달라진다.
        for (int j = 0; j < channelCount; j++) {
            Notification* channel = channels[j];
            channel->send(*person, message);
        }
    }
}

int main()
{
    const int PEOPLE_COUNT = 3;
    const int CHANNEL_COUNT = 3;
    Person* people[PEOPLE_COUNT];
    Notification* channels[CHANNEL_COUNT];

    // 업캐스팅: Student*, Professor*를 Person* 배열에 저장
    people[0] = new Student("Minji", 2025001, 2);
    people[1] = new Student("Jisoo", 2025002, 4);
    people[2] = new Professor("Kim", 3001001, "Computer Science");

    // 추상 클래스 Notification의 실제 구현체들을 배열에 저장
    channels[0] = new EmailNotification();
    channels[1] = new SMSNotification();
    channels[2] = new AppPushNotification();

    showRecipients(people, PEOPLE_COUNT);
    broadcast(people, PEOPLE_COUNT, channels, CHANNEL_COUNT,
              "Assignment 3 deadline is Friday 6 PM.");

    // 부모 포인터로 삭제하므로 Person, Notification 소멸자는 virtual이어야 한다.
    for (int i = 0; i < PEOPLE_COUNT; i++) {
        delete people[i];
    }

    for (int i = 0; i < CHANNEL_COUNT; i++) {
        delete channels[i];
    }

    return 0;
}
