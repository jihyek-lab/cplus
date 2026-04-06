#!/usr/bin/env python3
from __future__ import annotations

import html
import json
import re
import uuid
from datetime import datetime
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import parse_qs, urlparse


HOST = "127.0.0.1"
PORT = 8000
EXAM_DURATION_MINUTES = 75

BASE_DIR = Path(__file__).resolve().parent
DATA_DIR = BASE_DIR / "data"
SUBMISSIONS_DIR = DATA_DIR / "submissions"


def code_html(code: str, language: str = "cpp") -> str:
    escaped = html.escape(code)
    return f'<pre><code class="language-{language}">{escaped}</code></pre>'


SECTIONS = [
    {"key": "A", "title": "A. 객관식 / 짧은 판단"},
    {"key": "B", "title": "B. 코드 작성 / 완성"},
    {"key": "C", "title": "C. 코드 분석 / 오류 수정"},
    {"key": "D", "title": "D. 출력 예측 / 심화 분석"},
]


QUESTIONS = [
    {
        "id": 1,
        "section": "A",
        "points": 2,
        "title": "`class`의 기본 접근 지정자",
        "body_html": "",
        "fields": [
            {
                "name": "q1",
                "type": "radio",
                "label": "답",
                "options": [("1", "public"), ("2", "protected"), ("3", "private"), ("4", "static")],
            }
        ],
    },
    {
        "id": 2,
        "section": "A",
        "points": 2,
        "title": "원본 값이 바뀔 수 있는 전달 방식",
        "body_html": "",
        "fields": [
            {
                "name": "q2",
                "type": "radio",
                "label": "답",
                "options": [
                    ("1", "값 전달"),
                    ("2", "값 전달, 주소 전달"),
                    ("3", "주소 전달, 참조 전달"),
                    ("4", "값 전달, 참조 전달"),
                ],
            }
        ],
    },
    {
        "id": 3,
        "section": "A",
        "points": 2,
        "title": "`char a[20]`, `char b[20]` 내용 비교",
        "body_html": "",
        "fields": [
            {
                "name": "q3",
                "type": "radio",
                "label": "답",
                "options": [
                    ("1", "a == b"),
                    ("2", "strcmp(a, b) == 0"),
                    ("3", "a = b"),
                    ("4", "cin >> a"),
                ],
            }
        ],
    },
    {
        "id": 4,
        "section": "A",
        "points": 2,
        "title": "함수 오버로딩을 구분하는 기준",
        "body_html": "",
        "fields": [
            {
                "name": "q4",
                "type": "radio",
                "label": "답",
                "options": [
                    ("1", "리턴 타입"),
                    ("2", "함수 본문 길이"),
                    ("3", "매개변수 개수와 타입"),
                    ("4", "주석 내용"),
                ],
            }
        ],
    },
    {
        "id": 5,
        "section": "A",
        "points": 2,
        "title": "static 멤버 함수에서 non-static 멤버 변수에 직접 접근할 수 없는 이유",
        "body_html": "",
        "fields": [
            {
                "name": "q5",
                "type": "radio",
                "label": "답",
                "options": [
                    ("1", "static 함수는 리턴값이 없어서"),
                    ("2", "static 함수에는 this가 없어서"),
                    ("3", "static 함수는 public만 접근해서"),
                    ("4", "static 함수는 항상 전역 함수라서"),
                ],
            }
        ],
    },
    {
        "id": 6,
        "section": "A",
        "points": 4,
        "title": "실행 결과 쓰기",
        "body_html": code_html(
            """class A {
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
}"""
        ),
        "fields": [{"name": "q6", "type": "text", "label": "출력 결과", "placeholder": "실행 결과를 입력하세요"}],
    },
    {
        "id": 7,
        "section": "A",
        "points": 4,
        "title": "배열 선언 가능 여부와 이유",
        "body_html": code_html(
            """class A {
public:
    int x;
};

class B {
public:
    B(int n) { }
};

A arr1[3];
B arr2[3];"""
        ),
        "fields": [
            {
                "name": "q7_arr1_decision",
                "type": "select",
                "label": "arr1",
                "options": [("", "선택"), ("가능", "가능"), ("불가", "불가")],
            },
            {"name": "q7_arr1_reason", "type": "text", "label": "arr1 이유", "placeholder": "이유를 짧게 쓰세요"},
            {
                "name": "q7_arr2_decision",
                "type": "select",
                "label": "arr2",
                "options": [("", "선택"), ("가능", "가능"), ("불가", "불가")],
            },
            {"name": "q7_arr2_reason", "type": "text", "label": "arr2 이유", "placeholder": "이유를 짧게 쓰세요"},
        ],
    },
    {
        "id": 8,
        "section": "B",
        "points": 4,
        "title": '문자열 "250"을 정수로 변환',
        "body_html": code_html('string s = "250";\nint n = (1) __________;'),
        "fields": [{"name": "q8_1", "type": "text", "label": "(1)", "placeholder": "코드를 입력하세요"}],
    },
    {
        "id": 9,
        "section": "B",
        "points": 4,
        "title": "참조를 이용한 swap 완성",
        "body_html": "<p><code>swapByRef(int& a, int& b)</code>의 핵심 코드 세 줄을 쓰시오.</p>",
        "fields": [
            {"name": "q9_1", "type": "text", "label": "(1)"},
            {"name": "q9_2", "type": "text", "label": "(2)"},
            {"name": "q9_3", "type": "text", "label": "(3)"},
        ],
    },
    {
        "id": 10,
        "section": "B",
        "points": 4,
        "title": "배열 원소를 참조로 반환",
        "body_html": code_html(
            """int& arrElem(int a[], int index) {
    return (1) __________;
}"""
        ),
        "fields": [{"name": "q10_1", "type": "text", "label": "(1)"}],
    },
    {
        "id": 11,
        "section": "B",
        "points": 10,
        "title": "객체 수를 세는 Counter 클래스 완성",
        "body_html": "<p><code>count</code>는 <code>Counter</code> 클래스의 멤버 변수이며, 생성된 객체 수를 저장한다. 객체가 생성될 때 1 증가하고, 소멸될 때 1 감소하도록 하시오. 현재 객체 수를 반환하는 <code>getCount()</code>도 작성하시오.</p>"
        + code_html(
            """class Counter {
private:
    (1) ______________________
public:
    Counter() { (2) ______________________; }
    ~Counter() { (3) ______________________; }
    (4) ______________________
};

(5) ______________________"""
        ),
        "fields": [
            {"name": "q11_1", "type": "text", "label": "(1)"},
            {"name": "q11_2", "type": "text", "label": "(2)"},
            {"name": "q11_3", "type": "text", "label": "(3)"},
            {"name": "q11_4", "type": "text", "label": "(4)"},
            {"name": "q11_5", "type": "text", "label": "(5)"},
        ],
    },
    {
        "id": 12,
        "section": "B",
        "points": 6,
        "title": "객체 포인터로 생성, 사용, 해제",
        "body_html": code_html(
            """class Circle {
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
}"""
        ),
        "fields": [
            {"name": "q12_1", "type": "text", "label": "(1)"},
            {"name": "q12_2", "type": "text", "label": "(2)"},
            {"name": "q12_3", "type": "text", "label": "(3)"},
        ],
    },
    {
        "id": 13,
        "section": "B",
        "points": 6,
        "title": "this와 *this를 이용한 멤버 함수 구현",
        "body_html": code_html(
            """class Circle {
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
}"""
        ),
        "fields": [
            {"name": "q13_1", "type": "text", "label": "(1)"},
            {"name": "q13_2", "type": "text", "label": "(2)"},
        ],
    },
    {
        "id": 14,
        "section": "B",
        "points": 3,
        "title": "this를 이용한 생성자 수정",
        "body_html": code_html(
            """class Circle {
private:
    int radius;
public:
    Circle(int radius) {
        (1) ______________________
    }
};"""
        ),
        "fields": [{"name": "q14_1", "type": "text", "label": "(1)"}],
    },
    {
        "id": 15,
        "section": "C",
        "points": 5,
        "title": "입력 버퍼 분석",
        "body_html": code_html(
            """int age;
string name;

cin >> age;
getline(cin, name);"""
        ),
        "fields": [
            {"name": "q15_cause", "type": "textarea", "label": "원인", "rows": 2},
            {"name": "q15_fix", "type": "text", "label": "수정 코드 1줄"},
        ],
    },
    {
        "id": 16,
        "section": "C",
        "points": 6,
        "title": "동적 메모리 해제 오류",
        "body_html": code_html(
            """int* p = new int[3];
for (int i = 0; i < 3; i++) {
    p[i] = i * 10;
}
delete p;
cout << p[1] << '\\n';"""
        ),
        "fields": [
            {"name": "q16_problem1", "type": "textarea", "label": "문제 1", "rows": 2},
            {"name": "q16_problem2", "type": "textarea", "label": "문제 2", "rows": 2},
            {"name": "q16_fix", "type": "textarea", "label": "수정안", "rows": 3},
        ],
    },
    {
        "id": 17,
        "section": "C",
        "points": 6,
        "title": "오버로딩 모호성 분석",
        "body_html": code_html(
            """int sum(int a) { return a; }
int sum(int a, int b = 0) { return a + b; }

int main() {
    sum(3);
    sum(3, 4);
    sum('a');
}"""
        ),
        "fields": [
            {
                "name": "q17_a",
                "type": "select",
                "label": "sum(3)",
                "options": [("", "선택"), ("정상", "정상"), ("오류", "오류")],
            },
            {
                "name": "q17_b",
                "type": "select",
                "label": "sum(3, 4)",
                "options": [("", "선택"), ("정상", "정상"), ("오류", "오류")],
            },
            {
                "name": "q17_c",
                "type": "select",
                "label": "sum('a')",
                "options": [("", "선택"), ("정상", "정상"), ("오류", "오류")],
            },
        ],
    },
    {
        "id": 18,
        "section": "C",
        "points": 4,
        "title": "static 함수의 제한 분석",
        "body_html": code_html(
            """class Person {
private:
    int money;
public:
    static int getMoney() { return money; }
};"""
        ),
        "fields": [
            {"name": "q18_cause", "type": "textarea", "label": "오류 원인", "rows": 2},
            {"name": "q18_fix", "type": "textarea", "label": "수정 방법 1가지", "rows": 2},
        ],
    },
    {
        "id": 19,
        "section": "D",
        "points": 4,
        "title": "복사 생성자 호출 분석",
        "body_html": code_html(
            """class Sample {
public:
    Sample() { cout << "A"; }
    Sample(const Sample& s) { cout << "B"; }
};

void func(Sample x) { }

int main() {
    Sample a;
    Sample b = a;
    func(a);
}"""
        ),
        "fields": [{"name": "q19", "type": "text", "label": "출력 결과", "placeholder": "출력 결과를 입력하세요"}],
    },
    {
        "id": 20,
        "section": "D",
        "points": 6,
        "title": "참조 반환의 위험",
        "body_html": code_html(
            """int& maxValue() {
    int x = 10;
    return x;
}"""
        ),
        "fields": [
            {"name": "q20_problem", "type": "textarea", "label": "문제점", "rows": 2},
            {"name": "q20_fix", "type": "textarea", "label": "수정 방법 1가지", "rows": 2},
        ],
    },
    {
        "id": 21,
        "section": "D",
        "points": 8,
        "title": "깊은 복사 코드 수정",
        "body_html": code_html(
            """class Person {
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
};"""
        ),
        "fields": [
            {"name": "q21_wrong", "type": "text", "label": "잘못된 줄"},
            {"name": "q21_reason", "type": "textarea", "label": "이유", "rows": 2},
            {"name": "q21_fix", "type": "textarea", "label": "핵심 수정 코드", "rows": 3},
        ],
    },
    {
        "id": 22,
        "section": "D",
        "points": 6,
        "title": "문자열 나누기 코드 작성",
        "body_html": "<p>다음 <code>main()</code>이 아래 출력 결과를 만들도록 코드를 완성하시오.</p>"
        + code_html("apple\nbanana", language="text")
        + "<p>사용 가능 함수: <code>find</code>, <code>substr</code></p>"
        + code_html(
            """int main() {
    string s = "apple:banana";
    (1) ______________________
    (2) ______________________
    (3) ______________________
}"""
        ),
        "fields": [
            {"name": "q22_1", "type": "text", "label": "(1)"},
            {"name": "q22_2", "type": "text", "label": "(2)"},
            {"name": "q22_3", "type": "text", "label": "(3)"},
        ],
    },
]
def ensure_data_dirs() -> None:
    SUBMISSIONS_DIR.mkdir(parents=True, exist_ok=True)


