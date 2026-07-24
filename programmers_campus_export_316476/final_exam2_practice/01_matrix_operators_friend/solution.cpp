/*
 * Reference solution
 * 문제 1: 연산자 중복과 프렌드 함수
 *
 * 문제 요약:
 * - 2x2 행렬 클래스 matrix 를 구현한다.
 * - +, += 는 멤버 함수로, -, -= 는 프렌드 함수로 구현한다.
 * - == 비교와 배열 <-> matrix 복사 연산자(>>, <<)도 함께 완성한다.
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

    matrix operator+(matrix &m);
    matrix &operator+=(matrix &m);
    friend matrix operator-(matrix &lhs, matrix &rhs);
    friend matrix &operator-=(matrix &lhs, matrix &rhs);
    bool operator==(matrix &m);
    matrix &operator>>(int m[][2]);
    friend matrix &operator<<(matrix &lhs, int rhs[][2]);
};

matrix::matrix(int e11, int e12, int e21, int e22) {
    // 생성자에서 2x2 원소를 한 번에 저장한다.
    e[0][0] = e11;
    e[0][1] = e12;
    e[1][0] = e21;
    e[1][1] = e22;
}

matrix matrix::operator+(matrix &m) {
    return matrix(
        e[0][0] + m.e[0][0], e[0][1] + m.e[0][1],
        e[1][0] + m.e[1][0], e[1][1] + m.e[1][1]);
}

matrix &matrix::operator+=(matrix &m) {
    // 현재 객체를 직접 수정하는 누적 연산이다.
    e[0][0] += m.e[0][0];
    e[0][1] += m.e[0][1];
    e[1][0] += m.e[1][0];
    e[1][1] += m.e[1][1];
    return *this;
}

matrix operator-(matrix &lhs, matrix &rhs) {
    return matrix(
        lhs.e[0][0] - rhs.e[0][0], lhs.e[0][1] - rhs.e[0][1],
        lhs.e[1][0] - rhs.e[1][0], lhs.e[1][1] - rhs.e[1][1]);
}

matrix &operator-=(matrix &lhs, matrix &rhs) {
    lhs.e[0][0] -= rhs.e[0][0];
    lhs.e[0][1] -= rhs.e[0][1];
    lhs.e[1][0] -= rhs.e[1][0];
    lhs.e[1][1] -= rhs.e[1][1];
    return lhs;
}

bool matrix::operator==(matrix &m) {
    return e[0][0] == m.e[0][0] && e[0][1] == m.e[0][1] &&
           e[1][0] == m.e[1][0] && e[1][1] == m.e[1][1];
}

matrix &matrix::operator>>(int m[][2]) {
    // matrix -> 일반 배열 방향으로 복사한다.
    m[0][0] = e[0][0];
    m[0][1] = e[0][1];
    m[1][0] = e[1][0];
    m[1][1] = e[1][1];
    return *this;
}

matrix &operator<<(matrix &lhs, int rhs[][2]) {
    // 일반 배열 -> matrix 방향으로 복사한다.
    lhs.e[0][0] = rhs[0][0];
    lhs.e[0][1] = rhs[0][1];
    lhs.e[1][0] = rhs[1][0];
    lhs.e[1][1] = rhs[1][1];
    return lhs;
}

void input2x2(int m[][2]) {
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            cin >> m[row][col];
        }
    }
}

void output2x2(int m[][2]) {
    cout << "array [[";
    cout << m[0][0] << ", " << m[0][1] << "], [";
    cout << m[1][0] << ", " << m[1][1] << "]]" << endl;
}

int main() {
    int e11, e12, e21, e22;
    cin >> e11 >> e12 >> e21 >> e22;
    matrix m(e11, e12, e21, e22);
    m.show();

    int x[2][2], y[2][2], z[2][2], w[2][2];
    input2x2(x);
    input2x2(y);
    input2x2(z);
    input2x2(w);

    matrix a, b, c, d;
    a << x;
    b << y;
    c << z;
    d << w;

    a += b;
    c -= d;

    // 연산 결과를 별도 객체로 만들어 비교한다.
    matrix add = a + d;
    matrix sub = b - c;

    if (add == c) {
        cout << "a 행렬과 d 행렬을 더한 값은 c 행렬과 같습니다." << endl;
    }
    if (sub == d) {
        cout << "b 행렬과 c 행렬을 뺀 값은 d 행렬과 같습니다." << endl;
    }

    add >> x;
    add.show();
    output2x2(x);

    sub >> y;
    sub.show();
    output2x2(y);
    return 0;
}
