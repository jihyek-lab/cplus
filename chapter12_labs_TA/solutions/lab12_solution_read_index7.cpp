#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("./data/data.dat", ios::in|ios::binary);
    if(!fin){ cout<<"run lab10 first\n"; return 0; }
    fin.seekg(7*(int)sizeof(int), ios::beg);
    int x;
    fin.read((char*)&x, sizeof(x));
    cout << "8th int=" << x << "\n";
}
