#include <iostream>
using namespace std;

long long sum(long long a, long long b) { return a + b; }
int sum(int a, int b) { return a + b; }

int main() {
    cout << sum(2, 3) << "\n";
    cout << sum(10000000000LL, 20000000000LL) << "\n";
}
