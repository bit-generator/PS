#include <iostream>
#include <algorithm>
using namespace std;

int N, M, maxlen = 1;
bool check[1'000'001];
int dp[1'000'001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    check[M] = true;
    fill(dp, dp + 1'000'001, 1);

    for (int i = 1; i < N; i++) {
        cin >> M;
        if (check[M - 1]) {
            dp[M] = dp[M - 1] + 1;
            maxlen = max(dp[M], maxlen);
        }

        check[M] = true;
    }

    cout << N - maxlen;
    return 0;
}