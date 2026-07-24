/*
 * 실습용 starter code
 * 문제: 연산자 중복과 프렌드 함수
 *
 * 학생용 가이드:
 * - README.md 에 문제 설명과 체크리스트가 정리되어 있습니다.
 * - 아래 코드의 TODO 위치를 중심으로 구현을 진행하세요.
 * - 필요하면 main 함수는 그대로 두고, 클래스/함수 구현만 채워 넣는 방식으로 연습해 보세요.
 */

#include <iostream>
using namespace std;
class matrix {
    int e[2][2];
public:
    matrix(int e11 = 0, int e12 = 0, int e21 = 0, int e22 = 0);
    void show() {
        cout << "matrix [[";
        cout << e[0][0] << ", " << e[0][1] << "], [";
        cout << e[1][0] << ", " << e[1][1] << "]]" << endl;
    }
    // TODO 1:
// 아래 연산자들을 구현하세요.
// +, += 는 멤버 함수로 작성하고, -, -= 는 프렌드 함수로 작성합니다.
// == 는 모든 원소가 같은지 비교하고, >> / << 는 matrix 와 배열 사이의 복사를 담당합니다.
    matrix operator+(matrix &m);
    matrix &operator+=(matrix &m);
    friend matrix operator-(matrix &lhs, matrix &rhs);
    friend matrix &operator-=(matrix &lhs, matrix &rhs);
    bool operator==(matrix &m);
    matrix &operator>>(int m[][2]);
    friend matrix &operator<<(matrix &lhs, int rhs[][2]);
};
// TODO 2:
// 생성자와 연산자 함수들의 실제 구현을 이 아래에 작성하세요.
// 구현 순서는 생성자 -> += / -= -> + / - -> == -> >> / << 로 가면 테스트하기 편합니다.
// 2 X 2 배열 입력
void input2x2(int m[][2]) {
    for (int row = 0; row < 2; row++)
    for (int col = 0; col < 2; col++)
    cin >> m[row][col];
}
// 2 X 2 배열 출력
void output2x2(int m[][2]) {
    cout << "array [[";
    cout << m[0][0] << ", " << m[0][1] << "], [";
    cout << m[1][0] << ", " << m[1][1] << "]]" << endl;
}
int main() {
    int e11, e12, e21, e22;
    cin >> e11 >> e12 >> e21 >> e22; // 행렬의 네 원소를 입력
    matrix m(e11, e12, e21, e22); // 생성자를 통한 행렬 생성
    m.show();
    int x[2][2], y[2][2], z[2][2], w[2][2];
    input2x2(x); // x 배열 입력
    input2x2(y); // y 배열 입력
    input2x2(z); // z 배열 입력
    input2x2(w); // w 배열 입력
    matrix a, b, c, d;
    a << x; // x 의 각 원소를 a 에 복사
    b << y; // y 의 각 원소를 b 에 복사
    c << z; // z 의 각 원소를 c 에 복사
    d << w; // w 의 각 원소를 d 에 복사
    a += b;
    c -= d;
    matrix add = a + d;
    matrix sub = b - c;
    if (add == c)
    cout << "a 행렬과 d 행렬을 더한 값은 c 행렬과 같습니다." << endl;
    if (sub == d)
    cout << "b 행렬과 c 행렬을 뺀 값은 d 행렬과 같습니다." << endl;
    add >> x; // add 의 각 원소를 x 에 복사
    add.show();
    output2x2(x); // x 배열 출력
    sub >> y; // add 의 각 원소를 x 에 복사
    sub.show();
    output2x2(y); // y 배열 출력
    return 0;
}
