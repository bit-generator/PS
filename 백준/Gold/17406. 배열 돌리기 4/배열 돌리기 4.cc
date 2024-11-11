#include <iostream>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstring>
using namespace std;

int N, M, K, r, c, s, ans = 500000;
int A[51][51];
int board[51][51];
tuple<int, int, int> info[6];
int order[6] = { 0, 1, 2, 3, 4, 5 };

void rotate(int idx) {
    int row, col, offset;
    tie(row, col, offset) = info[idx];

    for (int os = 1; os <= offset; os++) {
        int topright = board[row - os][col + os];
        int downleft = board[row + os][col - os];

        for (int i = col + os; i >= col - os + 1; i--) {
            board[row - os][i] = board[row - os][i - 1];
        }

        for (int i = col - os; i <= col + os - 1; i++) {
            board[row + os][i] = board[row + os][i + 1];
        }
        //memcpy(&board[row - os][col - os + 1], &board[row - os][col - os], sizeof(int) * (os * 2));
       // memcpy(&board[row + os][col - os], &board[row + os][col - os + 1], sizeof(int) * (os * 2));

        for (int i = row - os; i <= row + os - 2; i++) {
            board[i][col - os] = board[i + 1][col - os];
        }
        board[row + os - 1][col - os] = downleft;

        for (int i = row + os; i >= row - os + 2; i--) {
            board[i][col + os] = board[i - 1][col + os];
        }
        board[row - os + 1][col + os] = topright;
    }
}

void solve() {
    for (int i = 0; i < K; i++) {
        rotate(order[i]);
    }

    for (int i = 1; i <= N; i++) {
        ans = min(ans, (int)accumulate(board[i] + 1, board[i] + M + 1, 0));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        cin >> r >> c >> s;
        info[i] = { r, c, s };
    }

    do {
        for (int i = 1; i <= N; i++) {
            memcpy(board[i] + 1, A[i] + 1, sizeof(int) * M);
        }

        solve();
    } while (next_permutation(order, order + K));

    cout << ans;
    return 0;
}