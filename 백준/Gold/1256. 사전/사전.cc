#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int dp[201][201];

void fillDP() {
    dp[0][0] = 1;
    dp[1][0] = 1; dp[1][1] = 1;

    for (int i = 2; i <= N + M; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = min(1'000'000'001, dp[i - 1][j - 1] + dp[i - 1][j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    fillDP();
    if (dp[N + M][N] < K) {
        cout << -1;
        return 0;
    }

    while (N > 0) {
        if (dp[N + M - 1][N - 1] >= K) {
            --N;
            cout << 'a';
        }
        else {
            K -= dp[N + M - 1][N - 1];
            --M;
            cout << 'z';
        }
    }

    while (M--) cout << 'z';

    return 0;
}