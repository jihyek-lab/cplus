#!/usr/bin/env python3
import html
import json
import re
import subprocess
import sys
import time


COURSE_ID = "83507"
SESSKEY = "LVQpVWSRfu"
QUIZ_CMID = "1893201"
CATEGORY = "117862,2203162"
QUESTION_PREFIX = "C++ 기말고사"


QUESTIONS = [
    {"number": 1, "name": f"{QUESTION_PREFIX} 01번", "mark": "4"},
    {"number": 2, "name": f"{QUESTION_PREFIX} 02번", "mark": "4"},
    {"number": 3, "name": f"{QUESTION_PREFIX} 03번", "mark": "6"},
    {"number": 4, "name": f"{QUESTION_PREFIX} 04번", "mark": "2"},
    {"number": 5, "name": f"{QUESTION_PREFIX} 05번", "mark": "2"},
    {"number": 6, "name": f"{QUESTION_PREFIX} 06번", "mark": "2"},
    {"number": 7, "name": f"{QUESTION_PREFIX} 07번", "mark": "2"},
    {"number": 8, "name": f"{QUESTION_PREFIX} 08번", "mark": "2"},
    {"number": 9, "name": f"{QUESTION_PREFIX} 09번", "mark": "2"},
    {"number": 10, "name": f"{QUESTION_PREFIX} 10번", "mark": "3"},
    {"number": 11, "name": f"{QUESTION_PREFIX} 11번", "mark": "4"},
    {"number": 12, "name": f"{QUESTION_PREFIX} 12번", "mark": "6"},
    {"number": 13, "name": f"{QUESTION_PREFIX} 13번", "mark": "5"},
    {"number": 14, "name": f"{QUESTION_PREFIX} 14번", "mark": "4"},
    {"number": 15, "name": f"{QUESTION_PREFIX} 15번", "mark": "5"},
    {"number": 16, "name": f"{QUESTION_PREFIX} 16번", "mark": "6"},
    {"number": 17, "name": f"{QUESTION_PREFIX} 17번", "mark": "6"},
    {"number": 18, "name": f"{QUESTION_PREFIX} 18번", "mark": "7"},
    {"number": 19, "name": f"{QUESTION_PREFIX} 19번", "mark": "8"},
    {"number": 20, "name": f"{QUESTION_PREFIX} 20번", "mark": "10"},
    {"number": 21, "name": f"{QUESTION_PREFIX} 21번", "mark": "10"},
]


def run_applescript(script: str) -> str:
    result = subprocess.run(
        ["osascript", "-e", script],
        check=True,
        capture_output=True,
        text=True,
    )
    return result.stdout.strip()


def safari_find_ecampus_tab() -> None:
    script = r'''
tell application "Safari"
  repeat with w in windows
    repeat with t in tabs of w
      set u to URL of t
      if u contains "ecampus.kookmin.ac.kr" then
        set current tab of w to t
        set index of w to 1
        activate
        return
      end if
    end repeat
  end repeat
end tell
'''
    run_applescript(script)


def safari_open(url: str) -> None:
    safari_find_ecampus_tab()
    script = f'''
tell application "Safari"
  set URL of current tab of front window to {json.dumps(url, ensure_ascii=False)}
end tell
'''
    run_applescript(script)


def safari_url() -> str:
    safari_find_ecampus_tab()
    return run_applescript('tell application "Safari" to return URL of current tab of front window')


def safari_js(js: str) -> str:
    safari_find_ecampus_tab()
    script = f'''
tell application "Safari"
  return do JavaScript {json.dumps(js, ensure_ascii=False)} in current tab of front window
end tell
'''
    return run_applescript(script)


def wait_until(predicate, timeout: float = 30.0, interval: float = 0.5) -> None:
    deadline = time.time() + timeout
    last_error = None
    while time.time() < deadline:
        try:
            if predicate():
                return
        except Exception as exc:
            last_error = exc
        time.sleep(interval)
    raise RuntimeError(f"Timed out waiting for Safari/eCampus state. Last error: {last_error}")


def p(text: str) -> str:
    return f"<p>{html.escape(text)}</p>"


def code_block(code: str) -> str:
    return f"<pre><code>{html.escape(code)}</code></pre>"


def ol(items: list[str]) -> str:
    return "<ol>" + "".join(f"<li>{html.escape(item)}</li>" for item in items) + "</ol>"


