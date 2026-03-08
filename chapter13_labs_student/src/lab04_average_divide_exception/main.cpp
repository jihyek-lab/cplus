#include <iostream>
using namespace std;

int main() {
    int n, sum, average;
    while(true) {
        cout << "합>>"; cin >> sum;
        cout << "인원수>>"; cin >> n;

        try {
            if(n <= 0) throw n;
            average = sum / n;
        } catch(int x) {
            cout << "예외: " << x << "으로 나눌 수 없음\n";
            continue;
        }
        cout << "평균=" << average << "\n";
    }
}
