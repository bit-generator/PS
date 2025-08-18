#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int N, M;
char board[1000][1000];
bool visit[1000][1000];
int ans[1000][1000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool validRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void countCells(int x, int y) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    q.emplace(x, y);
    visit[x][y] = true;
    int cnt = 1;
    
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny) || visit[nx][ny]) continue;
            
            visit[nx][ny] = true;
            
            if(board[nx][ny] == '1') {
                v.emplace_back(nx, ny);
                continue;
            }
            
            q.emplace(nx, ny);
            ++cnt;
        }
    }
    
    for(const auto& p : v) {
        int curx = p.first, cury = p.second;
        ans[curx][cury] += cnt;
        visit[curx][cury] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> board[i][j];
            if(board[i][j] == '1') ++ans[i][j];
        }
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(board[i][j] == '1' || visit[i][j]) continue;
            countCells(i, j);
        }
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cout << ans[i][j] % 10;
        }
        
        cout << '\n';
    }
    
    return 0;
}