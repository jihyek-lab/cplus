#include <iostream>
using namespace std;

ostream& tenstar(ostream& os){
    return os << "**********";
}

int main(){
    cout << tenstar << "\n";
}
