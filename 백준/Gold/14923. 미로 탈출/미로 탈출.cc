#include <iostream>
#include <utility>
#include <tuple>
#include <queue>
using namespace std;

int N, M, Hx, Hy, Ex, Ey;
int board[1000][1000];
int dist[1000][1000][2];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValidRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int bfs() {
    queue<tuple<int, int, int>> q;
    q.emplace(Hx, Hy, 0);
    dist[Hx][Hy][0] = 1;
    
    while(!q.empty()) {
        int curx, cury, curz;
        tie(curx, cury, curz) = q.front();
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            int nz = curz;
            
            if(!isValidRange(nx, ny)) continue;
            if(nx == Ex && ny == Ey)
                return dist[curx][cury][curz];
            
            if(board[nx][ny] == 1) {
                if(nz) continue;
                nz = 1;
            }
            
            if(dist[nx][ny][nz] != 0 &&
               dist[curx][cury][curz] + 1 >= dist[nx][ny][nz]) continue;
            
            dist[nx][ny][nz] = dist[curx][cury][curz] + 1;
            q.emplace(nx, ny, nz);
        }
    }
    
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> Hx >> Hy >> Ex >> Ey;
    --Hx; --Hy; --Ex; --Ey;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }
    
    cout << bfs();
    return 0;
}