#include <iostream>
using namespace std;

/*
[Lab03] big() 오버로딩: (두 수 비교) vs (배열 최댓값)
-----------------------------------------
핵심
- 같은 이름 big을 두 가지 용도로 제공:
  1) big(int,int)    : 두 정수 중 큰 값
  2) big(int[],size) : 배열에서 최대값

여기서 확인할 것
- 호출 형태가 다르니 컴파일러가 자동으로 올바른 함수를 선택한다.
-----------------------------------------
*/

int big(int a, int b) {
    return (a > b) ? a : b;
}

int big(int a[], int size) {
    int res = a[0];
    for (int i = 1; i < size; i++)
        if (res < a[i]) res = a[i];
    return res;
}

int main() {
    int array[5] = {1, 9, -2, 8, 6};
    cout << big(2, 3) << "\n";
    cout << big(array, 5) << "\n";
    return 0;
}