def now_string() -> str:
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S")


def normalize_space(value: str) -> str:
    return " ".join((value or "").strip().split())


def normalize_code(value: str) -> str:
    value = (value or "").strip()
    value = re.sub(r"\s+", "", value)
    value = value.rstrip(";")
    return value


def compact_code(value: str) -> str:
    return re.sub(r"[;\s]+", "", (value or "").strip())


def normalize_output(value: str) -> str:
    return re.sub(r"\s+", "", (value or ""))


def contains_any(value: str, keywords: list[str]) -> bool:
    lowered = (value or "").lower()
    return any(keyword.lower() in lowered for keyword in keywords)


def grade_submission(answers: dict[str, str]) -> dict:
    results = []
    total = 0
    for question in QUESTIONS:
        grader = GRADERS[question["id"]]
        result = grader(answers, question["points"])
        result["question_id"] = question["id"]
        result["title"] = question["title"]
        result["max_score"] = question["points"]
        results.append(result)
        total += result["score"]
    return {"total_score": total, "max_score": 100, "questions": results}


def exact_choice(answer: str, correct: str, points: int) -> dict:
    return {
        "score": points if answer == correct else 0,
        "notes": [f"정답: {correct}"],
    }


def grade_q1(answers: dict[str, str], points: int) -> dict:
    return exact_choice(answers.get("q1", ""), "3", points)


