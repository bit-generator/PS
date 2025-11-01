#include <iostream>
#include <queue>
using namespace std;

int N, M, u, v;
int board[101];
int visit[101];

int bfs() {
    queue<int> q;
    q.push(1);
    visit[1] = 1;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int i = 1; i <= 6; ++i) {
            int nxt = board[cur + i];
            if(nxt > 100) continue;
            else if(nxt == 100) {
                return visit[cur];
            }
            
            if(visit[nxt]) continue;
            visit[nxt] = visit[cur] + 1;
            q.push(nxt);
        }
    }
    
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 1; i <= 100; ++i) board[i] = i;
    
    cin >> N >> M;
    for(int i = 0; i < N + M; ++i) {
        cin >> u >> v;
        board[u] = v;
    }
    
    cout << bfs();
    return 0;
}