#include <iostream>
using namespace std;

/*
[Lab04] 디폴트 인자를 이용한 생성자 간소화
------------------------------------------------------------
강의 핵심
1) 생성자에도 디폴트 매개변수를 줄 수 있다.
2) 그러면 "기본 생성자"와 "크기를 받는 생성자" 역할을 하나로 합칠 수 있다.
3) 동적 메모리를 가진 클래스는 생성자와 소멸자를 함께 설명해야 이해가 완성된다.
4) 실습에서는 내부 배열을 0으로 초기화해 상태 변화를 눈으로 확인하는 것이 좋다.
------------------------------------------------------------
*/

class MyVector {
private:
    int* p;
    int size;

public:
    // 생성자 하나에 디폴트 값을 두면 두 종류의 호출을 함께 처리할 수 있다.
    MyVector(int n = 100) {
        p = new int[n];
        size = n;

        // 상태 변화를 보기 쉽도록 처음에는 0으로 채운다.
        for (int i = 0; i < size; ++i) {
            p[i] = 0;
        }
    }

    // new[]에 대응하는 정리는 delete[]다.
    ~MyVector() {
        delete[] p;
    }

    int getSize() const {
        return size;
    }

    void set(int index, int value) {
        // 간단한 범위 검사를 넣어 두면 실습 중 결과 해석이 쉬워진다.
        if (0 <= index && index < size) {
            p[index] = value;
        }
    }

    void printPreview(int count) const {
        // 큰 배열은 앞부분만 보는 편이 핵심 확인에 적합하다.
        int limit = (count < size) ? count : size;
        for (int i = 0; i < limit; ++i) {
            cout << p[i] << ' ';
        }
        cout << "\n";
    }
};

int main() {
    // 같은 생성자라도 인수 유무에 따라 다른 초기화가 가능하다.
    MyVector v1;
    MyVector v2(8);

    // 일부 값만 바꿔 보면 초기값과 변경값이 함께 드러난다.
    v1.set(0, 100);
    v1.set(1, 200);
    v2.set(0, 7);
    v2.set(1, 8);

    cout << "v1 size = " << v1.getSize() << "\n";
    cout << "v1 preview = ";
    v1.printPreview(5);

    cout << "v2 size = " << v2.getSize() << "\n";
    cout << "v2 preview = ";
    v2.printPreview(5);

    return 0;
}