def grade_q2(answers: dict[str, str], points: int) -> dict:
    return exact_choice(answers.get("q2", ""), "3", points)


def grade_q3(answers: dict[str, str], points: int) -> dict:
    return exact_choice(answers.get("q3", ""), "2", points)


def grade_q4(answers: dict[str, str], points: int) -> dict:
    return exact_choice(answers.get("q4", ""), "3", points)


def grade_q5(answers: dict[str, str], points: int) -> dict:
    return exact_choice(answers.get("q5", ""), "2", points)


def grade_q6(answers: dict[str, str], points: int) -> dict:
    score = points if normalize_output(answers.get("q6", "")) == "AAaAaa" else 0
    return {"score": score, "notes": ["정답: AAaAaa"]}


def grade_q7(answers: dict[str, str], points: int) -> dict:
    score = 0
    notes = []
    if answers.get("q7_arr1_decision", "") == "가능":
        score += 1
    else:
        notes.append("arr1 판단")
    if contains_any(answers.get("q7_arr1_reason", ""), ["생성자", "기본 생성", "인수 없는 생성", "자동"]):
        score += 1
    else:
        notes.append("arr1 이유")
    if answers.get("q7_arr2_decision", "") == "불가":
        score += 1
    else:
        notes.append("arr2 판단")
    if contains_any(answers.get("q7_arr2_reason", ""), ["기본 생성자", "기본 생성 불가", "b(int)", "인자 없는", "매개변수 없는 생성자"]):
        score += 1
    else:
        notes.append("arr2 이유")
    return {"score": score, "notes": notes}


def grade_q8(answers: dict[str, str], points: int) -> dict:
    allowed = {"stoi(s)"}
    score = points if normalize_code(answers.get("q8_1", "")) in {normalize_code(x) for x in allowed} else 0
    return {"score": score, "notes": ["정답: stoi(s)"]}


def grade_q9(answers: dict[str, str], points: int) -> dict:
    expected = [
        normalize_code("int temp = a;"),
        normalize_code("a = b;"),
        normalize_code("b = temp;"),
    ]
    actual = [
        normalize_code(answers.get("q9_1", "")),
        normalize_code(answers.get("q9_2", "")),
        normalize_code(answers.get("q9_3", "")),
    ]
    return {
        "score": points if actual == expected else 0,
        "notes": ["세 줄 모두 맞으면 만점"],
    }


