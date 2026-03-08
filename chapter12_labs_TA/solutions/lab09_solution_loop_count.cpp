#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream in("./data/src.bin", ios::in|ios::binary);
    ofstream out("./data/dest7.bin", ios::out|ios::binary);
    char buf[7];
    int loops=0;
    while(true){
        in.read(buf, sizeof(buf));
        streamsize n=in.gcount();
        if(n<=0) break;
        out.write(buf, n);
        loops++;
    }
    cout << "loops=" << loops << "\n";
}
