#!/usr/bin/env python3
import json
import subprocess
import sys
import time


COURSE_ID = "83507"
SESSKEY = "ih3x3eXl1h"
CATEGORY = "117862"


QUESTIONS = [
    {
        "number": 2,
        "qtype": "multichoice",
        "name": "중간고사 02번",
        "mark": "2",
        "text": "다음 중 원본 값이 바뀔 수 있는 전달 방식만 올바르게 묶은 것은?",
        "answers": [
            {"text": "값 전달", "fraction": "0.0"},
            {"text": "값 전달, 주소 전달", "fraction": "0.0"},
            {"text": "주소 전달, 참조 전달", "fraction": "1.0"},
            {"text": "값 전달, 참조 전달", "fraction": "0.0"},
        ],
    },
    {
        "number": 3,
        "qtype": "multichoice",
        "name": "중간고사 03번",
        "mark": "2",
        "text": "`char a[20]`, `char b[20]`의 내용이 같은지 비교할 때 가장 적절한 것은?",
        "answers": [
            {"text": "a == b", "fraction": "0.0"},
            {"text": "strcmp(a, b) == 0", "fraction": "1.0"},
            {"text": "a = b", "fraction": "0.0"},
            {"text": "cin >> a", "fraction": "0.0"},
        ],
    },
    {
        "number": 4,
        "qtype": "multichoice",
        "name": "중간고사 04번",
        "mark": "2",
        "text": "함수 오버로딩을 구분하는 기준은?",
        "answers": [
            {"text": "리턴 타입", "fraction": "0.0"},
            {"text": "함수 본문 길이", "fraction": "0.0"},
            {"text": "매개변수 개수와 타입", "fraction": "1.0"},
            {"text": "주석 내용", "fraction": "0.0"},
        ],
    },
    {
        "number": 5,
        "qtype": "multichoice",
        "name": "중간고사 05번",
        "mark": "2",
        "text": "static 멤버 함수에서 non-static 멤버 변수에 직접 접근할 수 없는 가장 직접적인 이유는?",
        "answers": [
            {"text": "static 함수는 리턴값이 없어서", "fraction": "0.0"},
            {"text": "static 함수에는 this가 없어서", "fraction": "1.0"},
            {"text": "static 함수는 public만 접근해서", "fraction": "0.0"},
            {"text": "static 함수는 항상 전역 함수라서", "fraction": "0.0"},
        ],
    },
    {
        "number": 6,
        "qtype": "shortanswer",
        "name": "중간고사 06번",
        "mark": "4",
        "text": """다음 코드의 실행 결과를 쓰시오.

class A {
public:
    A() { cout << "A"; }
    ~A() { cout << "a"; }
};

int main() {
    A x;
    {
        A y;
    }
    A z;
}""",
        "answers": [
            {"text": "AAaAaa", "fraction": "1.0"},
        ],
    },
    {
        "number": 7,
        "qtype": "essay",
        "name": "중간고사 07번",
        "mark": "4",
        "text": """다음 코드를 보고 각 배열 선언이 가능한지 판단하고, 이유를 쓰시오. 답은 짧게 쓰시오.

class A {
public:
    int x;
};

class B {
public:
    B(int n) { }
};

A arr1[3];
B arr2[3];

- arr1:
- arr1 이유:
- arr2:
- arr2 이유:""",
    },
    {
        "number": 8,
        "qtype": "shortanswer",
        "name": "중간고사 08번",
        "mark": "4",
        "text": """문자열 \"250\"을 정수 250으로 바꾸어 n에 저장하려고 한다. 빈칸에 들어갈 표현을 쓰시오.

string s = "250";
int n = (1) __________;""",
        "answers": [
            {"text": "stoi(s)", "fraction": "1.0"},
        ],
    },
    {
        "number": 9,
        "qtype": "essay",
        "name": "중간고사 09번",
        "mark": "4",
        "text": """두 정수의 값을 참조로 바꾸는 함수 swapByRef(int& a, int& b)의 핵심 코드 세 줄을 쓰시오.

- (1)
- (2)
- (3)""",
    },
    {
        "number": 10,
        "qtype": "shortanswer",
        "name": "중간고사 10번",
        "mark": "4",
        "text": """배열의 index번째 원소를 참조로 돌려주는 함수이다. 빈칸에 들어갈 표현을 쓰시오.

int& arrElem(int a[], int index) {
    return (1) __________;
}""",
        "answers": [
            {"text": "a[index]", "fraction": "1.0"},
        ],
    },
    {
        "number": 11,
        "qtype": "essay",
        "name": "중간고사 11번",
        "mark": "10",
        "text": """count는 Counter 클래스의 멤버 변수이며, 생성된 객체 수를 저장한다. 객체가 생성될 때 count를 1 증가시키고, 소멸될 때 1 감소하도록 Counter 클래스를 완성하시오. 또한 현재 객체 수를 반환하는 getCount()도 알맞게 작성하시오. 아래 코드는 컴파일과 실행이 모두 가능해야 한다.

class Counter {
private:
    (1) ______________________
public:
    Counter() { (2) ______________________; }
    ~Counter() { (3) ______________________; }
    (4) ______________________
};

(5) ______________________""",
    },
    {
        "number": 12,
        "qtype": "essay",
        "name": "중간고사 12번",
        "mark": "6",
        "text": """다음 Circle 클래스를 사용할 때, main()을 완성하시오.

class Circle {
public:
    Circle(int r);
    int getRadius() const;
};

int main() {
    // 반지름 10인 Circle 객체 p를 동적으로 생성
    (1) ______________________

    // 객체의 반지름을 출력
    (2) ______________________

    // 동적으로 생성한 객체의 메모리를 해제
    (3) ______________________
}""",
    },
    {
        "number": 13,
        "qtype": "essay",
        "name": "중간고사 13번",
        "mark": "6",
        "text": """다음 main()이 정상 동작하도록 Circle 클래스를 완성하시오.

class Circle {
private:
    int radius;
public:
    Circle(int radius = 1) : radius(radius) { }
    int getRadius() const { return radius; }

    Circle& setRadius(int radius) {
        (1) ______________________
        (2) ______________________
    }
};

int main() {
    Circle c;
    c.setRadius(10).setRadius(20);
    cout << c.getRadius() << '\\n';
}""",
    },
    {
        "number": 14,
        "qtype": "shortanswer",
        "name": "중간고사 14번",
        "mark": "3",
        "text": """다음 생성자가 멤버 변수에 값을 제대로 저장하도록, 생성자 본문 한 줄을 올바르게 쓰시오.

class Circle {
private:
    int radius;
public:
    Circle(int radius) {
        (1) ______________________
    }
};""",
        "answers": [
            {"text": "this->radius = radius;", "fraction": "1.0"},
            {"text": "this->radius=radius;", "fraction": "1.0"},
        ],
    },
    {
        "number": 15,
        "qtype": "essay",
        "name": "중간고사 15번",
        "mark": "5",
        "text": """다음 코드에서 이름이 빈 줄로 들어갈 수 있다.

int age;
string name;

cin >> age;
getline(cin, name);

- 원인:
- 수정 코드 1줄:""",
    },
    {
        "number": 16,
        "qtype": "essay",
        "name": "중간고사 16번",
        "mark": "6",
        "text": """다음 코드의 문제를 2가지 쓰고, 한 가지 가능한 수정안을 쓰시오.

int* p = new int[3];
for (int i = 0; i < 3; i++) {
    p[i] = i * 10;
}
delete p;
cout << p[1] << '\\n';

- 문제 1:
- 문제 2:
- 수정안:""",
    },
    {
        "number": 17,
        "qtype": "essay",
        "name": "중간고사 17번",
        "mark": "6",
        "text": """다음 코드의 각 호출에 대해 정상 또는 오류만 쓰시오.

int sum(int a) { return a; }
int sum(int a, int b = 0) { return a + b; }

int main() {
    sum(3);
    sum(3, 4);
    sum('a');
}

- sum(3):
- sum(3, 4):
- sum('a'): """,
    },
    {
        "number": 18,
        "qtype": "essay",
        "name": "중간고사 18번",
        "mark": "4",
        "text": """다음 코드의 오류를 설명하고, 한 가지 수정 방법을 쓰시오.

class Person {
private:
    int money;
public:
    static int getMoney() { return money; }
};

- 오류 원인:
- 수정 방법 1가지:""",
    },
    {
        "number": 19,
        "qtype": "shortanswer",
        "name": "중간고사 19번",
        "mark": "4",
        "text": """다음 코드의 출력 결과를 쓰시오.

class Sample {
public:
    Sample() { cout << "A"; }
    Sample(const Sample& s) { cout << "B"; }
};

void func(Sample x) { }

int main() {
    Sample a;
    Sample b = a;
    func(a);
}""",
        "answers": [
            {"text": "ABB", "fraction": "1.0"},
        ],
    },
    {
        "number": 20,
        "qtype": "essay",
        "name": "중간고사 20번",
        "mark": "8",
        "text": """다음 함수는 문제가 있다.

int& maxValue() {
    int x = 10;
    return x;
}

- 문제점:
- 수정 방법 1가지:""",
    },
    {
        "number": 21,
        "qtype": "essay",
        "name": "중간고사 21번",
        "mark": "6",
        "text": """다음 코드에서 잘못된 부분을 찾고, 왜 문제가 되는지 설명한 뒤, 핵심 수정 코드를 쓰시오.

class Person {
private:
    char* name;
public:
    Person(const char* s) {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    Person(const Person& p) {
        name = p.name;
    }

    ~Person() { delete[] name; }
};

- 잘못된 줄:
- 이유:
- 핵심 수정 코드:""",
    },
    {
        "number": 22,
        "qtype": "essay",
        "name": "중간고사 22번",
        "mark": "6",
        "text": """다음 main()에서 string s = \"apple:banana\"; 를 사용하여 ':' 앞 문자열과 뒤 문자열을 각각 한 줄씩 출력하도록 코드를 완성하시오.

사용 가능 함수:
- find
- substr

int main() {
    string s = "apple:banana";
    (1) ______________________
    (2) ______________________
    (3) ______________________
}""",
    },
]