def grade_q10(answers: dict[str, str], points: int) -> dict:
    score = points if normalize_code(answers.get("q10_1", "")) == normalize_code("a[index]") else 0
    return {"score": score, "notes": ["정답: a[index]"]}


def grade_q11(answers: dict[str, str], points: int) -> dict:
    score = 0
    notes = []
    if normalize_code(answers.get("q11_1", "")) == normalize_code("static int count;"):
        score += 2
    else:
        notes.append("(1)")
    if normalize_code(answers.get("q11_2", "")) in {normalize_code("++count"), normalize_code("count++")}:
        score += 2
    else:
        notes.append("(2)")
    if normalize_code(answers.get("q11_3", "")) in {normalize_code("--count"), normalize_code("count--")}:
        score += 2
    else:
        notes.append("(3)")
    allowed_get_count = {
        normalize_code("static int getCount() { return count; }"),
        normalize_code("static int getCount(){return count;}"),
    }
    if normalize_code(answers.get("q11_4", "")) in allowed_get_count:
        score += 2
    else:
        notes.append("(4)")
    if normalize_code(answers.get("q11_5", "")) == normalize_code("int Counter::count = 0;"):
        score += 2
    else:
        notes.append("(5)")
    return {"score": score, "notes": notes}


def grade_q12(answers: dict[str, str], points: int) -> dict:
    score = 0
    notes = []
    if normalize_code(answers.get("q12_1", "")) == normalize_code("Circle* p = new Circle(10);"):
        score += 2
    else:
        notes.append("(1)")
    allowed_print = {
        normalize_code("cout << p->getRadius() << '\\n';"),
        normalize_code("cout << p->getRadius() << endl;"),
    }
    if normalize_code(answers.get("q12_2", "")) in allowed_print:
        score += 2
    else:
        notes.append("(2)")
    if normalize_code(answers.get("q12_3", "")) == normalize_code("delete p;"):
        score += 2
    else:
        notes.append("(3)")
    return {"score": score, "notes": notes}


def grade_q13(answers: dict[str, str], points: int) -> dict:
    score = 0
    notes = []
    if normalize_code(answers.get("q13_1", "")) == normalize_code("this->radius = radius;"):
        score += 3
    else:
        notes.append("(1)")
    if normalize_code(answers.get("q13_2", "")) == normalize_code("return *this;"):
        score += 3
    else:
        notes.append("(2)")
    return {"score": score, "notes": notes}


def grade_q14(answers: dict[str, str], points: int) -> dict:
    score = points if normalize_code(answers.get("q14_1", "")) == normalize_code("this->radius = radius;") else 0
    return {"score": score, "notes": ["정답: this->radius = radius;"]}


def grade_q15(answers: dict[str, str], points: int) -> dict:
    score = 0
    cause = answers.get("q15_cause", "")
    if contains_any(cause, ["개행", "\\n", "newline", "엔터"]) and contains_any(cause, ["버퍼", "getline", "남아", "남음"]):
        score += 3
    fix_code = normalize_code(answers.get("q15_fix", ""))
    allowed_fixes = {
        normalize_code("cin.ignore();"),
        normalize_code("cin.ignore(1, '\\n');"),
        normalize_code('cin.ignore(1, "\\n");'),
    }
    if fix_code in allowed_fixes:
        score += 2
    return {"score": score, "notes": []}


def detect_delete_issue(text: str) -> bool:
    return contains_any(text, ["delete[]", "배열", "new int[3]", "delete p"])


def detect_use_after_free_issue(text: str) -> bool:
    return contains_any(text, ["해제 후", "삭제 후", "이미 해제", "p[1]", "접근", "읽", "사용"])


def grade_q16(answers: dict[str, str], points: int) -> dict:
    score = 0
    issue1 = answers.get("q16_problem1", "")
    issue2 = answers.get("q16_problem2", "")
    matched = set()
    for text in [issue1, issue2]:
        if "delete" not in matched and detect_delete_issue(text):
            matched.add("delete")
            score += 2
            continue
        if "use_after_free" not in matched and detect_use_after_free_issue(text):
            matched.add("use_after_free")
            score += 2
    fix = answers.get("q16_fix", "")
    compact = compact_code(fix)
    has_delete_array = "delete[]p" in compact
    has_print = "cout<<p[1]<<'\\n'" in compact or 'cout<<p[1]<<"\\n"' in compact or "cout<<p[1]<<endl" in compact
    mentions_before_delete = contains_any(fix, ["먼저 출력", "출력 후 해제", "delete 전에", "삭제 전에"])
    if has_delete_array and (has_print or mentions_before_delete):
        score += 2
    return {"score": score, "notes": []}


def grade_q17(answers: dict[str, str], points: int) -> dict:
    score = 0
    if answers.get("q17_a", "") == "오류":
        score += 4
    if answers.get("q17_b", "") == "정상":
        score += 1
    if answers.get("q17_c", "") == "정상":
        score += 1
    return {"score": score, "notes": []}


def grade_q18(answers: dict[str, str], points: int) -> dict:
    score = 0
    cause = answers.get("q18_cause", "")
    if contains_any(cause, ["this"]) and contains_any(cause, ["없", "non-static", "객체", "money"]):
        score += 2
    fix = answers.get("q18_fix", "")
    if contains_any(fix, ["static 제거", "static을 제거", "person&", "const person&", "money를 static", "money를 static으로"]):
        score += 2
    return {"score": score, "notes": []}