def ul(items: list[str]) -> str:
    return "<ul>" + "".join(f"<li>{html.escape(item)}</li>" for item in items) + "</ul>"


def blanks(items: list[str]) -> str:
    return "<ul>" + "".join(f"<li>{html.escape(item)}: ____________________</li>" for item in items) + "</ul>"


def html_for_question(number: int) -> str:
    if number == 1:
        return (
            p("다음 코드에서 Power p(5);라고 할 때 3 + p가 가능하도록 빈칸을 채우시오. 여기서 p는 오른쪽 피연산자인 Power 객체이다.")
            + code_block(
                "class Power {\n"
                "    int value;\n"
                "public:\n"
                "    Power(int value = 0) : value(value) { }\n"
                "    int get() const { return value; }\n\n"
                "    (1) __________\n"
                "};\n\n"
                "(2) __________ {\n"
                "    return Power(n + p.value);\n"
                "}\n"
            )
        )
    if number == 2:
        return p("다음 코드의 출력 결과를 쓰시오.") + code_block(
            "class Num {\n"
            "    int value;\n"
            "public:\n"
            "    Num(int value = 0) : value(value) { }\n"
            "    Num& operator+=(const Num& other) {\n"
            "        value += other.value;\n"
            "        return *this;\n"
            "    }\n"
            "    int get() const { return value; }\n"
            "};\n\n"
            "int main() {\n"
            "    Num a(1), b(2), c(3);\n"
            "    a += b += c;\n"
            "    cout << a.get() << \" \" << b.get();\n"
            "}\n"
        )
    if number == 3:
        return (
            p("다음 Num 클래스에서 전위 증가 ++a와 후위 증가 a++가 모두 동작하도록 두 연산자 함수를 완성하시오.")
            + ul([
                "전위 증가 ++a: 값을 1 증가시킨 뒤, 증가된 현재 객체를 반환한다.",
                "후위 증가 a++: 증가 전 객체를 반환하고, 현재 객체의 값은 1 증가시킨다.",
            ])
            + code_block(
                "class Num {\n"
                "    int value;\n"
                "public:\n"
                "    Num(int value = 0) : value(value) { }\n"
                "    int get() const { return value; }\n\n"
                "    // 전위 증가 연산자 함수 전체를 작성하시오.\n"
                "    (1)\n\n"
                "    // 후위 증가 연산자 함수 전체를 작성하시오.\n"
                "    (2)\n"
                "};\n"
            )
        )
    if number == 4:
        return p("상속 관계에서 생성자 호출 순서로 옳은 것은?") + ol([
            "파생 클래스 생성자 본문 -> 기본 클래스 생성자",
            "기본 클래스 생성자 -> 파생 클래스 생성자 본문",
            "멤버 함수 호출 순서에 따라 달라진다",
            "포인터 타입에 따라 달라진다",
        ])
    if number == 5:
        return p("다음 코드의 실행 결과를 쓰시오.") + code_block(
            "class Shape {\n"
            "public:\n"
            "    void draw() { cout << \"Shape\"; }\n"
            "};\n"
            "class Circle : public Shape {\n"
            "public:\n"
            "    void draw() { cout << \"Circle\"; }\n"
            "};\n\n"
            "int main() {\n"
            "    Circle c;\n"
            "    Shape* p = &c;\n"
            "    p->draw();\n"
            "}\n"
        )
    if number == 6:
        return p("다음 코드의 실행 결과를 쓰시오.") + code_block(
            "class Base {\n"
            "public:\n"
            "    virtual ~Base() { cout << \"B\"; }\n"
            "};\n\n"
            "class Derived : public Base {\n"
            "public:\n"
            "    ~Derived() { cout << \"D\"; }\n"
            "};\n\n"
            "int main() {\n"
            "    Base* p = new Derived;\n"
            "    delete p;\n"
            "}\n"
        )
    if number == 7:
        return p("다음 코드에서 객체를 직접 생성할 수 없는 클래스를 모두 쓰시오.") + code_block(
            "class A {\n"
            "public:\n"
            "    virtual void f() = 0;\n"
            "};\n\n"
            "class B : public A {\n"
            "public:\n"
            "    void f() override { }\n"
            "};\n\n"
            "class C : public A {\n"
            "};\n"
        )
    if number == 8:
        return p("다음 함수 템플릿 호출 중 컴파일 오류 가능성이 가장 큰 것은?") + code_block(
            "template <class T>\n"
            "void myswap(T& a, T& b);\n"
        ) + ol([
            "int a=1, b=2; myswap(a, b);",
            "double a=1.1, b=2.2; myswap(a, b);",
            "int a=1; double b=2.2; myswap(a, b);",
            "char a='x', b='y'; myswap(a, b);",
        ])
    if number == 9:
        return p("다음 코드 실행 후 출력 결과를 쓰시오.") + code_block(
            "map<string, int> scores;\n"
            "scores[\"kim\"] = 90;\n\n"
            "if (scores.find(\"lee\") == scores.end()) {\n"
            "    cout << \"none \";\n"
            "}\n\n"
            "cout << scores.size() << \" \";\n"
            "cout << scores[\"lee\"] << \" \";\n"
            "cout << scores.size();\n"
        )
    if number == 10:
        return p("다음 코드에서 vector<int>의 기본 반복자(iterator)를 사용하여 모든 원소를 순서대로 출력하도록 빈칸을 채우시오.") + code_block(
            "vector<int> v = { 3, 1, 2 };\n\n"
            "for ((1) __________ it = (2) __________; it != (3) __________; ++it) {\n"
            "    cout << *it;\n"
            "}\n"
        )
    if number == 11:
        return p("다음 코드의 실행 결과를 쓰시오.") + code_block(
            "class Base {\n"
            "public:\n"
            "    Base() { cout << \"B\"; }\n"
            "    ~Base() { cout << \"b\"; }\n"
            "};\n\n"
            "class Derived : public Base {\n"
            "public:\n"
            "    Derived() { cout << \"D\"; }\n"
            "    ~Derived() { cout << \"d\"; }\n"
            "};\n\n"
            "int main() {\n"
            "    Derived x;\n"
            "}\n"
        )
    if number == 12:
        return p("다음 코드에서 주석으로 표시된 각 문장이 가능한지 독립적으로 판단하시오.") + code_block(
            "class Base {\n"
            "public:\n"
            "    int pub;\n"
            "protected:\n"
            "    int pro;\n"
            "private:\n"
            "    int pri;\n"
            "};\n\n"
            "class Derived : public Base {\n"
            "public:\n"
            "    void f() {\n"
            "        pub = 1;   // A\n"
            "        pro = 2;   // B\n"
            "        pri = 3;   // C\n"
            "    }\n"
            "};\n\n"
            "class ProtectedD : protected Base { };\n"
            "class PrivateD : private Base { };\n\n"
            "int main() {\n"
            "    Derived a;\n"
            "    ProtectedD b;\n"
            "    PrivateD c;\n\n"
            "    a.pub = 1;     // D\n"
            "    b.pub = 2;     // E\n"
            "    c.pub = 3;     // F\n"
            "}\n"
        ) + blanks(["A", "B", "C", "D", "E", "F"])
    if number == 13:
        return p("다음 코드의 실행 결과를 쓰고, 그 이유를 한 문장으로 설명하시오.") + code_block(
            "class Shape {\n"
            "public:\n"
            "    virtual void draw() { cout << \"Shape\"; }\n"
            "};\n\n"
            "class Circle : public Shape {\n"
            "public:\n"
            "    void draw() override { cout << \"Circle\"; }\n"
            "};\n\n"
            "void paint(Shape* p) {\n"
            "    p->draw();\n"
            "}\n\n"
            "int main() {\n"
            "    Circle c;\n"
            "    paint(&c);\n"
            "}\n"
        ) + blanks(["실행 결과", "이유"])
    if number == 14:
        return p("다음 코드가 위험하거나 잘못된 이유를 설명하시오.") + code_block(
            "class Point { };\n"
            "class ColorPoint : public Point {\n"
            "    string color;\n"
            "public:\n"
            "    void setColor(string color) { this->color = color; }\n"
            "};\n\n"
            "int main() {\n"
            "    Point p;\n"
            "    Point* base = &p;\n"
            "    ColorPoint* cp = (ColorPoint*)base;\n"
            "    cp->setColor(\"red\");\n"
            "}\n"
        )
    if number == 15:
        return p("다음 Student 객체들을 sort(v.begin(), v.end())로 정렬하려고 한다. 점수 오름차순으로 정렬되도록 Student 클래스 안에 operator< 함수 전체를 작성하시오.") + code_block(
            "class Student {\n"
            "public:\n"
            "    string name;\n"
            "    int score;\n\n"
            "    Student(string name, int score) : name(name), score(score) { }\n\n"
            "    // 여기에 operator< 함수 전체 작성\n"
            "};\n"
        )
    if number == 16:
        return p("다음 Point 클래스에서 두 점의 좌표가 모두 같으면 같은 객체로 판단하도록 operator==와 operator!=를 완성하시오.") + code_block(
            "class Point {\n"
            "    int x;\n"
            "    int y;\n"
            "public:\n"
            "    Point(int x = 0, int y = 0) : x(x), y(y) { }\n\n"
            "    bool operator==(const Point& p) const {\n"
            "        return (1) __________;\n"
            "    }\n\n"
            "    bool operator!=(const Point& p) const {\n"
            "        return (2) __________;\n"
            "    }\n"
            "};\n"
        )
    if number == 17:
        return p("다음 코드가 동작하도록 BaseArray를 상속받는 MyStack 클래스를 완성하시오. 스택이 꽉 찼을 때 push()는 아무 일도 하지 않고, 비었을 때 pop()은 -1을 반환한다.") + code_block(
            "class BaseArray {\n"
            "    int capacity;\n"
            "    int* mem;\n"
            "protected:\n"
            "    BaseArray(int capacity = 10) {\n"
            "        this->capacity = capacity;\n"
            "        mem = new int[capacity];\n"
            "    }\n"
            "    ~BaseArray() { delete[] mem; }\n"
            "    void put(int index, int val) { mem[index] = val; }\n"
            "    int get(int index) const { return mem[index]; }\n"
            "    int getCapacity() const { return capacity; }\n"
            "};\n\n"
            "class MyStack : public BaseArray {\n"
            "    int top;\n"
            "public:\n"
            "    MyStack(int capacity = 10) : (1) __________, (2) __________ { }\n\n"
            "    void push(int n) {\n"
            "        if (top == getCapacity()) return;\n"
            "        (3) __________;\n"
            "        top++;\n"
            "    }\n\n"
            "    int pop() {\n"
            "        if (top == 0) return -1;\n"
            "        top--;\n"
            "        return (4) __________;\n"
            "    }\n\n"
            "    int length() const {\n"
            "        return (5) __________;\n"
            "    }\n"
            "};\n"
        )
    if number == 18:
        return p("다음 조건을 만족하도록 추상 클래스와 파생 클래스를 완성하시오.") + ul([
            "Notifier는 추상 클래스이다.",
            "Notifier는 기본 클래스 포인터로 삭제해도 안전하도록 가상 소멸자를 가진다.",
            "send()는 순수 가상 함수이다.",
            "notify()는 공통 흐름을 제공하며, 내부에서 send()를 호출한다.",
            "EmailNotifier는 send()를 오버라이딩하여 Email: 메시지 형식으로 출력한다.",
        ]) + code_block(
            "class Notifier {\n"
            "protected:\n"
            "    string message;\n"
            "public:\n"
            "    Notifier(string message) : message(message) { }\n\n"
            "    // 가상 소멸자를 한 줄로 작성하시오.\n"
            "    (1) ________________________________________\n\n"
            "    // 순수 가상 함수 send()를 한 줄로 선언하시오.\n"
            "    (2) ________________________________________\n\n"
            "    void notify() {\n"
            "        cout << \"[start]\" << '\\n';\n"
            "        send();\n"
            "        cout << \"[end]\" << '\\n';\n"
            "    }\n"
            "};\n\n"
            "class EmailNotifier : public Notifier {\n"
            "public:\n"
            "    EmailNotifier(string message) : (3) __________ { }\n\n"
            "    void send() (4) __________ {\n"
            "        cout << \"Email: \" << message << '\\n';\n"
            "    }\n"
            "};\n"
        )
    if number == 19:
        return p("다음 MyStack<T> 클래스 템플릿을 완성하시오. 스택이 비었을 때 pop()은 기본값 T()를 반환한다고 가정한다.") + code_block(
            "template <class T>\n"
            "class MyStack {\n"
            "    vector<T> data;\n"
            "public:\n"
            "    void push(const T& value) {\n"
            "        (1) __________;\n"
            "    }\n\n"
            "    T pop() {\n"
            "        if ((2) __________) return (3) __________;\n"
            "        T value = (4) __________;\n"
            "        (5) __________;\n"
            "        return value;\n"
            "    }\n\n"
            "    int size() const {\n"
            "        return (6) __________;\n"
            "    }\n"
            "};\n"
        )
    if number == 20:
        return p("학생 이름과 점수를 여러 줄 입력받아 평균 이상인 학생 이름만 사전순으로 출력하려고 한다. 빈칸을 채우시오. 단, 학생 이름은 중복되지 않는다고 가정한다.") + p("입력 형식:") + code_block(
            "3\npark 60\nlee 100\nkim 80\n"
        ) + p("출력 예:") + code_block(
            "kim\nlee\n"
        ) + code_block(
            "int n;\n"
            "cin >> n;\n\n"
            "map<string, int> score;\n"
            "int sum = 0;\n\n"
            "for (int i = 0; i < n; i++) {\n"
            "    string name;\n"
            "    int s;\n"
            "    cin >> name >> s;\n"
            "    // 이름과 점수를 map에 저장\n"
            "    (1) __________;\n"
            "    // 합계 누적\n"
            "    (2) __________;\n"
            "}\n\n"
            "// 평균 계산\n"
            "double avg = (3) __________;\n\n"
            "for (map<string, int>::iterator it = (4) __________; it != (5) __________; ++it) {\n"
            "    // 평균 이상인지 검사\n"
            "    if ((6) __________) {\n"
            "        // 학생 이름 출력\n"
            "        cout << (7) __________ << '\\n';\n"
            "    }\n"
            "}\n"
        )
    if number == 21:
        return p("정수 n개를 입력받아 vector에 저장한 뒤, 오름차순으로 정렬하고 짝수만 출력하려고 한다. 빈칸을 채우시오.") + p("입력 예:") + code_block(
            "5\n3 8 1 4 7\n"
        ) + p("출력 예:") + code_block(
            "4\n8\n"
        ) + code_block(
            "int n;\n"
            "cin >> n;\n\n"
            "vector<int> v;\n\n"
            "for (int i = 0; i < n; i++) {\n"
            "    int x;\n"
            "    cin >> x;\n"
            "    // vector에 입력값 저장\n"
            "    (1) __________;\n"
            "}\n\n"
            "// 오름차순 정렬\n"
            "(2) __________;\n\n"
            "for (int i = 0; i < v.size(); i++) {\n"
            "    // 짝수인지 검사\n"
            "    if ((3) __________) {\n"
            "        // 짝수 출력\n"
            "        cout << (4) __________ << '\\n';\n"
            "    }\n"
            "}\n"
        )
    raise ValueError(number)


