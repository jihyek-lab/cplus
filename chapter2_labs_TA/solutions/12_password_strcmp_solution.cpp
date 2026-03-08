#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const char correct[] = "zkrypto123";
    char input[50];

    for (int i = 3; i >= 1; --i) {
        cout << "Password (" << i << " tries left): ";
        cin >> input;

        if (strcmp(input, correct) == 0) {
            cout << "Success\n";
            return 0;
        }
        cout << "Wrong\n";
    }
    cout << "Locked out\n";
    return 0;
}
