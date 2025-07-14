#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[501];
int dp[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> arr[i] >> arr[i + 1];
    }
    
    for(int len = 2; len <= N; ++len) {
        for(int i = 0; i <= N - len; ++i) {
            dp[i][i + len] = 0x7FFFFFFF;
            
            for(int j = i + 1; j < i + len; ++j) {
                int tmp = dp[i][j] + dp[j][i + len] + arr[i] * arr[j] * arr[i + len];
                dp[i][i + len] = min(dp[i][i + len], tmp);
            }
        }
    }
    
    cout << dp[0][N];
    return 0;
}