def grade_q19(answers: dict[str, str], points: int) -> dict:
    score = points if normalize_output(answers.get("q19", "")) == "ABB" else 0
    return {"score": score, "notes": ["정답: ABB"]}


def grade_q20(answers: dict[str, str], points: int) -> dict:
    score = 0
    problem = answers.get("q20_problem", "")
    if contains_any(problem, ["지역 변수", "지역변수", "함수 종료", "사라", "return x", "참조 반환"]):
        score += 3
    fix = answers.get("q20_fix", "")
    if contains_any(fix, ["int maxvalue()", "int로 바꾸", "반환 타입을 int", "static int x", "매개변수", "외부에서 전달"]):
        score += 3
    return {"score": score, "notes": []}


def grade_q21(answers: dict[str, str], points: int) -> dict:
    score = 0
    wrong = answers.get("q21_wrong", "")
    if compact_code("name = p.name;") in compact_code(wrong) or compact_code(wrong) == compact_code("name = p.name"):
        score += 2
    reason = answers.get("q21_reason", "")
    if contains_any(reason, ["얕은 복사", "주소만 복사", "같은 메모리", "이중 해제", "double delete"]):
        score += 2
    fix = compact_code(answers.get("q21_fix", ""))
    if "name=newchar[strlen(p.name)+1]" in fix and "strcpy(name,p.name)" in fix:
        score += 4
    return {"score": score, "notes": []}


def grade_q22(answers: dict[str, str], points: int) -> dict:
    score = 0
    if normalize_code(answers.get("q22_1", "")) == normalize_code("int pos = s.find(':');"):
        score += 2
    if normalize_code(answers.get("q22_2", "")) == normalize_code("cout << s.substr(0, pos) << '\\n';"):
        score += 2
    if normalize_code(answers.get("q22_3", "")) == normalize_code("cout << s.substr(pos + 1) << '\\n';"):
        score += 2
    return {"score": score, "notes": []}


GRADERS = {
    1: grade_q1,
    2: grade_q2,
    3: grade_q3,
    4: grade_q4,
    5: grade_q5,
    6: grade_q6,
    7: grade_q7,
    8: grade_q8,
    9: grade_q9,
    10: grade_q10,
    11: grade_q11,
    12: grade_q12,
    13: grade_q13,
    14: grade_q14,
    15: grade_q15,
    16: grade_q16,
    17: grade_q17,
    18: grade_q18,
    19: grade_q19,
    20: grade_q20,
    21: grade_q21,
    22: grade_q22,
}


def load_submission(submission_id: str) -> dict | None:
    path = SUBMISSIONS_DIR / f"{submission_id}.json"
    if not path.exists():
        return None
    return json.loads(path.read_text(encoding="utf-8"))


def load_submissions() -> list[dict]:
    submissions = []
    for path in sorted(SUBMISSIONS_DIR.glob("*.json")):
        try:
            submissions.append(json.loads(path.read_text(encoding="utf-8")))
        except json.JSONDecodeError:
            continue
    submissions.sort(key=lambda item: item.get("submitted_at", ""), reverse=True)
    return submissions


def save_submission(payload: dict) -> None:
    submission_id = payload["submission_id"]
    path = SUBMISSIONS_DIR / f"{submission_id}.json"
    path.write_text(json.dumps(payload, ensure_ascii=False, indent=2), encoding="utf-8")