def page_url(question_type: str) -> str:
    return (
        "https://ecampus.kookmin.ac.kr/question/question.php"
        f"?courseid={COURSE_ID}&sesskey={SESSKEY}&qtype={question_type}"
        f"&returnurl=%2Fquestion%2Fedit.php%3Fcmid%3D{QUIZ_CMID}&category={CATEGORY}"
    )


def ensure_question_form_loaded() -> None:
    wait_until(
        lambda: safari_js(
            'JSON.stringify({name:!!document.getElementById("id_name"),qtext:!!document.getElementById("id_questiontext"),mark:!!document.getElementById("id_defaultmark"),submit:!!document.getElementById("id_submitbutton")})'
        )
        == '{"name":true,"qtext":true,"mark":true,"submit":true}'
    )


def set_editor_js(target_id_expr: str, html_var: str) -> str:
    return (
        f'var ta={target_id_expr};'
        'if(ta){'
        f'  ta.value={html_var};'
        '  var ed=ta.parentElement && ta.parentElement.querySelector(".editor_atto_content");'
        f'  if(ed){{ed.innerHTML={html_var};ed.dispatchEvent(new Event("input",{{bubbles:true}}));ed.dispatchEvent(new Event("change",{{bubbles:true}}));}}'
        '}'
    )


