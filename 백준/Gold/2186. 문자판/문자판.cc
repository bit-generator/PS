#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int N, M, K, ans;
char board[100][100];
int dp[100][100][80];
string str;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool validRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int dfs(int x, int y, int idx) {
    if(dp[x][y][idx] != -1) return dp[x][y][idx];
    dp[x][y][idx] = 0;
    
    if(idx == str.length() - 1) {
        ++dp[x][y][idx];
        return dp[x][y][idx];
    }
    
    for(int i = 0; i < 4; ++i) {
        for(int j = 1; j <= K; ++j) {
            int nx = x + dx[i] * j;
            int ny = y + dy[i] * j;
            if(!validRange(nx, ny) || str[idx + 1] != board[nx][ny]) continue;
        
            dp[x][y][idx] += dfs(nx, ny, idx + 1);
        }
    }
    
    return dp[x][y][idx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> K;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }
    
    cin >> str;
    memset(dp, -1, sizeof(dp));
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(str[0] == board[i][j]) {
                ans += dfs(i, j, 0);
            }
        }
    }
    
    cout << ans;
    return 0;
}