/*
 * Reference solution
 * 문제 5: 템플릿 함수 종합
 *
 * 문제 요약:
 * - 배열 입력, 뒤집기, 연결, 제거, 탐색 기능을 템플릿 함수로 구현한다.
 * - int, char, float 세 타입에서 모두 같은 코드가 동작해야 한다.
 */

#include <iostream>
using namespace std;

template <class T>
T *scanArray(int len) {
    if (len <= 0) {
        return nullptr;
    }
    T *arr = new T[len];
    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }
    return arr;
}

template <class T>
void reverseArray(T *arr, int len) {
    // 양끝 원소를 맞바꾸며 가운데로 좁혀 간다.
    for (int i = 0; i < len / 2; i++) {
        T tmp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = tmp;
    }
}

template <class T>
bool contains(T *arr, int len, T value) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

template <class T>
T *remove(T *arr, int arrLen, T *removeArr, int removeLen, int &outLen) {
    // 먼저 결과 배열의 길이를 계산한다.
    outLen = 0;
    for (int i = 0; i < arrLen; i++) {
        if (!contains(removeArr, removeLen, arr[i])) {
            outLen++;
        }
    }

    T *result = new T[outLen];
    int idx = 0;
    // 제거 대상이 아닌 원소만 새 배열에 복사한다.
    for (int i = 0; i < arrLen; i++) {
        if (!contains(removeArr, removeLen, arr[i])) {
            result[idx++] = arr[i];
        }
    }
    return result;
}

template <class T>
T *concat(T *a, int aLen, T *b, int bLen) {
    // a 뒤에 b를 이어 붙인 새 배열을 만든다.
    T *result = new T[aLen + bLen];
    for (int i = 0; i < aLen; i++) {
        result[i] = a[i];
    }
    for (int i = 0; i < bLen; i++) {
        result[aLen + i] = b[i];
    }
    return result;
}

template <class T>
int search(T *arr, int len, T target) {
    // 가장 먼저 찾은 위치를 반환하고, 없으면 -1을 반환한다.
    for (int i = 0; i < len; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

template <class T>
void printArray(T *arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class T>
void run() {
    int aSize, bSize, cSize, dSize, eSize;
    T *a, *b, *c, *d, *e;

    cin >> aSize;
    a = scanArray<T>(aSize);
    reverseArray(a, aSize);
    printArray(a, aSize);

    cin >> bSize;
    b = scanArray<T>(bSize);

    cSize = aSize + bSize;
    c = concat(a, aSize, b, bSize);
    printArray(c, cSize);

    cin >> dSize;
    d = scanArray<T>(dSize);
    e = remove(c, cSize, d, dSize, eSize);
    printArray(e, eSize);

    T element;
    cin >> element;
    cout << search<T>(e, eSize, element) << endl;

    delete[] a;
    delete[] b;
    delete[] c;
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
