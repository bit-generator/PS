#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int n, mx, mn = 200, ans;
int board[100][100];
bool visit[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool validRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool bfs(int x, int len) {
    memset(visit, 0, sizeof(visit));
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    visit[0][0] = true;
    int st = board[0][0], en = board[0][0];
    
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny) || visit[nx][ny]) continue;
            if(board[nx][ny] < x || board[nx][ny] > x + len) continue;
            
            q.emplace(nx, ny);
            visit[nx][ny] = true;
            st = min(st, board[nx][ny]);
            en = max(en, board[nx][ny]);
        }
    }
    
    if(!visit[n - 1][n - 1]) return false;
    return true;
}

bool solve(int target) {
    for(int i = 0; i + target <= mx; ++i) {
        if(board[0][0] < i || board[0][0] > i + target) continue;
        if(board[n - 1][n - 1] < i || board[n - 1][n - 1] > i + target) continue;
        if(bfs(i, target)) return true;
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> board[i][j];
            mx = max(mx, board[i][j]);
            mn = min(mn, board[i][j]);
        }
    }
    
    int st = 0, en = mx - mn;
    while(st <= en) {
        int mid = (st + en) / 2;
        if(solve(mid)) {
            en = mid - 1;
            ans = mid;
        }
        else {
            st = mid + 1;
        }
    }
    
    cout << ans;
    return 0;
}