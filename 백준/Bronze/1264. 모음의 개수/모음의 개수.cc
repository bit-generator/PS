#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        getline(cin, str);
        if(str == "#") break;
        
        int ans = 0;
        for(char ch : str) {
            char c = tolower(ch);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}