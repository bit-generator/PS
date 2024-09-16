#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int N, K;
pair<int, int> stuff[100];
int dp[100][100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> stuff[i].first >> stuff[i].second;
    
    for(int j = 1; j <= K; j++) {
        if(j < stuff[0].first) continue;
        dp[0][j] = stuff[0].second;
    }
    
    for(int i = 1; i < N; i++) {
        for(int j = 1; j <= K; j++) {
            if(j < stuff[i].first) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stuff[i].first] + stuff[i].second);
            }
        }
    }
    
    cout << dp[N - 1][K];
    return 0;
}