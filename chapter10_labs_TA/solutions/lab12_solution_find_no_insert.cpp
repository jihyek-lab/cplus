#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<string,string> dic;
    dic["love"]="사랑";
    string eng="love";
    auto it = dic.find(eng);
    if(it==dic.end()) cout << "없음\n";
    else cout << it->second << "\n"; // [] 안 씀 -> 삽입 부작용 없음
}
