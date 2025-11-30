#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans = 1'000'000'000;
int board[6][6];
int dp[6][6][3];
int dy[] = {-1, 0, 1};

inline bool validRange(int y) {
    return y >= 0 && y < M;
}

void solve(int x, int y) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(i == j || !validRange(y + dy[j])) continue;
            
            int ny = y + dy[j];
            if(dp[x][y][i] == 0) dp[x][y][i] = dp[x - 1][ny][j] + board[x][y];
            else dp[x][y][i] = min(dp[x][y][i], dp[x - 1][ny][j] + board[x][y]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) cin >> board[i][j];
    }
    
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < 3; ++j) {
            dp[0][i][j] = board[0][i];
        }
    }
    
    for(int i = 1; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            solve(i, j);
        }
    }
    
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < 3; ++j) {
            ans = min(ans, dp[N - 1][i][j]);
        }
    }
    
    cout << ans;
    return 0;
}