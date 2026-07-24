#!/usr/bin/env python3
import html
import json
import re
import subprocess
import sys
import time


COURSE_ID = "83169"
SESSKEY = "LVQpVWSRfu"
QUIZ_CMID = "1893222"
CATEGORY = "118165,2202824"
SOURCE_MD = "/Users/narim1pro/Documents/workspace/c/midterm_implementation_5_problems_student.md"
QUESTION_PREFIX = "C 중간고사 구현형"


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


def inline_markdown(text: str) -> str:
    escaped = html.escape(text)
    return re.sub(r"`([^`]+)`", r"<code>\1</code>", escaped)


def paragraph_html(lines: list[str]) -> str:
    text = " ".join(line.strip() for line in lines).strip()
    return f"<p>{inline_markdown(text)}</p>" if text else ""


def markdown_to_html(markdown: str) -> str:
    lines = markdown.strip().splitlines()
    chunks: list[str] = []
    para: list[str] = []
    list_items: list[str] = []
    in_code = False
    code_lang = ""
    code_lines: list[str] = []

    def flush_para() -> None:
        nonlocal para
        if para:
            chunks.append(paragraph_html(para))
            para = []

    def flush_list() -> None:
        nonlocal list_items
        if list_items:
            chunks.append("<ul>" + "".join(f"<li>{inline_markdown(item)}</li>" for item in list_items) + "</ul>")
            list_items = []

    for line in lines:
        if line.startswith("```"):
            if in_code:
                chunks.append(
                    f'<pre><code class="language-{html.escape(code_lang)}">'
                    + html.escape("\n".join(code_lines))
                    + "</code></pre>"
                )
                in_code = False
                code_lang = ""
                code_lines = []
            else:
                flush_para()
                flush_list()
                in_code = True
                code_lang = line[3:].strip()
            continue

        if in_code:
            code_lines.append(line)
            continue

        stripped = line.strip()

        if not stripped:
            flush_para()
            flush_list()
            continue

        if stripped == "---":
            flush_para()
            flush_list()
            continue

        if line.startswith("### "):
            flush_para()
            flush_list()
            chunks.append(f"<h4>{inline_markdown(line[4:].strip())}</h4>")
            continue

        if line.startswith("## "):
            flush_para()
            flush_list()
            chunks.append(f"<h3>{inline_markdown(line[3:].strip())}</h3>")
            continue

        if stripped.startswith("- "):
            flush_para()
            list_items.append(stripped[2:].strip())
            continue

        flush_list()
        para.append(line)

    flush_para()
    flush_list()
    if in_code:
        chunks.append("<pre><code>" + html.escape("\n".join(code_lines)) + "</code></pre>")
    return "\n".join(chunks)


def strip_grading_rubric(markdown: str) -> str:
    return re.sub(r"\n채점 기준:\n.*\Z", "", markdown.strip(), flags=re.DOTALL)


def parse_questions() -> list[dict]:
    md = open(SOURCE_MD, encoding="utf-8").read()
    pattern = re.compile(r"^##\s+(\d+)번\.\s+(.+?)\s+\((\d+)점\)\s*$", re.MULTILINE)
    matches = list(pattern.finditer(md))
    questions: list[dict] = []
    for index, match in enumerate(matches):
        number = int(match.group(1))
        title = match.group(2).strip()
        mark = match.group(3)
        start = match.start()
        end = matches[index + 1].start() if index + 1 < len(matches) else len(md)
        block = strip_grading_rubric(md[start:end])
        questions.append(
            {
                "number": number,
                "name": f"{QUESTION_PREFIX} {number:02d}번",
                "title": title,
                "mark": mark,
                "html": markdown_to_html(block),
            }
        )
    if len(questions) != 5:
        raise RuntimeError(f"Expected 5 questions from {SOURCE_MD}, found {len(questions)}")
    return questions


QUESTIONS = parse_questions()


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
        f"var ta={target_id_expr};"
        "if(ta){"
        f"  ta.value={html_var};"
        '  var ed=ta.parentElement && ta.parentElement.querySelector(".editor_atto_content");'
        f'  if(ed){{ed.innerHTML={html_var};ed.dispatchEvent(new Event("input",{{bubbles:true}}));ed.dispatchEvent(new Event("change",{{bubbles:true}}));}}'
        "}"
    )


def submit_essay(question: dict) -> None:
    safari_open(page_url("essay"))
    wait_until(lambda: "qtype=essay" in safari_url())
    ensure_question_form_loaded()
    js = (
        "(function(){"
        f"var q={json.dumps(question, ensure_ascii=False)};"
        "document.getElementById('id_name').value=q.name;"
        + set_editor_js("document.getElementById('id_questiontext')", "q.html")
        + "document.getElementById('id_defaultmark').value=q.mark;"
        "var f=document.forms[0]; var b=document.getElementById('id_submitbutton');"
        "if(f && f.requestSubmit && b){f.requestSubmit(b); return 'requested';}"
        "if(f){f.submit(); return 'submitted';}"
        "return 'noform';"
        "})();"
    )
    safari_js(js)
    wait_until(lambda: "/question/edit.php" in safari_url(), timeout=30)
    time.sleep(0.7)


