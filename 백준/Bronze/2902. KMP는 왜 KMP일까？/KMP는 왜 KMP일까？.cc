#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string str, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    for(char c : str) {
        if(isupper(c)) ans += c;
    }
    
    cout << ans;
    return 0;
}