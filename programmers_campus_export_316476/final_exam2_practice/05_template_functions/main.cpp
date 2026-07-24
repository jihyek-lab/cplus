/*
 * 실습용 starter code
 * 문제: 함수 템플릿 종합
 *
 * 학생용 가이드:
 * - README.md 에 문제 설명과 체크리스트가 정리되어 있습니다.
 * - 아래 코드의 TODO 위치를 중심으로 구현을 진행하세요.
 * - 필요하면 main 함수는 그대로 두고, 클래스/함수 구현만 채워 넣는 방식으로 연습해 보세요.
 */

#include <iostream>
using namespace std;
// TODO 1:
// 길이 len 의 동적 배열을 만들고, len 개의 값을 입력받아 반환하세요.
template <class T> T *scanArray(int len);
// TODO 2:
// 배열의 원소 순서를 제자리에서 뒤집으세요.
template <class T> void reverseArray(T *arr, int len);
// TODO 3:
// arr 에서 removeArr 의 원소들을 제거한 새 동적 배열을 만들고, 새 길이를 outLen 에 저장하세요.
template <class T> T *remove(T *arr, int arrLen, T *removeArr, int removeLen, int &outLen);
// TODO 4:
// 두 배열을 순서대로 이어 붙인 새 동적 배열을 반환하세요.
template <class T> T *concat(T *a, int aLen, T *b, int bLen);
// TODO 5:
// target 을 찾은 첫 인덱스를 반환하고, 없으면 -1 을 반환하세요.
template <class T> int search(T *arr, int len, T target);
// 배열의 포인터와 길이를 인자로 받아 모든 원소를 출력
template <class T> void printArray(T *arr, int len) {
    for (int i = 0; i < len; i++)
    cout << arr[i] << " ";
    cout << endl;
}
template <class T> void run() {
    int aSize, bSize, cSize, dSize, eSize;
    T *a, *b, *c, *d, *e;
    // a 배열 입력 및 뒤집기
    cin >> aSize;
    a = scanArray<T>(aSize);
    reverseArray(a, aSize);
    printArray(a, aSize); // 뒤집을 배열 출력
    // b 배열 입력
    cin >> bSize;
    b = scanArray<T>(bSize);
    // a, b 배열 합치기
    cSize = aSize + bSize;
    c = concat(a, aSize, b, bSize);
    printArray(c, cSize); // 합쳐진 배열 출력
    // 제거할 배열 입력 및 제거
    cin >> dSize;
    d = scanArray<T>(dSize);
    e = remove(c, cSize, d, dSize, eSize);
    printArray(e, eSize); // 원소를 제거한 배열 출력
    // 특정 원소가 저장된 인덱스 찾기
    T element;
    int find;
    cin >> element;
    find = search<T>(e, eSize, element);
    cout << find << endl;
    delete[] a;
    delete[] b;
    delete[] c;
    if (d)
    delete[] d;
    delete[] e;
}
enum DATA_TYPE { INT, CHAR, FLOAT };
int main() {
    int dtype;
    cin >> dtype;
    switch (dtype) {
        case INT:
        run<int>();
        break;
        case CHAR:
        run<char>();
        break;
        case FLOAT:
        run<float>();
        break;
        default:
        break;
    }
    return 0;
}
