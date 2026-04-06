#!/usr/bin/env python3
import html
import json
import subprocess
import time


QUESTION_IDS = {
    1: 746653,
    2: 746654,
    3: 746656,
    4: 746657,
    5: 746658,
    6: 746659,
    7: 746660,
    8: 746661,
    9: 746662,
    10: 746663,
    11: 746664,
    12: 746665,
    13: 746666,
    14: 746667,
    15: 746668,
    16: 746669,
    17: 746670,
    18: 746671,
    19: 746672,
    20: 746673,
    21: 746674,
    22: 746675,
}


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


def safari_open(url: str) -> None:
    run_applescript(f'tell application "Safari" to set URL of current tab of front window to {json.dumps(url)}')


def safari_url() -> str:
    return run_applescript('tell application "Safari" to return URL of current tab of front window')


def wait_until(predicate, timeout: float = 20.0, interval: float = 0.5) -> None:
    deadline = time.time() + timeout
    while time.time() < deadline:
        if predicate():
            return
        time.sleep(interval)
    raise RuntimeError("Timed out waiting for Safari/eCampus state.")


def edit_url(qid: int) -> str:
    return (
        "https://ecampus.kookmin.ac.kr/question/question.php"
        "?returnurl=%2Fquestion%2Fedit.php%3Fcourseid%3D83507"
        f"&courseid=83507&id={qid}"
    )


def code_block(code: str) -> str:
    return f"<pre><code>{html.escape(code)}</code></pre>"


def p(text: str) -> str:
    return f"<p>{html.escape(text)}</p>"


def ul(items: list[str]) -> str:
    return "<ul>" + "".join(f"<li>{html.escape(item)}</li>" for item in items) + "</ul>"


