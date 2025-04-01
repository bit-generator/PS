#include <iostream>
#include <string>
using namespace std;

int T;
string str1, str2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> str1 >> str2;
        if(str1 == str2) cout << "OK\n";
        else cout << "ERROR\n";
    }
    
    return 0;
}