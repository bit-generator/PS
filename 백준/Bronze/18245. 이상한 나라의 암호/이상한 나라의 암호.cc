#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 2; ; ++i) {
        getline(cin, str);
        if(str == "Was it a cat I saw?") break;
        
        string ans;
        for(int j = 0; j < str.length(); j += i) {
            ans += str[j];
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}