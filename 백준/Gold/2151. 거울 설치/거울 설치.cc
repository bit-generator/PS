#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <tuple>
#include <algorithm>
#define INF    1'000'000'000
using namespace std;
using Tuple = tuple<int, int, int, int>;

int N, ans = INF;
char board[50][50];
int dist[4][50][50];
vector<pair<int, int>> node;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool validRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void dijkstra() {
    priority_queue<Tuple, vector<Tuple>, greater<>> pq;
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < N; ++j) {
            fill(dist[i][j], dist[i][j] + N, INF);
        }
    }
    
    for(int i = 0; i < 4; ++i) {
        pq.emplace(0, node[0].first, node[0].second, i);
        dist[i][node[0].first][node[0].second] = 0;
    }
    
    while(!pq.empty()) {
        int curx, cury, cost, dir;
        tie(cost, curx, cury, dir) = pq.top();
        pq.pop();
        
        do {
            curx += dx[dir];
            cury += dy[dir];
        } while(validRange(curx, cury) && board[curx][cury] == '.');
        if(!validRange(curx, cury) || board[curx][cury] == '*') continue;
        
        if(cost < dist[dir][curx][cury]) {
            dist[dir][curx][cury] = cost;
            if(board[curx][cury] == '!') {
                for(int i = 3; i <= 5; ++i) {
                    int ndir = (dir + i) % 4;
                    if(dir != ndir) pq.emplace(cost + 1, curx, cury, ndir);
                    else pq.emplace(cost, curx, cury, ndir);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> board[i][j];
            if(board[i][j] == '#') {
                node.emplace_back(i, j);
            }
        }
    }
    
    dijkstra();
    for(int i = 0; i < 4; ++i) ans = min(ans, dist[i][node[1].first][node[1].second]);
    cout << ans;
    return 0;
}