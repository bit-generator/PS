#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr size_t MAX_VAL = 1'000'000'000;
int N, M, dstX, dstY, ans = MAX_VAL;
int pos[2][4];
int board[101][101];
int visit[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool validRange(int x, int y) {
    return x >= 0 && x <= N && y >= 0 && y <= M;
}

void initBoard() {
    memset(board, 0, sizeof(board));
    for(int i = 0; i < 2; ++i) {
        board[pos[i][0]][pos[i][1]] = i + 1;
        board[pos[i][2]][pos[i][3]] = i + 1;
    }
}

int floodFill(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    memset(visit, 0, sizeof(visit));
    visit[x][y] = 1;
    int idx = board[x][y];
    
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny) || visit[nx][ny]) continue;
            
            if(board[nx][ny] == idx) {
                visit[nx][ny] = visit[curx][cury] + 1;
                dstX = nx;
                dstY = ny;
                return visit[curx][cury];
            }
            else if(board[nx][ny] == 0) {
                visit[nx][ny] = visit[curx][cury] + 1;
                q.emplace(nx, ny);
            }
        }
    }
    
    return -1;
}

void connect() {
    while(visit[dstX][dstY] != 1) {
        for(int i = 0; i < 4; ++i) {
            int nx = dstX + dx[i];
            int ny = dstY + dy[i];
            if(!validRange(nx, ny)) continue;
            if(visit[nx][ny] == visit[dstX][dstY] - 1) {
                board[nx][ny] = board[dstX][dstY];
                dstX = nx;
                dstY = ny;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 4; j += 2) {
            cin >> pos[i][j] >> pos[i][j + 1];
        }
    }
    
    for(int i = 0; i < 2; ++i) {
        initBoard();
        int len1 = floodFill(pos[i][0], pos[i][1]);
        if(len1 != -1) {
            connect();
            int len2 = floodFill(pos[!i][0], pos[!i][1]);
            if(len2 != -1) ans = min(ans, len1 + len2);
        }
    }
    
    if(ans == MAX_VAL) cout << "IMPOSSIBLE";
    else cout << ans;
    return 0;
}