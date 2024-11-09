#include <iostream>
#include <string>
using namespace std;

string a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> a >> b;
    if(a.length() >= b.length()) cout << "go";
    else cout << "no";
    return 0;
}