#include <iostream>
#include <algorithm>
using namespace std;

int N;
int L[21], J[21];
int dp[21][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> L[i];
    for(int i = 1; i <= N; ++i) cin >> J[i];
    
    for(int i = 1; i <= N; ++i) {
        for(int j = 100; j >= 1; --j) {
            if(j + L[i] > 100) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j + L[i]] + J[i], dp[i - 1][j]);
        }
    }
    
    cout << dp[N][1];
    return 0;
}