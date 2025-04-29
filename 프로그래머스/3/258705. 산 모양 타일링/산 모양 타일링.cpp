#include <string>
#include <vector>
#define MOD 10007
using namespace std;

int dp[100001][2];

int solution(int n, vector<int> tops) {
    dp[0][1] = 1;
    
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] * (tops[i - 1] + 1) + dp[i - 1][1] * (tops[i - 1] + 2)) % MOD;
    }
    
    return (dp[n][0] + dp[n][1]) % MOD;
}