def run_applescript(script: str) -> str:
    result = subprocess.run(
        ["osascript", "-e", script],
        check=True,
        capture_output=True,
        text=True,
    )
    return result.stdout.strip()


def safari_js(js: str) -> str:
    script = f'tell application "Safari" to do JavaScript {json.dumps(js, ensure_ascii=False)} in current tab of front window'
    return run_applescript(script)


def safari_url() -> str:
    return run_applescript('tell application "Safari" to return URL of current tab of front window')


def safari_open(url: str) -> None:
    run_applescript(f'tell application "Safari" to set URL of current tab of front window to {json.dumps(url)}')


def wait_until(predicate, timeout: float = 20.0, interval: float = 0.5) -> None:
    deadline = time.time() + timeout
    while time.time() < deadline:
        if predicate():
            return
        time.sleep(interval)
    raise RuntimeError("Timed out waiting for Safari/eCampus state.")


def page_url(question_type: str) -> str:
    return (
        "https://ecampus.kookmin.ac.kr/question/question.php"
        f"?courseid={COURSE_ID}&sesskey={SESSKEY}&qtype={question_type}"
        f"&returnurl=%2Fquestion%2Fedit.php%3Fcourseid%3D{COURSE_ID}&category={CATEGORY}"
    )


def edit_url() -> str:
    return f"https://ecampus.kookmin.ac.kr/question/edit.php?courseid={COURSE_ID}"