def get_existing_qbank_ids(prefix: str) -> dict[str, int]:
    merged: dict[str, int] = {}
    for qpage in range(0, 8):
        safari_open(
            f"https://ecampus.kookmin.ac.kr/question/edit.php?cmid={QUIZ_CMID}&cat={CATEGORY}&qpage={qpage}"
        )
        wait_until(lambda: "/question/edit.php" in safari_url())
        time.sleep(0.5)
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
      if (!(name in result) || qid > result[name]) result[name] = qid;
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


def get_existing_quiz_names() -> set[str]:
    safari_open(f"https://ecampus.kookmin.ac.kr/mod/quiz/edit.php?cmid={QUIZ_CMID}")
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url())
    raw = safari_js(
        f"""
(() => {{
  const prefix = {json.dumps(QUESTION_PREFIX, ensure_ascii=False)};
  return JSON.stringify([...document.querySelectorAll('a,span,div')]
    .map(el => (el.textContent || '').trim())
    .filter(text => text.startsWith(prefix)));
}})();
"""
    )
    return set(json.loads(raw))


def attach_questions_to_quiz(qids: list[int]) -> None:
    safari_open(f"https://ecampus.kookmin.ac.kr/mod/quiz/edit.php?cmid={QUIZ_CMID}")
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url())
    js = (
        "(function(){"
        f"var qids={json.dumps(qids)};"
        f"var sesskey={json.dumps(SESSKEY)};"
        f"var cmid={json.dumps(QUIZ_CMID)};"
        "var form=document.createElement('form');"
        "form.method='POST';"
        "form.action='https://ecampus.kookmin.ac.kr/mod/quiz/edit.php';"
        "function add(name,value){var i=document.createElement('input');i.type='hidden';i.name=name;i.value=value;form.appendChild(i);}"
        "add('sesskey', sesskey);"
        "add('cmid', cmid);"
        "add('add', '선택한 문제를 퀴즈에 추가');"
        "qids.forEach(function(id){ add('q' + id, '1'); });"
        "document.body.appendChild(form);"
        "form.submit();"
        "return 'submitted';"
        "})();"
    )
    safari_js(js)
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url(), timeout=30)


def get_attached_quiz_ids() -> dict[str, int]:
    safari_open(f"https://ecampus.kookmin.ac.kr/mod/quiz/edit.php?cmid={QUIZ_CMID}")
    wait_until(lambda: "/mod/quiz/edit.php" in safari_url())
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
    question_by_number = {question["number"]: question for question in QUESTIONS}
    attached: dict[str, int] = {}
    for link in links:
        id_match = re.search(r"[?&]id=(\d+)", link["href"])
        number_match = re.search(r"구현형\s+(\d+)번", link["text"])
        if not id_match or not number_match:
            continue
        question = question_by_number.get(int(number_match.group(1)))
        if question:
            attached[question["name"]] = int(id_match.group(1))
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
    js = (
        "(function(){"
        f"var q={json.dumps(question, ensure_ascii=False)};"
        "document.getElementById('id_name').value=q.name;"
        + set_editor_js("document.getElementById('id_questiontext')", "q.html")
        + "document.getElementById('id_defaultmark').value=q.mark;"
        "var f=document.forms[0]; var b=document.getElementById('id_submitbutton') || document.getElementById('id_updatebutton');"
        "if(f && f.requestSubmit && b){f.requestSubmit(b); return 'requested';}"
        "if(f){f.submit(); return 'submitted';}"
        "return 'noform';"
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
    print(json.dumps(verify_quiz(), ensure_ascii=False, indent=2), flush=True)


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
    hasRubric: text.includes("채점 기준"),
    hasCurrentQuiz: text.includes("프로그래밍 중간고사")
  }});
}})();
"""
        )
    )


def main() -> int:
    if "--dry-run" in sys.argv:
        print(json.dumps(QUESTIONS, ensure_ascii=False, indent=2))
        return 0

    if "--update-attached" in sys.argv:
        update_attached_questions()
        return 0

    existing = get_existing_qbank_ids(QUESTION_PREFIX)
    for question in QUESTIONS:
        if question["name"] in existing:
            print(f"Already exists in bank: {question['name']} -> {existing[question['name']]}", flush=True)
            continue
        print(f"Registering {question['name']} ({question['mark']}점) ...", flush=True)
        submit_essay(question)

    existing = get_existing_qbank_ids(QUESTION_PREFIX)
    missing = [q["name"] for q in QUESTIONS if q["name"] not in existing]
    if missing:
        raise RuntimeError(f"Missing question ids after registration: {missing}")

    quiz_names = get_existing_quiz_names()
    attach_ids = [existing[q["name"]] for q in QUESTIONS if q["name"] not in quiz_names]
    if attach_ids:
        print(f"Attaching {len(attach_ids)} questions to quiz cmid={QUIZ_CMID}: {attach_ids}", flush=True)
        attach_questions_to_quiz(attach_ids)
    else:
        print("All questions are already attached to the quiz.", flush=True)

    print(json.dumps(verify_quiz(), ensure_ascii=False, indent=2), flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
