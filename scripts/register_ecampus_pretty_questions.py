#!/usr/bin/env python3
import json
import subprocess
import sys
import time

from format_ecampus_questions import html_for_question


COURSE_ID = "83507"
SESSKEY = "ih3x3eXl1h"
CATEGORY = "117862"


QUESTIONS = [
    {
        "number": 1,
        "qtype": "multichoice",
        "name": "중간고사 서식개선 01번",
        "mark": "2",
        "answers": [
            {"text": "public", "fraction": "0.0"},
            {"text": "protected", "fraction": "0.0"},
            {"text": "private", "fraction": "1.0"},
            {"text": "static", "fraction": "0.0"},
        ],
    },
    {
        "number": 2,
        "qtype": "multichoice",
        "name": "중간고사 서식개선 02번",
        "mark": "2",
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
        "name": "중간고사 서식개선 03번",
        "mark": "2",
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
        "name": "중간고사 서식개선 04번",
        "mark": "2",
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
        "name": "중간고사 서식개선 05번",
        "mark": "2",
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
        "name": "중간고사 서식개선 06번",
        "mark": "4",
        "answers": [{"text": "AAaAaa", "fraction": "1.0"}],
    },
    {"number": 7, "qtype": "essay", "name": "중간고사 서식개선 07번", "mark": "4"},
    {
        "number": 8,
        "qtype": "shortanswer",
        "name": "중간고사 서식개선 08번",
        "mark": "4",
        "answers": [{"text": "stoi(s)", "fraction": "1.0"}],
    },
    {"number": 9, "qtype": "essay", "name": "중간고사 서식개선 09번", "mark": "4"},
    {
        "number": 10,
        "qtype": "shortanswer",
        "name": "중간고사 서식개선 10번",
        "mark": "4",
        "answers": [{"text": "a[index]", "fraction": "1.0"}],
    },
    {"number": 11, "qtype": "essay", "name": "중간고사 서식개선 11번", "mark": "10"},
    {"number": 12, "qtype": "essay", "name": "중간고사 서식개선 12번", "mark": "6"},
    {"number": 13, "qtype": "essay", "name": "중간고사 서식개선 13번", "mark": "6"},
    {
        "number": 14,
        "qtype": "shortanswer",
        "name": "중간고사 서식개선 14번",
        "mark": "3",
        "answers": [
            {"text": "this->radius = radius;", "fraction": "1.0"},
            {"text": "this->radius=radius;", "fraction": "1.0"},
        ],
    },
    {"number": 15, "qtype": "essay", "name": "중간고사 서식개선 15번", "mark": "5"},
    {"number": 16, "qtype": "essay", "name": "중간고사 서식개선 16번", "mark": "6"},
    {"number": 17, "qtype": "essay", "name": "중간고사 서식개선 17번", "mark": "6"},
    {"number": 18, "qtype": "essay", "name": "중간고사 서식개선 18번", "mark": "4"},
    {
        "number": 19,
        "qtype": "shortanswer",
        "name": "중간고사 서식개선 19번",
        "mark": "4",
        "answers": [{"text": "ABB", "fraction": "1.0"}],
    },
    {"number": 20, "qtype": "essay", "name": "중간고사 서식개선 20번", "mark": "8"},
    {"number": 21, "qtype": "essay", "name": "중간고사 서식개선 21번", "mark": "6"},
    {"number": 22, "qtype": "essay", "name": "중간고사 서식개선 22번", "mark": "6"},
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


def ensure_form_loaded(question_type: str) -> None:
    wait_until(lambda: f"qtype={question_type}" in safari_url())
    wait_until(lambda: safari_js('!!document.getElementById("id_name") && !!document.getElementById("id_submitbutton")') == "true")


def set_editor_js(target_id_expr: str, html_var: str) -> str:
    return (
        f'var ta={target_id_expr};'
        'if(ta){'
        f'  ta.value={html_var};'
        '  var ed=ta.parentElement && ta.parentElement.querySelector(".editor_atto_content");'
        f'  if(ed){{ed.innerHTML={html_var};ed.dispatchEvent(new Event("input",{{bubbles:true}}));ed.dispatchEvent(new Event("change",{{bubbles:true}}));}}'
        '}'
    )


def submit_multichoice(question: dict) -> None:
    safari_open(page_url("multichoice"))
    ensure_form_loaded("multichoice")
    qtext_html = html_for_question(question["number"])
    js = (
        "(function(){"
        f"var q={json.dumps(question, ensure_ascii=False)};"
        f"var qhtml={json.dumps(qtext_html, ensure_ascii=False)};"
        'document.getElementById("id_name").value=q.name;'
        + set_editor_js('document.getElementById("id_questiontext")', "qhtml")
        + 'document.getElementById("id_defaultmark").value=q.mark;'
        'q.answers.forEach(function(ans,i){'
        'var answer=document.getElementsByName("answer["+i+"][text]")[0];'
        'var fraction=document.getElementsByName("fraction["+i+"]")[0];'
        'if(answer){answer.value=ans.text; var ed=answer.parentElement && answer.parentElement.querySelector(".editor_atto_content"); if(ed){ed.textContent=ans.text;}}'
        'if(fraction) fraction.value=ans.fraction;'
        "});"
        'var f=document.forms[0]; var b=document.getElementById("id_submitbutton");'
        'if(f && f.requestSubmit && b){f.requestSubmit(b); return "requested";}'
        'if(f){f.submit(); return "submitted";}'
        'return "noform";'
        "})();"
    )
    safari_js(js)


def submit_shortanswer(question: dict) -> None:
    safari_open(page_url("shortanswer"))
    ensure_form_loaded("shortanswer")
    qtext_html = html_for_question(question["number"])
    js = (
        "(function(){"
        f"var q={json.dumps(question, ensure_ascii=False)};"
        f"var qhtml={json.dumps(qtext_html, ensure_ascii=False)};"
        'document.getElementById("id_name").value=q.name;'
        + set_editor_js('document.getElementById("id_questiontext")', "qhtml")
        + 'document.getElementById("id_defaultmark").value=q.mark;'
        'q.answers.forEach(function(ans,i){'
        'var answer=document.getElementsByName("answer["+i+"]")[0];'
        'var fraction=document.getElementsByName("fraction["+i+"]")[0];'
        'if(answer) answer.value=ans.text;'
        'if(fraction) fraction.value=ans.fraction;'
        "});"
        'var f=document.forms[0]; var b=document.getElementById("id_submitbutton");'
        'if(f && f.requestSubmit && b){f.requestSubmit(b); return "requested";}'
        'if(f){f.submit(); return "submitted";}'
        'return "noform";'
        "})();"
    )
    safari_js(js)


def submit_essay(question: dict) -> None:
    safari_open(page_url("essay"))
    ensure_form_loaded("essay")
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


def wait_for_saved(name: str) -> None:
    del name
    wait_until(lambda: "/question/edit.php" in safari_url())


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
    numbers = [q["number"] for q in QUESTIONS]
    if len(sys.argv) > 1:
        numbers = [int(arg) for arg in sys.argv[1:]]
    selected = [q for q in QUESTIONS if q["number"] in numbers]
    for question in selected:
        print(f"Registering {question['name']} ({question['qtype']})...", flush=True)
        submit_question(question)
        print(f"Saved {question['name']}", flush=True)
        time.sleep(0.7)
    print("All requested pretty questions saved.", flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
