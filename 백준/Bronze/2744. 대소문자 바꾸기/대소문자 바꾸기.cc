#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    for(char c : s) {
        if(isupper(c)) cout << (char)tolower(c);
        else cout << (char)toupper(c);
    }
    
    return 0;
}