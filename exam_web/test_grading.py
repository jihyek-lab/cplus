#!/usr/bin/env python3
from __future__ import annotations

import importlib.util
import unittest
from pathlib import Path


SERVER_PATH = Path(__file__).resolve().parent / "server.py"
spec = importlib.util.spec_from_file_location("exam_server", SERVER_PATH)
server = importlib.util.module_from_spec(spec)
assert spec.loader is not None
spec.loader.exec_module(server)


def full_score_answers() -> dict[str, str]:
    return {
        "student_id": "20260001",
        "student_name": "Tester",
        "q1": "3",
        "q2": "3",
        "q3": "2",
        "q4": "3",
        "q5": "2",
        "q6": "AAaAaa",
        "q7_arr1_decision": "가능",
        "q7_arr1_reason": "생성자를 따로 정의하지 않아 기본 생성이 가능하다.",
        "q7_arr2_decision": "불가",
        "q7_arr2_reason": "B(int)만 있어서 기본 생성자가 없다.",
        "q8_1": "stoi(s)",
        "q9_1": "int temp = a;",
        "q9_2": "a = b;",
        "q9_3": "b = temp;",
        "q10_1": "a[index]",
        "q11_1": "static int count;",
        "q11_2": "++count",
        "q11_3": "--count",
        "q11_4": "static int getCount() { return count; }",
        "q11_5": "int Counter::count = 0;",
        "q12_1": "Circle* p = new Circle(10);",
        "q12_2": "cout << p->getRadius() << '\\n';",
        "q12_3": "delete p;",
        "q13_1": "this->radius = radius;",
        "q13_2": "return *this;",
        "q14_1": "this->radius = radius;",
        "q15_cause": "cin >> age 뒤 개행 문자가 버퍼에 남아서 getline이 그 개행을 읽는다.",
        "q15_fix": "cin.ignore();",
        "q16_problem1": "new int[3]인데 delete p;를 써서 배열 해제가 잘못되었다.",
        "q16_problem2": "메모리를 해제한 후 p[1]에 접근한다.",
        "q16_fix": "cout << p[1] << '\\n';\ndelete[] p;",
        "q17_a": "오류",
        "q17_b": "정상",
        "q17_c": "정상",
        "q18_cause": "static 함수에는 this가 없고 money는 non-static 멤버라 직접 접근할 수 없다.",
        "q18_fix": "static을 제거한다.",
        "q19": "ABB",
        "q20_problem": "지역 변수 x는 함수 종료와 함께 사라지는데 그 참조를 반환해서 위험하다.",
        "q20_fix": "반환 타입을 int로 바꾸기",
        "q21_wrong": "name = p.name;",
        "q21_reason": "주소만 복사하는 얕은 복사라서 같은 메모리를 가리키고 이중 해제 위험이 있다.",
        "q21_fix": "name = new char[strlen(p.name) + 1];\nstrcpy(name, p.name);",
        "q22_1": "int pos = s.find(':');",
        "q22_2": "cout << s.substr(0, pos) << '\\n';",
        "q22_3": "cout << s.substr(pos + 1) << '\\n';",
    }


class GradingTests(unittest.TestCase):
    def test_perfect_submission_scores_100(self) -> None:
        result = server.grade_submission(full_score_answers())
        self.assertEqual(result["total_score"], 100)
        self.assertEqual(result["max_score"], 100)

    def test_allowed_variants_are_accepted(self) -> None:
        answers = full_score_answers()
        answers["q6"] = "A A a A a a"
        answers["q11_2"] = "count++"
        answers["q11_3"] = "count--"
        answers["q12_2"] = "cout << p->getRadius() << endl;"
        answers["q15_fix"] = "cin.ignore(1, '\\n');"
        answers["q18_fix"] = "money를 static으로 바꾸기"
        answers["q20_fix"] = "static int x; 로 바꾸기"
        result = server.grade_submission(answers)
        self.assertEqual(result["total_score"], 100)

    def test_swap_is_all_or_nothing(self) -> None:
        answers = full_score_answers()
        answers["q9_3"] = "a = temp;"
        result = server.grade_submission(answers)
        q9 = next(item for item in result["questions"] if item["question_id"] == 9)
        self.assertEqual(q9["score"], 0)

    def test_q17_partial_scoring(self) -> None:
        answers = full_score_answers()
        answers["q17_a"] = "정상"
        result = server.grade_submission(answers)
        q17 = next(item for item in result["questions"] if item["question_id"] == 17)
        self.assertEqual(q17["score"], 2)

    def test_q21_partial_scoring(self) -> None:
        answers = full_score_answers()
        answers["q21_fix"] = ""
        result = server.grade_submission(answers)
        q21 = next(item for item in result["questions"] if item["question_id"] == 21)
        self.assertEqual(q21["score"], 4)

    def test_q22_line_by_line_scoring(self) -> None:
        answers = full_score_answers()
        answers["q22_3"] = "cout << s.substr(pos) << '\\n';"
        result = server.grade_submission(answers)
        q22 = next(item for item in result["questions"] if item["question_id"] == 22)
        self.assertEqual(q22["score"], 4)


if __name__ == "__main__":
    unittest.main()
