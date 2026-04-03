#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K, odd, even, ans = 4'000'000;
char board[2001][2001];
int sum[2][2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    even = K * K / 2;
    odd = K * K - even;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> board[i][j];
            sum[0][i][j] = sum[0][i - 1][j] + sum[0][i][j - 1] - sum[0][i - 1][j - 1];
            sum[1][i][j] = sum[1][i - 1][j] + sum[1][i][j - 1] - sum[1][i - 1][j - 1];
            if (board[i][j] == 'B') {
                if ((i + j) % 2 == 0) ++sum[0][i][j];
                else ++sum[1][i][j];
            }
        }
    }

    for (int i = 0; i <= N - K; ++i) {
        for (int j = 0; j <= M - K; ++j) {
            int cnt = 0;

            if ((i + j) % 2 == 0) {
                int oddCnt = sum[0][i + K][j + K] - sum[0][i][j + K] - sum[0][i + K][j] + sum[0][i][j];
                int evenCnt = sum[1][i + K][j + K] - sum[1][i][j + K] - sum[1][i + K][j] + sum[1][i][j];
                cnt = min(odd - oddCnt + evenCnt, oddCnt + even - evenCnt);
            }
            else {
                int evenCnt = sum[0][i + K][j + K] - sum[0][i][j + K] - sum[0][i + K][j] + sum[0][i][j];
                int oddCnt = sum[1][i + K][j + K] - sum[1][i][j + K] - sum[1][i + K][j] + sum[1][i][j];
                cnt = min(odd - oddCnt + evenCnt, oddCnt + even - evenCnt);
            }

            ans = min(ans, cnt);
        }
    }

    cout << ans;
    return 0;
}