def html_for_question(number: int) -> str:
    if number == 1:
        return p("class의 기본 접근 지정자는?")
    if number == 2:
        return p("다음 중 원본 값이 바뀔 수 있는 전달 방식만 올바르게 묶은 것은?")
    if number == 3:
        return p('char a[20], char b[20]의 내용이 같은지 비교할 때 가장 적절한 것은?')
    if number == 4:
        return p("함수 오버로딩을 구분하는 기준은?")
    if number == 5:
        return p("static 멤버 함수에서 non-static 멤버 변수에 직접 접근할 수 없는 가장 직접적인 이유는?")
    if number == 6:
        return (
            p("다음 코드의 실행 결과를 쓰시오.")
            + code_block(
                'class A {\n'
                'public:\n'
                '    A() { cout << "A"; }\n'
                '    ~A() { cout << "a"; }\n'
                '};\n\n'
                'int main() {\n'
                '    A x;\n'
                '    {\n'
                '        A y;\n'
                '    }\n'
                '    A z;\n'
                '}'
            )
        )
    if number == 7:
        return (
            p("다음 코드를 보고 각 배열 선언이 가능한지 판단하고, 이유를 쓰시오. 답은 짧게 쓰시오.")
            + code_block(
                'class A {\n'
                'public:\n'
                '    int x;\n'
                '};\n\n'
                'class B {\n'
                'public:\n'
                '    B(int n) { }\n'
                '};\n\n'
                'A arr1[3];\n'
                'B arr2[3];'
            )
            + ul(["arr1:", "arr1 이유:", "arr2:", "arr2 이유:"])
        )
    if number == 8:
        return (
            p('문자열 "250"을 정수 250으로 바꾸어 n에 저장하려고 한다. 빈칸에 들어갈 표현을 쓰시오.')
            + code_block('string s = "250";\nint n = (1) __________;')
        )
    if number == 9:
        return p("두 정수의 값을 참조로 바꾸는 함수 swapByRef(int& a, int& b)의 핵심 코드 세 줄을 쓰시오.") + ul(["(1)", "(2)", "(3)"])
    if number == 10:
        return (
            p("배열의 index번째 원소를 참조로 돌려주는 함수이다. 빈칸에 들어갈 표현을 쓰시오.")
            + code_block("int& arrElem(int a[], int index) {\n    return (1) __________;\n}")
        )
    if number == 11:
        return (
            p("count는 Counter 클래스의 멤버 변수이며, 생성된 객체 수를 저장한다. 객체가 생성될 때 count를 1 증가시키고, 소멸될 때 1 감소하도록 Counter 클래스를 완성하시오. 또한 현재 객체 수를 반환하는 getCount()도 알맞게 작성하시오. 아래 코드는 컴파일과 실행이 모두 가능해야 한다.")
            + code_block(
                "class Counter {\n"
                "private:\n"
                "    (1) ______________________\n"
                "public:\n"
                "    Counter() { (2) ______________________; }\n"
                "    ~Counter() { (3) ______________________; }\n"
                "    (4) ______________________\n"
                "};\n\n"
                "(5) ______________________"
            )
        )
    if number == 12:
        return (
            p("다음 Circle 클래스를 사용할 때, main()을 완성하시오.")
            + code_block(
                "class Circle {\n"
                "public:\n"
                "    Circle(int r);\n"
                "    int getRadius() const;\n"
                "};\n\n"
                "int main() {\n"
                "    // 반지름 10인 Circle 객체 p를 동적으로 생성\n"
                "    (1) ______________________\n\n"
                "    // 객체의 반지름을 출력\n"
                "    (2) ______________________\n\n"
                "    // 동적으로 생성한 객체의 메모리를 해제\n"
                "    (3) ______________________\n"
                "}"
            )
        )
    if number == 13:
        return (
            p("다음 main()이 정상 동작하도록 Circle 클래스를 완성하시오.")
            + code_block(
                "class Circle {\n"
                "private:\n"
                "    int radius;\n"
                "public:\n"
                "    Circle(int radius = 1) : radius(radius) { }\n"
                "    int getRadius() const { return radius; }\n\n"
                "    Circle& setRadius(int radius) {\n"
                "        (1) ______________________\n"
                "        (2) ______________________\n"
                "    }\n"
                "};\n\n"
                "int main() {\n"
                "    Circle c;\n"
                "    c.setRadius(10).setRadius(20);\n"
                "    cout << c.getRadius() << '\\n';\n"
                "}"
            )
        )
    if number == 14:
        return (
            p("다음 생성자가 멤버 변수에 값을 제대로 저장하도록, 생성자 본문 한 줄을 올바르게 쓰시오.")
            + code_block(
                "class Circle {\n"
                "private:\n"
                "    int radius;\n"
                "public:\n"
                "    Circle(int radius) {\n"
                "        (1) ______________________\n"
                "    }\n"
                "};"
            )
        )
    if number == 15:
        return (
            p("다음 코드에서 이름이 빈 줄로 들어갈 수 있다.")
            + code_block("int age;\nstring name;\n\ncin >> age;\ngetline(cin, name);")
            + ul(["원인:", "수정 코드 1줄:"])
        )
    if number == 16:
        return (
            p("다음 코드의 문제를 2가지 쓰고, 한 가지 가능한 수정안을 쓰시오.")
            + code_block(
                "int* p = new int[3];\n"
                "for (int i = 0; i < 3; i++) {\n"
                "    p[i] = i * 10;\n"
                "}\n"
                "delete p;\n"
                "cout << p[1] << '\\n';"
            )
            + ul(["문제 1:", "문제 2:", "수정안:"])
        )
    if number == 17:
        return (
            p("다음 코드의 각 호출에 대해 정상 또는 오류만 쓰시오.")
            + code_block(
                "int sum(int a) { return a; }\n"
                "int sum(int a, int b = 0) { return a + b; }\n\n"
                "int main() {\n"
                "    sum(3);\n"
                "    sum(3, 4);\n"
                "    sum('a');\n"
                "}"
            )
            + ul(["sum(3):", "sum(3, 4):", "sum('a'):"])
        )
    if number == 18:
        return (
            p("다음 코드의 오류를 설명하고, 한 가지 수정 방법을 쓰시오.")
            + code_block(
                "class Person {\n"
                "private:\n"
                "    int money;\n"
                "public:\n"
                "    static int getMoney() { return money; }\n"
                "};"
            )
            + ul(["오류 원인:", "수정 방법 1가지:"])
        )
    if number == 19:
        return (
            p("다음 코드의 출력 결과를 쓰시오.")
            + code_block(
                "class Sample {\n"
                "public:\n"
                "    Sample() { cout << \"A\"; }\n"
                "    Sample(const Sample& s) { cout << \"B\"; }\n"
                "};\n\n"
                "void func(Sample x) { }\n\n"
                "int main() {\n"
                "    Sample a;\n"
                "    Sample b = a;\n"
                "    func(a);\n"
                "}"
            )
        )
    if number == 20:
        return (
            p("다음 함수는 문제가 있다.")
            + code_block("int& maxValue() {\n    int x = 10;\n    return x;\n}")
            + ul(["문제점:", "수정 방법 1가지:"])
        )
    if number == 21:
        return (
            p("다음 코드에서 잘못된 부분을 찾고, 왜 문제가 되는지 설명한 뒤, 핵심 수정 코드를 쓰시오.")
            + code_block(
                "class Person {\n"
                "private:\n"
                "    char* name;\n"
                "public:\n"
                "    Person(const char* s) {\n"
                "        name = new char[strlen(s) + 1];\n"
                "        strcpy(name, s);\n"
                "    }\n\n"
                "    Person(const Person& p) {\n"
                "        name = p.name;\n"
                "    }\n\n"
                "    ~Person() { delete[] name; }\n"
                "};"
            )
            + ul(["잘못된 줄:", "이유:", "핵심 수정 코드:"])
        )
    if number == 22:
        return (
            p("다음 main()에서 string s = \"apple:banana\"; 를 사용하여 ':' 앞 문자열과 뒤 문자열을 각각 한 줄씩 출력하도록 코드를 완성하시오.")
            + p("사용 가능 함수: find, substr")
            + code_block(
                'int main() {\n'
                '    string s = "apple:banana";\n'
                '    (1) ______________________\n'
                '    (2) ______________________\n'
                '    (3) ______________________\n'
                '}'
            )
        )
    raise ValueError(number)


