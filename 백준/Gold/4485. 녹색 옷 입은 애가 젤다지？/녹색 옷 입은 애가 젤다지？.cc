#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
using tiii = tuple<int, int, int>;

constexpr int INF = 1'000'000'000;
int N;
int board[125][125];
int dist[125][125];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

inline bool validRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void dijkstra() {
    priority_queue<tiii, vector<tiii>, greater<>> pq;
    for(int i = 0; i < N; ++i) {
        fill(dist[i], dist[i] + N, INF);
    }
    dist[0][0] = board[0][0];
    pq.emplace(board[0][0], 0, 0);
    
    while(!pq.empty()) {
        int cost, curx, cury;
        tie(cost, curx, cury) = pq.top();
        pq.pop();
        
        if(dist[curx][cury] < cost) continue;
        
        for(int i = 0; i < 4; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny)) continue;
            
            int ncost = cost + board[nx][ny];
            if(ncost < dist[nx][ny]) {
                dist[nx][ny] = ncost;
                pq.emplace(ncost, nx, ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int tc = 1; ; ++tc) {
        cin >> N;
        if(N == 0) break;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                cin >> board[i][j];
            }
        }
        
        dijkstra();
        cout << "Problem " << tc << ": " << dist[N - 1][N - 1] << '\n';
    }
    
    return 0;
}