def ensure_form_loaded(question_type: str) -> None:
    target = f"qtype={question_type}"
    wait_until(lambda: target in safari_url())
    wait_until(lambda: safari_js('!!document.getElementById("id_name") && !!document.getElementById("id_submitbutton")') == "true")


def submit_multichoice(question: dict) -> None:
    safari_open(page_url("multichoice"))
    ensure_form_loaded("multichoice")
    js = (
        "(function(){"
        f"var q={json.dumps(question, ensure_ascii=False)};"
        'function setEditor(el,text){'
        'if(!el) return;'
        'el.value=text;'
        'var ed=el.parentElement && el.parentElement.querySelector(".editor_atto_content");'
        'if(ed){ed.innerHTML="";ed.textContent=text;ed.dispatchEvent(new Event("input",{bubbles:true}));ed.dispatchEvent(new Event("change",{bubbles:true}));}'
        '}'
        'document.getElementById("id_name").value=q.name;'
        'setEditor(document.getElementById("id_questiontext"),q.text);'
        'document.getElementById("id_defaultmark").value=q.mark;'
        'q.answers.forEach(function(ans,i){'
        'var answer=document.getElementsByName("answer["+i+"][text]")[0];'
        'var fraction=document.getElementsByName("fraction["+i+"]")[0];'
        'setEditor(answer,ans.text);'
        'if(fraction) fraction.value=ans.fraction;'
        "});"
        'document.getElementById("id_submitbutton").click();'
        'return "ok";'
        "})();"
    )
    safari_js(js)


