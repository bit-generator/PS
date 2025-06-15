#include <iostream>
#include <vector>
using namespace std;

int N, M, a, b;
vector<int> graph[100001];
int depth[100001];
int dp[100001][17];

void dfs(int cur, int prv) {
    for(int nxt : graph[cur]) {
        if(nxt == prv) continue;
        depth[nxt] = depth[cur] + 1;
        dp[nxt][0] = cur;
        
        for(int i = 1; i < 17; ++i) {
            dp[nxt][i] = dp[dp[nxt][i - 1]][i - 1];
        }
        
        dfs(nxt, cur);
    }
}

int lca(int x, int y) {
    if(depth[x] < depth[y]) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    
    for(int i = 16; i >= 0; --i) {
        if(depth[dp[x][i]] < depth[y]) continue;
        x = dp[x][i];
    }
    
    if(x == y) return x;
    int ret;
    
    for(int i = 16; i >= 0; --i) {
        if(dp[x][i] != dp[y][i]) {
            x = dp[x][i];
            y = dp[y][i];
        }
        
        ret = dp[x][i];
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N - 1; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    depth[1] = 1;
    dfs(1, 0);
    
    cin >> M;
    while(M--) {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    
    return 0;
}