def submit_essay(question: dict) -> None:
    safari_open(page_url("essay"))
    wait_until(lambda: "qtype=essay" in safari_url())
    ensure_question_form_loaded()
    qtext_html = html_for_question(question["number"])
    js = (
        "(function(){"
        f"var q={json.dumps(question, ensure_ascii=False)};"
        f"var qhtml={json.dumps(qtext_html, ensure_ascii=False)};"
        'document.getElementById("id_name").value=q.name;'
        + set_editor_js('document.getElementById("id_questiontext")', "qhtml")
        + 'document.getElementById("id_defaultmark").value=q.mark;'
        'var f=document.forms[0]; var b=document.getElementById("id_submitbutton");'
        'if(f && f.requestSubmit && b){f.requestSubmit(b); return "requested";}'
        'if(f){f.submit(); return "submitted";}'
        'return "noform";'
        "})();"
    )
    safari_js(js)
    wait_until(lambda: "/question/edit.php" in safari_url(), timeout=30)
    time.sleep(0.7)


def get_existing_qbank_ids(prefix: str) -> dict[str, int]:
    merged: dict[str, int] = {}
    for qpage in range(0, 15):
        if qpage == 0:
            safari_open(f"https://ecampus.kookmin.ac.kr/question/edit.php?cmid={QUIZ_CMID}&cat={CATEGORY}&qpage=0")
        else:
            safari_open(f"https://ecampus.kookmin.ac.kr/question/edit.php?cmid={QUIZ_CMID}&cat={CATEGORY}&qpage={qpage}")
        wait_until(lambda: "/question/edit.php" in safari_url())
        time.sleep(0.6)
        raw = safari_js(
            f"""
(() => {{
  const result = {{}};
  for (const tr of document.querySelectorAll('tr')) {{
    const rowText = (tr.innerText || "").trim();
    if (!rowText.includes({json.dumps(prefix, ensure_ascii=False)})) continue;
    const nameEl = tr.querySelector(".questionname");
    const checkbox = tr.querySelector('input[id^="checkq"]');
    const name = nameEl ? (nameEl.textContent || "").trim() : "";
    const m = checkbox ? checkbox.id.match(/checkq(\\d+)/) : null;
    if (name && m) {{
      const qid = parseInt(m[1], 10);
      if (!(name in result) || qid > result[name]) {{
        result[name] = qid;
      }}
    }}
  }}
  return JSON.stringify(result);
}})();
"""
        )
        data = json.loads(raw)
        for name, qid in data.items():
            if name not in merged or qid > merged[name]:
                merged[name] = qid
    return merged