def page_layout(title: str, body_html: str, extra_head: str = "") -> str:
    return f"""<!doctype html>
<html lang="ko">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>{html.escape(title)}</title>
  <style>
    :root {{
      --bg: #f5f1e8;
      --panel: #fffdf8;
      --ink: #1f2a30;
      --muted: #66757f;
      --line: #d7d1c6;
      --accent: #1f6f78;
      --accent-soft: #dff1f4;
      --danger: #a33a2b;
      --code: #f3efe6;
    }}
    * {{ box-sizing: border-box; }}
    body {{
      margin: 0;
      font-family: "Pretendard", "Noto Sans KR", system-ui, sans-serif;
      color: var(--ink);
      background:
        radial-gradient(circle at top left, #fefaf0 0, transparent 32%),
        linear-gradient(180deg, #efe7d9 0%, var(--bg) 35%, #efe9df 100%);
    }}
    a {{ color: var(--accent); text-decoration: none; }}
    a:hover {{ text-decoration: underline; }}
    .shell {{
      max-width: 1080px;
      margin: 0 auto;
      padding: 24px 16px 64px;
    }}
    .topbar {{
      display: flex;
      gap: 12px;
      justify-content: space-between;
      align-items: center;
      margin-bottom: 20px;
      flex-wrap: wrap;
    }}
    .topbar .links {{
      display: flex;
      gap: 12px;
      flex-wrap: wrap;
      color: var(--muted);
      font-size: 14px;
    }}
    .hero, .card {{
      background: var(--panel);
      border: 1px solid var(--line);
      border-radius: 18px;
      box-shadow: 0 8px 24px rgba(31, 42, 48, 0.06);
    }}
    .hero {{
      padding: 22px;
      margin-bottom: 18px;
    }}
    .hero h1 {{
      margin: 0 0 8px;
      font-size: 28px;
    }}
    .hero p {{
      margin: 0;
      color: var(--muted);
      line-height: 1.6;
    }}
    .meta {{
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(180px, 1fr));
      gap: 10px;
      margin-top: 18px;
    }}
    .meta-item {{
      background: #faf6ee;
      border: 1px solid var(--line);
      border-radius: 14px;
      padding: 12px 14px;
    }}
    .meta-item strong {{
      display: block;
      font-size: 13px;
      color: var(--muted);
      margin-bottom: 6px;
    }}
    form {{
      display: grid;
      gap: 16px;
    }}
    .section-card {{
      padding: 18px;
      margin-bottom: 16px;
    }}
    .section-card h2 {{
      margin: 0 0 10px;
      font-size: 22px;
    }}
    .question {{
      border-top: 1px solid var(--line);
      padding: 18px 0 0;
      margin-top: 18px;
    }}
    .question:first-of-type {{
      border-top: 0;
      margin-top: 0;
      padding-top: 0;
    }}
    .question h3 {{
      margin: 0 0 10px;
      font-size: 19px;
    }}
    .points {{
      display: inline-block;
      margin-left: 8px;
      padding: 2px 10px;
      border-radius: 999px;
      background: var(--accent-soft);
      color: var(--accent);
      font-size: 13px;
      vertical-align: middle;
    }}
    .field {{
      margin-top: 12px;
    }}
    .field label {{
      display: block;
      font-weight: 600;
      margin-bottom: 6px;
    }}
    input[type="text"], textarea, select {{
      width: 100%;
      border: 1px solid #cbbfae;
      border-radius: 12px;
      padding: 10px 12px;
      font: inherit;
      background: white;
    }}
    textarea {{ resize: vertical; min-height: 70px; }}
    .radio-group {{
      display: grid;
      gap: 8px;
      margin-top: 10px;
    }}
    .radio-item, .select-item {{
      display: flex;
      align-items: center;
      gap: 8px;
      padding: 10px 12px;
      border: 1px solid var(--line);
      border-radius: 12px;
      background: #fcfaf6;
    }}
    pre {{
      overflow-x: auto;
      background: var(--code);
      border-radius: 14px;
      border: 1px solid #e0d7c8;
      padding: 14px;
      font-size: 14px;
      line-height: 1.55;
    }}
    code {{ font-family: "SFMono-Regular", Consolas, monospace; }}
    .submit-card {{
      position: sticky;
      bottom: 18px;
      padding: 16px;
      background: rgba(255, 253, 248, 0.94);
      backdrop-filter: blur(6px);
      margin-top: 8px;
    }}
    .submit-row {{
      display: flex;
      justify-content: space-between;
      align-items: center;
      gap: 16px;
      flex-wrap: wrap;
    }}
    .timer {{
      font-weight: 700;
      color: var(--accent);
    }}
    .btn {{
      border: 0;
      background: var(--accent);
      color: white;
      padding: 12px 18px;
      border-radius: 12px;
      font: inherit;
      font-weight: 700;
      cursor: pointer;
    }}
    .btn.secondary {{
      background: #4f6770;
    }}
    table {{
      width: 100%;
      border-collapse: collapse;
      margin-top: 12px;
    }}
    th, td {{
      text-align: left;
      padding: 10px 8px;
      border-bottom: 1px solid var(--line);
      vertical-align: top;
    }}
    .score {{
      font-size: 34px;
      font-weight: 800;
      color: var(--accent);
      margin: 6px 0;
    }}
    .muted {{ color: var(--muted); }}
    .danger {{ color: var(--danger); }}
    .pill {{
      display: inline-block;
      padding: 3px 8px;
      border-radius: 999px;
      background: #f3efe6;
      font-size: 12px;
      color: var(--muted);
    }}
    {extra_head}
  </style>
</head>
<body>
  <div class="shell">
    <div class="topbar">
      <div class="links">
        <a href="/">시험지</a>
        <a href="/admin">제출 목록</a>
        <a href="/admin/export">결과 JSON</a>
      </div>
    </div>
    {body_html}
  </div>
</body>
</html>"""


def render_field(field: dict, answers: dict[str, str]) -> str:
    value = answers.get(field["name"], "")
    label = html.escape(field.get("label", ""))
    field_type = field["type"]
    if field_type == "radio":
        items = []
        for option_value, option_label in field["options"]:
            checked = " checked" if value == option_value else ""
            items.append(
                f'<label class="radio-item"><input type="radio" name="{field["name"]}" value="{html.escape(option_value)}"{checked}>'
                f'<span>{html.escape(option_label)}</span></label>'
            )
        return f'<div class="field"><label>{label}</label><div class="radio-group">{"".join(items)}</div></div>'
    if field_type == "select":
        options = []
        for option_value, option_label in field["options"]:
            selected = " selected" if value == option_value else ""
            options.append(f'<option value="{html.escape(option_value)}"{selected}>{html.escape(option_label)}</option>')
        return f'<div class="field"><label for="{field["name"]}">{label}</label><select id="{field["name"]}" name="{field["name"]}">{"".join(options)}</select></div>'
    if field_type == "textarea":
        rows = field.get("rows", 3)
        return (
            f'<div class="field"><label for="{field["name"]}">{label}</label>'
            f'<textarea id="{field["name"]}" name="{field["name"]}" rows="{rows}"'
            f' placeholder="{html.escape(field.get("placeholder", ""))}">{html.escape(value)}</textarea></div>'
        )
    return (
        f'<div class="field"><label for="{field["name"]}">{label}</label>'
        f'<input type="text" id="{field["name"]}" name="{field["name"]}" value="{html.escape(value)}"'
        f' placeholder="{html.escape(field.get("placeholder", ""))}"></div>'
    )


