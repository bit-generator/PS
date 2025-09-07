#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int N, dst;
int board[500][1000];
int idx[500][1000];
bool visit[500][1000];
int prv[249751];
int dx[] = {1, 0, -1, 0, 1};
int dy[] = {0, -1, 0, 1, 0};
vector<int> ans;

bool validRange(int x, int y) {
    if(x >= 0 && x < N) {
        if(x % 2) return y > 0 && y < N * 2 - 1;
        else return y >= 0 && y < N * 2;
    }
    else return false;
}

void bfs() {
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    visit[0][0] = true; visit[0][1] = true;
    
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i = 0; i < 3; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny)) continue;
            if(visit[nx][ny] || board[curx][cury] != board[nx][ny]) continue;
            
            q.emplace(nx, ny - 1);
            visit[nx][ny] = true; visit[nx][ny - 1] = true;
            prv[idx[nx][ny]] = idx[curx][cury];
        }
        
        ++cury;
        for(int i = 2; i < 5; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny)) continue;
            if(visit[nx][ny] || board[curx][cury] != board[nx][ny]) continue;
            
            q.emplace(nx, ny);
            visit[nx][ny] = true; visit[nx][ny + 1] = true;
            prv[idx[nx][ny]] = idx[curx][cury];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = i % 2; j < 2 * N - i % 2; j += 2) {
            cin >> board[i][j] >> board[i][j + 1];
            idx[i][j] = ((i + 1) / 2) * N + (i / 2) * (N - 1) + j / 2 + 1;
            idx[i][j + 1] = idx[i][j];
        }
    }
    
    bfs();
    for(int i = N * N - N / 2; i >= 1; --i) {
        if(prv[i]) {
            dst = i;
            break;
        }
    }
    
    if(dst == 0) {
        cout << 1 << '\n' << 1;
        return 0;
    }
    
    while(dst != 0) {
        ans.push_back(dst);
        dst = prv[dst];
    }
    
    cout << ans.size() << '\n';
    for(int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << ' ';
    }
    
    return 0;
}