def attach_questions_to_quiz(qids: list[int]) -> None:
    safari_open(f"https://ecampus.kookmin.ac.kr/mod/quiz/edit.php?cmid={QUIZ_CMID}")
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url())
    js = (
        "(function(){"
        f"var qids={json.dumps(qids)};"
        f"var sesskey={json.dumps(SESSKEY)};"
        f"var cmid={json.dumps(QUIZ_CMID)};"
        'var form=document.createElement("form");'
        'form.method="POST";'
        'form.action="https://ecampus.kookmin.ac.kr/mod/quiz/edit.php";'
        'function add(name,value){var i=document.createElement("input");i.type="hidden";i.name=name;i.value=value;form.appendChild(i);}'
        'add("sesskey", sesskey);'
        'add("cmid", cmid);'
        'add("add", "선택한 문제를 퀴즈에 추가");'
        'qids.forEach(function(id){ add("q" + id, "1"); });'
        'document.body.appendChild(form);'
        'form.submit();'
        'return "submitted";'
        "})();"
    )
    safari_js(js)
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url(), timeout=30)


def get_attached_quiz_ids() -> dict[str, int]:
    safari_open(f"https://ecampus.kookmin.ac.kr/mod/quiz/edit.php?cmid={QUIZ_CMID}")
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url())
    wait_until(
        lambda: float(
            safari_js(
                "document.querySelectorAll('a[href*=\"/question/question.php\"][href*=\"id=\"]').length"
            )
        )
        >= len(QUESTIONS),
        timeout=30,
    )
    raw = safari_js(
        """
(() => {
  return JSON.stringify(Array.from(document.querySelectorAll('a[href*="/question/question.php"]')).map(a => ({
    href: a.href,
    text: (a.textContent || "").trim()
  })));
})();
"""
    )
    links = json.loads(raw)
    attached: dict[str, int] = {}
    question_by_number = {question["number"]: question for question in QUESTIONS}
    for link in links:
        id_match = re.search(r"[?&]id=(\d+)", link["href"])
        if not id_match:
            continue
        number_match = re.search(r"기말고사\s+(\d+)번", link["text"])
        if not number_match:
            continue
        number = int(number_match.group(1))
        question = question_by_number.get(number)
        if not question:
            continue
        qid = int(id_match.group(1))
        attached[question["name"]] = qid
    return attached


