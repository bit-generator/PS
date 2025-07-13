#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
#define INF    1'000'000'000
using namespace std;

struct Node {
    int x, y;
    int dir;
    int cost;
    
    bool operator<(const Node& a) const {
        return this->cost > a.cost;
    }
};

int W, H, ans = INF;
vector<pair<int, int>> pos;
char board[100][100];
int cnt[4][100][100];
priority_queue<Node> pq;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool validRange(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W;
}

void dijkstra() {
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < H; ++j) {
            fill(cnt[i][j], cnt[i][j] + W, INF);
        }
    }
    
    for(int i = 0; i < 4; ++i) {
        cnt[i][pos[0].first][pos[0].second] = 0;
        pq.push({pos[0].first, pos[0].second, i, 0});
    }
    
    while(!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        
        if(cnt[cur.dir][cur.x][cur.y] < cur.cost) continue;
        for(int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(!validRange(nx, ny) || board[nx][ny] == '*') continue;
            
            int ncost = cur.cost + (cur.dir != i);
            if(ncost < cnt[i][nx][ny]) {
                cnt[i][nx][ny] = ncost;
                pq.push({nx, ny, i, ncost});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> W >> H;
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cin >> board[i][j];
            if(board[i][j] == 'C') pos.emplace_back(i, j);
        }
    }
    
    dijkstra();
    for(int i = 0; i < 4; ++i) {
        ans = min(ans, cnt[i][pos[1].first][pos[1].second]);
    }
    
    cout << ans;
    return 0;
}