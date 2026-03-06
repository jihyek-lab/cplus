#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
[Lab10] vector<string> + 사전순(lexicographic) 비교
------------------------------------------------------------
핵심
- string의 < 비교는 사전순 비교
- getline으로 공백 포함 입력 가능

주의
- 이 코드는 입력을 5줄 받는다. (빈 줄도 입력으로 취급)
------------------------------------------------------------
*/

int main() {
    vector<string> sv;
    string name;

    cout << "이름을 5개 입력하라\n";
    for(int i=0;i<5;i++){
        cout << i+1 << ">>";
        getline(cin, name);
        sv.push_back(name);
    }

    name = sv.at(0);
    for(int i=1;i<(int)sv.size();i++)
        if(name < sv[i]) name = sv[i];

    cout << "사전에서 가장 뒤에 나오는 이름은 " << name << "\n";
}