def submit_shortanswer(question: dict) -> None:
    safari_open(page_url("shortanswer"))
    ensure_form_loaded("shortanswer")
    js = (
        "(function(){"
        f"var q={json.dumps(question, ensure_ascii=False)};"
        'function setEditor(el,text){'
        'if(!el) return;'
        'el.value=text;'
        'var ed=el.parentElement && el.parentElement.querySelector(".editor_atto_content");'
        'if(ed){ed.innerHTML="";ed.textContent=text;ed.dispatchEvent(new Event("input",{bubbles:true}));ed.dispatchEvent(new Event("change",{bubbles:true}));}'
        '}'
        'document.getElementById("id_name").value=q.name;'
        'setEditor(document.getElementById("id_questiontext"),q.text);'
        'document.getElementById("id_defaultmark").value=q.mark;'
        'q.answers.forEach(function(ans,i){'
        'var answer=document.getElementsByName("answer["+i+"]")[0];'
        'var fraction=document.getElementsByName("fraction["+i+"]")[0];'
        'if(answer) answer.value=ans.text;'
        'if(fraction) fraction.value=ans.fraction;'
        "});"
        'document.getElementById("id_submitbutton").click();'
        'return "ok";'
        "})();"
    )
    safari_js(js)


def submit_essay(question: dict) -> None:
    safari_open(page_url("essay"))
    ensure_form_loaded("essay")
    js = (
        "(function(){"
        f"var q={json.dumps(question, ensure_ascii=False)};"
        'function setEditor(el,text){'
        'if(!el) return;'
        'el.value=text;'
        'var ed=el.parentElement && el.parentElement.querySelector(".editor_atto_content");'
        'if(ed){ed.innerHTML="";ed.textContent=text;ed.dispatchEvent(new Event("input",{bubbles:true}));ed.dispatchEvent(new Event("change",{bubbles:true}));}'
        '}'
        'document.getElementById("id_name").value=q.name;'
        'setEditor(document.getElementById("id_questiontext"),q.text);'
        'document.getElementById("id_defaultmark").value=q.mark;'
        'document.getElementById("id_submitbutton").click();'
        'return "ok";'
        "})();"
    )
    safari_js(js)


def wait_for_saved(name: str) -> None:
    wait_until(lambda: "/question/edit.php" in safari_url())
    wait_until(lambda: safari_js(f'document.documentElement.outerHTML.includes({json.dumps(name)})') == "true")


def submit_question(question: dict) -> None:
    if question["qtype"] == "multichoice":
        submit_multichoice(question)
    elif question["qtype"] == "shortanswer":
        submit_shortanswer(question)
    elif question["qtype"] == "essay":
        submit_essay(question)
    else:
        raise ValueError(f"Unsupported qtype: {question['qtype']}")
    wait_for_saved(question["name"])


def main() -> int:
    start_number = 2
    end_number = None
    if len(sys.argv) > 1:
        start_number = int(sys.argv[1])
    if len(sys.argv) > 2:
        end_number = int(sys.argv[2])

    for question in QUESTIONS:
        if question["number"] < start_number:
            continue
        if end_number is not None and question["number"] > end_number:
            break
        print(f"Registering {question['name']} ({question['qtype']})...", flush=True)
        submit_question(question)
        print(f"Saved {question['name']}", flush=True)
        time.sleep(0.7)

    print("All requested questions saved.", flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
