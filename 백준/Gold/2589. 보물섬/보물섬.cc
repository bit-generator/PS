#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

int R, C, ans;
char board[50][50];
int check[50][50];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

bool validRange(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void bfs(int x, int y) {
    memset(check, -1, sizeof(check));
    q.emplace(x, y);
    check[x][y] = 0;
    int cnt = 0;
    
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny)) continue;
            if(board[nx][ny] == 'W' || check[nx][ny] != -1) continue;
            
            q.emplace(nx, ny);
            check[nx][ny] = check[curx][cury] + 1;
            cnt = check[nx][ny];
        }
    }
    
    ans = max(ans, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) cin >> board[i][j];
    }
    
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(board[i][j] == 'L') bfs(i, j);
        }
    }
    
    cout << ans;
    return 0;
}