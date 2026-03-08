#include <iostream>
#include <fstream>
using namespace std;

static int count_text(const char* file){
    ifstream fin(file);
    int c, n=0;
    while((c=fin.get())!=EOF) n++;
    return n;
}
static int count_bin(const char* file){
    ifstream fin(file, ios::in|ios::binary);
    int c, n=0;
    while((c=fin.get())!=EOF) n++;
    return n;
}

int main(){
    const char* f="./data/sample.txt";
    cout << "text count=" << count_text(f) << "\n";
    cout << "bin  count=" << count_bin(f) << "\n";
}
