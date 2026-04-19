#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N;
int cards[1000];
int dp[1000][1000];

int solve(int st, int en, int turns) {
    if(st > en) return 0;
    if(dp[st][en]) return dp[st][en];
    
    int n1 = solve(st + 1, en, turns + 1);
    int n2 = solve(st, en - 1, turns + 1);
    if(turns % 2) dp[st][en] = max(cards[st] + n1, cards[en] + n2);
    else dp[st][en] = min(n1, n2);
    return dp[st][en];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i = 0; i < N; ++i) cin >> cards[i];
        memset(dp, 0, sizeof(dp));
        cout << solve(0, N - 1, 1) << '\n';
    }
    
    return 0;
}