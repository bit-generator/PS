#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using Tuple = tuple<int, int, int>;

int M, N;
constexpr int INF = 21e8;
char maze[100][100];
int dist[100][100];
priority_queue<Tuple, vector<Tuple>, greater<>> pq;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool validRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void dijkstra(int x, int y) {
    for(int i = 0; i < N; i++) {
        fill(dist[i], dist[i] + M, INF);
    }
    dist[x][y] = 0;
    pq.emplace(0, x, y);
    
    while(!pq.empty()) {
        int curx, cury, cost;
        tie(cost, curx, cury) = pq.top();
        pq.pop();
        if(dist[curx][cury] != cost) continue;
        
        for(int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny)) continue;
            
            int ncost = maze[nx][ny] == '1' ? cost + 1 : cost;
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
    
    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> maze[i][j];
        }
    }
    
    dijkstra(0, 0);
    cout << dist[N - 1][M - 1];
    return 0;
}