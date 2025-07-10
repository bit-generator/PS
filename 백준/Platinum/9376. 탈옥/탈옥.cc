#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#define INF    100'000'000
using namespace std;
using Tuple = tuple<int, int, int>;
using PQ = priority_queue<Tuple, vector<Tuple>, greater<>>;

int T, h, w, ans;
char board[102][102];
int check[3][102][102];
pair<int, int> src[3];
int srcCnt;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool validRange(int x, int y) {
    return x >= 0 && x <= h + 1 && y >= 0 && y <= w + 1;
}

void dijkstra(int idx) {
    PQ pq;
    for(int i = 0; i <= h + 1; ++i) {
        fill(check[idx][i], check[idx][i] + w + 2, INF);
    }
    
    pq.emplace(0, src[idx].first, src[idx].second);
    check[idx][src[idx].first][src[idx].second] = 0;
    
    while(!pq.empty()) {
        int curx, cury, cost;
        tie(cost, curx, cury) = pq.top();
        pq.pop();
        
        if(check[idx][curx][cury] < cost) continue;
        
        for(int i = 0; i < 4; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny) || board[nx][ny] == '*') continue;
            
            int ncost = (board[nx][ny] == '#' ? cost + 1 : cost);
            if(ncost < check[idx][nx][ny]) {
                check[idx][nx][ny] = ncost;
                pq.emplace(ncost, nx, ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> h >> w;
        srcCnt = 0;
        for(int i = 1; i <= h; ++i) {
            for(int j = 1; j <= w; ++j) {
                cin >> board[i][j];
                if(board[i][j] == '$') src[srcCnt++] = {i, j};
            }
        }
        for(int i = 0; i <= h + 1; ++i) {
            board[i][0] = '.';
            board[i][w + 1] = '.';
        }
        
        for(int j = 1; j <= w; ++j) {
            board[0][j] = '.';
            board[h + 1][j] = '.';
        }
        
        ans = INF;
        for(int i = 0; i < 3; ++i) dijkstra(i);
        for(int i = 0; i <= h + 1; ++i) {
            for(int j = 0; j <= w + 1; ++j) {
                int sum = check[0][i][j] + check[1][i][j] + check[2][i][j];
                if(board[i][j] == '#') sum -= 2;
                
                ans = min(ans, sum);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}