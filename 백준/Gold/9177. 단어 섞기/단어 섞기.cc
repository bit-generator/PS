#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int T;
string str1, str2, str3;
bool dp[401][401];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    for(int tc = 1; tc <= T; ++tc) {
        cin >> str1 >> str2 >> str3;
        
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        int len = str3.length();
        
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j <= i; ++j) {
                if(!dp[j][i - j]) continue;
                
                if(str3[i] == str1[j]) {
                    dp[j + 1][i - j] = true;
                }
                
                if(str3[i] == str2[i - j]) {
                    dp[j][i - j + 1] = true;
                }
            }
        }
        
        bool isExist = false;
        for(int i = 0; i <= len; ++i) {
            if(dp[i][len - i]) {
                isExist = true;
                break;
            }
        }
        
        cout << "Data set " << tc << ": ";
        if(isExist) cout << "yes";
        else cout << "no";
        cout << '\n';
    }
    
    return 0;
}