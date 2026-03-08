#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char cmd[80];
    while(true){
        cout << ">> ";
        cin.get(cmd,80);
        if(strcmp(cmd,"exit")==0) break;
        cin.ignore(80,'\n'); // '\n'까지 제거(안전)
    }
    cout << "bye\n";
}
