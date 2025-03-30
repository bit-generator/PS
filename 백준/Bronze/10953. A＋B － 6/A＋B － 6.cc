#include <iostream>
#include <string>
using namespace std;

int T;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> str;
        cout << (str[0] - '0') + (str[2] - '0') << '\n';
    }
    
    return 0;
}