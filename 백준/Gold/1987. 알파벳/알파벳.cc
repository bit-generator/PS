#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int R, C, ans = 1;
char board[20][21];
bool visit[20][20];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool validRange(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void dfs(int x, int y, int mask, int cnt) {
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!validRange(nx, ny)) continue;
        if(mask & (1 << (board[nx][ny] - 'A'))) continue;

        ans = max(ans, cnt + 1);
        dfs(nx, ny, mask | (1 << (board[nx][ny] - 'A')), cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C;
    for(int i = 0; i < R; ++i) cin >> board[i];
    
    dfs(0, 0, 1 << (board[0][0] - 'A'), 1);
    
    cout << ans;
    return 0;
}