#include <iostream>
#include <string>
using namespace std;

/*
[Lab13] 사전식 비교 + 문자열 회전
------------------------------------------------------------
문제 설명
1) 단어 n개를 입력받아 사전식으로 가장 작은 단어와 가장 큰 단어를 출력한다.
2) 문자열 s와 정수 k를 입력받아, s를 왼쪽으로 k칸 회전한 결과를 출력한다.
   (k는 문자열 길이로 나눈 나머지만큼 회전하면 된다)
------------------------------------------------------------
핵심
1) string 비교(<, >)는 사전식(lexicographical) 기준이다.
2) 여러 문자열 중 min/max를 찾는 루프 패턴 익히기
3) substr로 문자열 일부를 잘라 회전을 구현한다.
------------------------------------------------------------
새로 나오는 함수 요약
- size(): 문자열 길이 반환
- substr(pos): pos부터 끝까지 반환
- substr(pos, len): pos부터 len만큼 반환
------------------------------------------------------------
*/

int main() {
    // (1) 사전식 비교
    int n;
    cout << "How many words? ";
    cin >> n;
    if (n <= 0) return 0;

    string first;
    cin >> first;
    string minWord = first;
    string maxWord = first;

    for (int i = 1; i < n; i++) {
        string w;
        cin >> w;
        // operator<, operator> : 사전식(사전 순서) 비교
        if (w < minWord) minWord = w; // 사전식 최소
        if (w > maxWord) maxWord = w; // 사전식 최대
    }

    cout << "min = " << minWord << "\n";
    cout << "max = " << maxWord << "\n\n";

    // (2) 문자열 회전(왼쪽 회전)
    string s;
    int k;
    cout << "String to rotate and k: ";
    cin >> s >> k;

    if (!s.empty()) {
        // size(): 문자열 길이 (size_t), k를 안전하게 줄이기 위해 변환
        k %= static_cast<int>(s.size());
        // substr(pos): pos부터 끝까지
        // substr(pos, len): pos부터 len만큼
        string rotated = s.substr(k) + s.substr(0, k);
        cout << "rotated = " << rotated << "\n";
    }

    return 0;
}