def edit_question_url(qid: int) -> str:
    return (
        "https://ecampus.kookmin.ac.kr/question/question.php"
        f"?returnurl=%2Fmod%2Fquiz%2Fedit.php%3Fcmid%3D{QUIZ_CMID}"
        f"&cmid={QUIZ_CMID}&id={qid}"
    )


def update_essay(question: dict, qid: int) -> None:
    safari_open(edit_question_url(qid))
    wait_until(lambda: f"id={qid}" in safari_url())
    ensure_question_form_loaded()
    qtext_html = html_for_question(question["number"])
    js = (
        "(function(){"
        f"var q={json.dumps(question, ensure_ascii=False)};"
        f"var qhtml={json.dumps(qtext_html, ensure_ascii=False)};"
        'document.getElementById("id_name").value=q.name;'
        + set_editor_js('document.getElementById("id_questiontext")', "qhtml")
        + 'document.getElementById("id_defaultmark").value=q.mark;'
        'var f=document.forms[0]; var b=document.getElementById("id_submitbutton") || document.getElementById("id_updatebutton");'
        'if(f && f.requestSubmit && b){f.requestSubmit(b); return "requested";}'
        'if(f){f.submit(); return "submitted";}'
        'return "noform";'
        "})();"
    )
    safari_js(js)
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url(), timeout=30)
    time.sleep(0.4)


