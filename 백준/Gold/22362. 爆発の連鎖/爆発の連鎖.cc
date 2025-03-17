#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int W, H, N, D, B, X, Y;
bool board[101][101];
bool check[101][101];
int srcX, srcY;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool validRange(int x, int y) {
    return x >= 1 && x <= H && y >= 1 && y <= W;
}

int bfs() {
    queue<pair<int, int>> q;
    q.emplace(srcX, srcY);
    check[srcX][srcY] = true;
    int cnt = 1;
    
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            
            for(int j = 0; j < D && validRange(nx, ny); ++j) {
                if(board[nx][ny] && !check[nx][ny]) {
                    q.emplace(nx, ny);
                    check[nx][ny] = true;
                    ++cnt;
                }
                
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        cin >> W >> H >> N >> D >> B;
        if(!W && !H && !N && !D && !B) break;
        
        for(int i = 1; i <= H; ++i) {
            memset(board[i], 0, W + 1);
            memset(check[i], 0, W + 1);
        }
 
        for(int i = 1; i <= N; ++i) {
            cin >> Y >> X;
            board[X][Y] = true;
            if(i == B) {
                srcX = X;
                srcY = Y;
            }
        }
        
        cout << bfs() << '\n';
    }
    
    return 0;
}