def wait_for_edit_page(qid: int) -> None:
    wait_until(lambda: f"id={qid}" in safari_url())
    wait_until(lambda: safari_js('!!document.getElementById("id_questiontext") && !!document.getElementById("id_submitbutton")') == "true")


def update_question(number: int) -> None:
    qid = QUESTION_IDS[number]
    safari_open(edit_url(qid))
    wait_for_edit_page(qid)
    html_text = html_for_question(number)
    js = (
        "(function(){"
        f"var html={json.dumps(html_text, ensure_ascii=False)};"
        'var ta=document.getElementById("id_questiontext");'
        'ta.value=html;'
        'var ed=ta.parentElement && ta.parentElement.querySelector(".editor_atto_content");'
        'if(ed){ed.innerHTML=html; ed.dispatchEvent(new Event("input",{bubbles:true})); ed.dispatchEvent(new Event("change",{bubbles:true}));}'
        'document.getElementById("id_submitbutton").click();'
        'return "submitted";'
        "})();"
    )
    safari_js(js)
    wait_until(lambda: "/question/edit.php" in safari_url())


def main() -> int:
    import sys
    numbers = list(range(1, 23))
    if len(sys.argv) > 1:
        numbers = [int(arg) for arg in sys.argv[1:]]
    for number in numbers:
        print(f"Formatting question {number}...", flush=True)
        update_question(number)
        time.sleep(0.5)
    print("All questions formatted.", flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
