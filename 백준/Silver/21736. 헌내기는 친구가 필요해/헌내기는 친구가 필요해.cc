#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;
char board[600][600];
bool visit[600][600];
queue<pair<int, int>> q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool validRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int bfs() {
    int cnt = 0;
    
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny)) continue;
            if(board[nx][ny] == 'X' || visit[nx][ny]) continue;
            cnt += (board[nx][ny] == 'P');
            
            q.emplace(nx, ny);
            visit[nx][ny] = true;
        }
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> board[i][j];
            if(board[i][j] == 'I') {
                q.emplace(i, j);
                visit[i][j] = true;
            }
        }
    }
    
    int ans = bfs();
    if(ans == 0) cout << "TT";
    else cout << ans;
    return 0;
}