def update_attached_questions() -> None:
    attached = get_attached_quiz_ids()
    missing = [q["name"] for q in QUESTIONS if q["name"] not in attached]
    if missing:
        raise RuntimeError(f"Could not find attached question ids: {missing}")
    for question in QUESTIONS:
        qid = attached[question["name"]]
        print(f"Updating {question['name']} -> {qid} ...", flush=True)
        update_essay(question, qid)
    result = verify_quiz()
    print(json.dumps(result, ensure_ascii=False, indent=2), flush=True)


def update_attached_question_number(number: int) -> None:
    attached = get_attached_quiz_ids()
    question = next((q for q in QUESTIONS if q["number"] == number), None)
    if not question:
        raise RuntimeError(f"Unknown question number: {number}")
    if question["name"] not in attached:
        raise RuntimeError(f"Could not find attached question id: {question['name']}")
    qid = attached[question["name"]]
    print(f"Updating {question['name']} -> {qid} ...", flush=True)
    update_essay(question, qid)


def verify_quiz() -> dict:
    safari_open(f"https://ecampus.kookmin.ac.kr/mod/quiz/edit.php?cmid={QUIZ_CMID}")
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url())
    return json.loads(
        safari_js(
            f"""
(() => {{
  const text = document.body.innerText || "";
  return JSON.stringify({{
    problemCountLine: (text.match(/출제 문제 수\\s*:?\\s*\\d+/) || [""])[0],
    totalLine: (text.match(/총점\\s*:?\\s*[0-9.]+/) || [""])[0],
    count: (text.match(/{QUESTION_PREFIX}/g) || []).length,
    hasFinalQuiz: text.includes("기말고사")
  }});
}})();
"""
        )
    )


def main() -> int:
    if "--update-number" in sys.argv:
        arg_index = sys.argv.index("--update-number") + 1
        update_attached_question_number(int(sys.argv[arg_index]))
        return 0

    if "--update-attached" in sys.argv:
        update_attached_questions()
        return 0

    existing = get_existing_qbank_ids(QUESTION_PREFIX)
    for question in QUESTIONS:
        if question["name"] in existing:
            print(f"Already exists in bank: {question['name']} -> {existing[question['name']]}", flush=True)
            continue
        print(f"Registering {question['name']} ...", flush=True)
        submit_essay(question)

    existing = get_existing_qbank_ids(QUESTION_PREFIX)
    missing = [q["name"] for q in QUESTIONS if q["name"] not in existing]
    if missing:
        raise RuntimeError(f"Missing question ids after registration: {missing}")

    attach_ids = [existing[q["name"]] for q in QUESTIONS]
    print(f"Attaching {len(attach_ids)} questions to quiz cmid={QUIZ_CMID} ...", flush=True)
    attach_questions_to_quiz(attach_ids)

    result = verify_quiz()
    print(json.dumps(result, ensure_ascii=False, indent=2), flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
