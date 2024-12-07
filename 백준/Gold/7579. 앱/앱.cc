#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N, M, ans;
pair<int, int> arr[100];
int dp[100][10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i) cin >> arr[i].first;
    for(int i = 0; i < N; ++i) cin >> arr[i].second;
    
    if(N == 1) {
        cout << arr[0].second;
        return 0;
    }
    
    for(int i = 0; i <= 10000; ++i) {
        if(arr[0].second > i) continue;
        dp[0][i] = arr[0].first;
    }
    
    for(int i = 1; i < N; ++i) {
        for(int j = 0; j <= 10000; ++j) {
            if(arr[i].second > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].second] + arr[i].first);
            }
            
            if(dp[i][j] >= M) {
                ans = j;
                break;
            }
        }
    }
    
    cout << ans;
    return 0;
}