#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int R, C;
char board[10][10];
bool boom[10][10];
int visit[10][10];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool validRange(int x, int y) {
    return x >= 0 && x < 10 && y >= 0 && y < 10;
}

void explode(int x, int y) {
    boom[x][y] = true;
    
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        while(validRange(nx, ny)) {
            boom[nx][ny] = true;
            nx += dx[i];
            ny += dy[i];
        }
    }
}

int bfs() {
    queue<pair<int, int>> q;
    q.emplace(R - 1, C - 1);
    visit[R - 1][C - 1] = 1;
    
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        if(!boom[curx][cury]) {
            return visit[curx][cury] - 1;
        }
        
        for(int i = 0; i < 4; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny) || visit[nx][ny]) continue;
            
            q.emplace(nx, ny);
            visit[nx][ny] = visit[curx][cury] + 1;
        }
    }
    
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C;
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            cin >> board[i][j];
            if(board[i][j] == 'o') {
                explode(i, j);
            }
        }
    }
    
    cout << bfs();
    return 0;
}