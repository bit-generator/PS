#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char board[8][8][8];
bool visit[8][8][8];
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};

bool validRange(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void bfs() {
    queue<tuple<int, int, int>> q;
    q.emplace(0, 7, 0);
    visit[0][7][0] = true;
    
    while(!q.empty()) {
        int curt, curx, cury;
        tie(curt, curx, cury) = q.front();
        q.pop();
        if(curt >= 7) continue;
        
        for(int i = 0; i < 9; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny) || visit[curt + 1][nx][ny] != 0) continue;
            if(board[curt][nx][ny] == '#' || board[curt + 1][nx][ny] == '#') continue;
            
            q.emplace(curt + 1, nx, ny);
            visit[curt + 1][nx][ny] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            cin >> board[0][i][j];
            
            for(int k = 1; i + k < 8; ++k) {
                board[k][i + k][j] = board[0][i][j];
            }
        }
    }
    
    bfs();
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(visit[7][i][j] == 1) {
                cout << 1;
                return 0;
            }
        }
    }
    
    cout << 0;
    return 0;
}