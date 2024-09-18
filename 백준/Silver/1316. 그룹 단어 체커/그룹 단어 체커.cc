#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int N, ans;
string str;
bool alpha[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    while(N--) {
        cin >> str;
        
        char ch = str[0];
        int i = 1;
        memset(alpha, 0, sizeof(bool) * 26);
        
        alpha[str[0] - 'a'] = true;
        bool isgroup = true;
        
        while(i < str.length()) {
            if(str[i] != ch) {
                if(alpha[str[i] - 'a']) {
                    isgroup = false;
                    break;
                }
                ch = str[i];
                alpha[str[i] - 'a'] = true;
            }
            
            i++;
        }
        
        if(isgroup) ans++;
    }
    
    cout << ans;
    return 0;
}