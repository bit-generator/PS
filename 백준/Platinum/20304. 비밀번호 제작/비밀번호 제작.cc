#include <iostream>
#include <queue>
using namespace std;

int N, M, p, mx, ans;
int tried[1000001];
queue<int> q;

void bfs() {
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans = max(ans, tried[cur] - 1);
        
        for(int i = 0; i <= mx; i++) {
            int nxt = cur ^ (1 << i);
            if(nxt > N || tried[nxt]) continue;
            tried[nxt] = tried[cur] + 1;
            q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(M--) {
        cin >> p;
        q.push(p);
        tried[p] = 1;
    }
    
    int base = 2;
    while(base <= N) {
        base *= 2;
        mx++;
    }
    bfs();
    
    cout << ans;
    return 0;
}