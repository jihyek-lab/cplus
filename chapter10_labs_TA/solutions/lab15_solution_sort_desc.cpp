#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    vector<int> v = {5,1,3,2,4};
    sort(v.begin(), v.end(), greater<int>());
    for(int x: v) cout << x << " ";
    cout << "\n";
}
