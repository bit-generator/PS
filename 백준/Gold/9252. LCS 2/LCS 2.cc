#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str1, str2;
int len1, len2;
int dp[1001][1001];
vector<char> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str1 >> str2;
    len1 = str1.length();
    len2 = str2.length();
    
    for(int i = 0; i < len1; ++i) {
        for(int j = 0; j < len2; ++j) {
            if(str1[i] == str2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    
    cout << dp[len1][len2] << '\n';
    
    while(dp[len1][len2]) {
        if(str1[len1 - 1] == str2[len2 - 1]) {
            ans.push_back(str1[len1 - 1]);
            --len1; --len2;
        }
        else {
            if(dp[len1 - 1][len2] > dp[len1][len2 - 1]) --len1;
            else --len2;
        }
    }
    
    for(int i = ans.size() - 1; i >= 0; --i) cout << ans[i];
    return 0;
}