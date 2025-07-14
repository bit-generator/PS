#include <iostream>
#include <algorithm>
using namespace std;

int N, r, c;
int arr[501];
int dp[501][501];

int solve(int st, int en) {
    if(en - st <= 1) return 0;
    if(en - st == 2) {
        return dp[st][en] = arr[st] * arr[st + 1] * arr[en];
    }
    
    if(dp[st][en]) return dp[st][en];
    
    int cnt = 0x7FFFFFFF;
    for(int i = st + 1; i < en; ++i) {
        int tmp = solve(st, i) + solve(i, en) + arr[st] * arr[i] * arr[en];
        cnt = min(cnt, tmp);
    }
    
    return dp[st][en] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> arr[i] >> arr[i + 1];
    }
    
    cout << solve(0, N);
    return 0;
}