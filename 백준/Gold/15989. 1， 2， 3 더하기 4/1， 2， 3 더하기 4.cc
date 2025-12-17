#include <iostream>
using namespace std;

int T, n;
int dp[10001][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    dp[1][1] = 1;
    dp[2][1] = 1; dp[2][2] = 1;
    dp[3][1] = 2; dp[3][3] = 1;
    
    for(int i = 4; i <= 10000; ++i) {
        dp[i][1] = dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
        dp[i][2] = dp[i - 2][2] + dp[i - 2][3];
        dp[i][3] = dp[i - 3][3];
    }
    
    while(T--) {
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
    }
    
    return 0;
}