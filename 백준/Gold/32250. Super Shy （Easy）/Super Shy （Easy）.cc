#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[3000001];

int solve(int n) {
    if (dp[n] > 0) return dp[n];
    return dp[n] = solve((n + 1) / 2) + solve(n / 2 + 1) - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    dp[1] = 1, dp[2] = 1, dp[3] = 2, dp[4] = 2;

    for (int i = 3; i <= (N + 1) / 2; i++) {
        dp[N] = max(dp[N], solve(i) + solve(N - i + 1) - 1);
    }

    cout << dp[N];
    return 0;
}