def render_exam_page(saved_answers: dict[str, str] | None = None) -> str:
    answers = saved_answers or {}
    sections_html = []
    for section in SECTIONS:
        question_html = []
        for question in [q for q in QUESTIONS if q["section"] == section["key"]]:
            rendered_fields = "".join(render_field(field, answers) for field in question["fields"])
            question_html.append(
                f'<article class="question" id="q{question["id"]}">'
                f'<h3>{question["id"]}번. {html.escape(question["title"])}'
                f'<span class="points">{question["points"]}점</span></h3>'
                f'{question["body_html"]}'
                f'{rendered_fields}'
                f'</article>'
            )
        sections_html.append(
            f'<section class="card section-card"><h2>{html.escape(section["title"])}</h2>{"".join(question_html)}</section>'
        )

    body = f"""
    <section class="hero">
      <h1>C++ 중간고사 웹 시험</h1>
      <p>학생은 시험지를 웹에서 작성하고 제출할 수 있고, 제출 즉시 자동 채점됩니다. 제출 결과는 관리자 화면에서 모두 모아볼 수 있습니다.</p>
      <div class="meta">
        <div class="meta-item"><strong>범위</strong>Chapter 1 ~ Chapter 6</div>
        <div class="meta-item"><strong>시험시간</strong>{EXAM_DURATION_MINUTES}분</div>
        <div class="meta-item"><strong>총점</strong>100점</div>
      </div>
    </section>

    <form id="exam-form" method="post" action="/submit">
      <section class="card section-card">
        <h2>응시 정보</h2>
        {render_field({"name": "student_id", "type": "text", "label": "학번"}, answers)}
        {render_field({"name": "student_name", "type": "text", "label": "이름"}, answers)}
      </section>
      {"".join(sections_html)}
      <section class="card submit-card">
        <div class="submit-row">
          <div>
            <div class="timer" id="timer">남은 시간 계산 중...</div>
            <div class="muted">시간이 끝나면 현재 입력된 답안으로 자동 제출됩니다.</div>
          </div>
          <button class="btn" type="submit">시험 제출</button>
        </div>
      </section>
    </form>
    <script>
      const durationMinutes = {EXAM_DURATION_MINUTES};
      const storageKey = "cplus-midterm-start-time";
      const submittedKey = "cplus-midterm-submitted";
      const form = document.getElementById("exam-form");
      const timerEl = document.getElementById("timer");
      let startTime = localStorage.getItem(storageKey);
      if (!startTime || localStorage.getItem(submittedKey) === "1") {{
        startTime = String(Date.now());
        localStorage.setItem(storageKey, startTime);
        localStorage.removeItem(submittedKey);
      }}
      startTime = Number(startTime);

      function formatTime(ms) {{
        const totalSeconds = Math.max(0, Math.floor(ms / 1000));
        const minutes = String(Math.floor(totalSeconds / 60)).padStart(2, "0");
        const seconds = String(totalSeconds % 60).padStart(2, "0");
        return `${{minutes}}:${{seconds}}`;
      }}

      function tick() {{
        const endTime = startTime + durationMinutes * 60 * 1000;
        const remaining = endTime - Date.now();
        if (remaining <= 0) {{
          timerEl.textContent = "남은 시간 00:00";
          localStorage.setItem(submittedKey, "1");
          form.submit();
          return;
        }}
        timerEl.textContent = `남은 시간 ${{formatTime(remaining)}}`;
      }}

      form.addEventListener("submit", () => {{
        localStorage.setItem(submittedKey, "1");
      }});

      tick();
      setInterval(tick, 1000);
    </script>
    """
    return page_layout("C++ 중간고사 웹 시험", body)


def render_result_page(payload: dict) -> str:
    result = payload["result"]
    rows = "".join(
        f"<tr><td>{item['question_id']}번</td><td>{html.escape(item['title'])}</td>"
        f"<td>{item['score']} / {item['max_score']}</td></tr>"
        for item in result["questions"]
    )
    body = f"""
    <section class="hero">
      <h1>제출이 완료되었습니다</h1>
      <p>답안이 저장되었고 자동 채점도 끝났습니다. 아래 점수는 현재 기준 자동 채점 결과입니다.</p>
      <div class="score">{result['total_score']} / {result['max_score']}</div>
      <div class="muted">제출 번호: {html.escape(payload['submission_id'])}</div>
      <div class="muted">제출 시각: {html.escape(payload['submitted_at'])}</div>
    </section>
    <section class="card section-card">
      <h2>응시자 정보</h2>
      <table>
        <tr><th>학번</th><td>{html.escape(payload.get('student_id', ''))}</td></tr>
        <tr><th>이름</th><td>{html.escape(payload.get('student_name', ''))}</td></tr>
      </table>
    </section>
    <section class="card section-card">
      <h2>문항별 자동 채점 결과</h2>
      <table>
        <thead><tr><th>문항</th><th>내용</th><th>점수</th></tr></thead>
        <tbody>{rows}</tbody>
      </table>
    </section>
    """
    return page_layout("제출 완료", body)


