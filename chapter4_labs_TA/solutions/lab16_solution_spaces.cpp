#include <iostream>
#include <string>
using namespace std;

static string removeSpaces(const string& s) {
    string t;
    for (char ch : s) if (ch != ' ') t.push_back(ch);
    return t;
}

int main() {
    string s;
    getline(cin, s);
    s = removeSpaces(s);

    long long sum = 0;
    int start = 0;
    while (true) {
        int idx = (int)s.find('+', start);
        if (idx == -1) {
            string part = s.substr(start);
            if (part != "") sum += stoi(part);
            break;
        }
        string part = s.substr(start, idx - start);
        if (part != "") sum += stoi(part);
        start = idx + 1;
    }
    cout << sum << "\n";
}