def render_admin_page() -> str:
    submissions = load_submissions()
    rows = []
    for submission in submissions:
        rows.append(
            "<tr>"
            f"<td>{html.escape(submission['submission_id'])}</td>"
            f"<td>{html.escape(submission.get('student_id', ''))}</td>"
            f"<td>{html.escape(submission.get('student_name', ''))}</td>"
            f"<td>{submission['result']['total_score']} / {submission['result']['max_score']}</td>"
            f"<td>{html.escape(submission['submitted_at'])}</td>"
            f'<td><a href="/submission?id={html.escape(submission["submission_id"])}">상세 보기</a></td>'
            "</tr>"
        )
    table_body = "".join(rows) if rows else '<tr><td colspan="6" class="muted">아직 제출이 없습니다.</td></tr>'
    body = f"""
    <section class="hero">
      <h1>제출 목록</h1>
      <p>학생 제출 결과와 자동 채점 점수를 한곳에서 볼 수 있습니다.</p>
    </section>
    <section class="card section-card">
      <div class="submit-row">
        <h2 style="margin:0;">전체 제출</h2>
        <a class="btn secondary" href="/admin/export">결과 JSON 다운로드</a>
      </div>
      <table>
        <thead>
          <tr><th>제출 번호</th><th>학번</th><th>이름</th><th>점수</th><th>제출 시각</th><th>상세</th></tr>
        </thead>
        <tbody>{table_body}</tbody>
      </table>
    </section>
    """
    return page_layout("제출 목록", body)


def render_submission_detail(submission: dict) -> str:
    question_rows = []
    answers = submission.get("answers", {})
    result_by_id = {item["question_id"]: item for item in submission["result"]["questions"]}
    for question in QUESTIONS:
        result = result_by_id[question["id"]]
        field_rows = []
        for field in question["fields"]:
            field_rows.append(
                f"<tr><th>{html.escape(field['label'])}</th><td><pre><code>{html.escape(answers.get(field['name'], ''))}</code></pre></td></tr>"
            )
        notes = ", ".join(result.get("notes", [])) or "-"
        question_rows.append(
            f'<section class="card section-card"><h2>{question["id"]}번. {html.escape(question["title"])}'
            f'<span class="points">{result["score"]} / {result["max_score"]}</span></h2>'
            f'<table>{"".join(field_rows)}<tr><th>자동 채점 메모</th><td>{html.escape(notes)}</td></tr></table></section>'
        )
    body = f"""
    <section class="hero">
      <h1>제출 상세</h1>
      <p>학번 {html.escape(submission.get('student_id', ''))} / 이름 {html.escape(submission.get('student_name', ''))}</p>
      <div class="score">{submission['result']['total_score']} / {submission['result']['max_score']}</div>
      <div class="muted">제출 번호: {html.escape(submission['submission_id'])}</div>
      <div class="muted">제출 시각: {html.escape(submission['submitted_at'])}</div>
    </section>
    {"".join(question_rows)}
    """
    return page_layout("제출 상세", body)


class ExamHandler(BaseHTTPRequestHandler):
    def do_GET(self) -> None:
        parsed = urlparse(self.path)
        if parsed.path == "/":
            self.respond_html(render_exam_page())
            return
        if parsed.path == "/admin":
            self.respond_html(render_admin_page())
            return
        if parsed.path == "/submission":
            query = parse_qs(parsed.query)
            submission_id = query.get("id", [""])[0]
            submission = load_submission(submission_id)
            if not submission:
                self.respond_not_found("제출 정보를 찾지 못했습니다.")
                return
            self.respond_html(render_submission_detail(submission))
            return
        if parsed.path == "/admin/export":
            self.respond_json(load_submissions())
            return
        self.respond_not_found("페이지를 찾지 못했습니다.")

    def do_POST(self) -> None:
        parsed = urlparse(self.path)
        if parsed.path != "/submit":
            self.respond_not_found("지원하지 않는 요청입니다.")
            return

        content_length = int(self.headers.get("Content-Length", "0"))
        raw = self.rfile.read(content_length).decode("utf-8")
        parsed_body = parse_qs(raw, keep_blank_values=True)
        answers = {key: values[0] for key, values in parsed_body.items()}

        payload = {
            "submission_id": uuid.uuid4().hex[:12],
            "submitted_at": now_string(),
            "student_id": answers.get("student_id", "").strip(),
            "student_name": answers.get("student_name", "").strip(),
            "answers": answers,
        }
        payload["result"] = grade_submission(answers)
        save_submission(payload)
        self.respond_html(render_result_page(payload))

    def log_message(self, format: str, *args) -> None:
        return

    def respond_html(self, body: str, status: HTTPStatus = HTTPStatus.OK) -> None:
        encoded = body.encode("utf-8")
        self.send_response(status.value)
        self.send_header("Content-Type", "text/html; charset=utf-8")
        self.send_header("Content-Length", str(len(encoded)))
        self.end_headers()
        self.wfile.write(encoded)

    def respond_json(self, payload: object, status: HTTPStatus = HTTPStatus.OK) -> None:
        encoded = json.dumps(payload, ensure_ascii=False, indent=2).encode("utf-8")
        self.send_response(status.value)
        self.send_header("Content-Type", "application/json; charset=utf-8")
        self.send_header("Content-Length", str(len(encoded)))
        self.end_headers()
        self.wfile.write(encoded)

    def respond_not_found(self, message: str) -> None:
        body = page_layout("Not Found", f'<section class="hero"><h1>404</h1><p>{html.escape(message)}</p></section>')
        self.respond_html(body, status=HTTPStatus.NOT_FOUND)


def main() -> None:
    ensure_data_dirs()
    server = ThreadingHTTPServer((HOST, PORT), ExamHandler)
    print(f"Exam server is running at http://{HOST}:{PORT}")
    print(f"Admin page: http://{HOST}:{PORT}/admin")
    server.serve_forever()


if __name__ == "__main__":
    main()
