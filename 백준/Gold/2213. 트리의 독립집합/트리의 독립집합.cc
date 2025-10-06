#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b;
vector<int> graph[10001];
int w[10001];
int dp[10001][2];
vector<int> path[10001][2];

void dfs(int cur, int prv) {
    for(int nxt : graph[cur]) {
        if(nxt == prv) continue;
        dfs(nxt, cur);
        
        if(dp[nxt][0] < dp[nxt][1]) {
            dp[cur][0] += dp[nxt][1];
            path[cur][0].insert(path[cur][0].end(), path[nxt][1].begin(), path[nxt][1].end());
        }
        else {
            dp[cur][0] += dp[nxt][0];
            path[cur][0].insert(path[cur][0].end(), path[nxt][0].begin(), path[nxt][0].end());
        }
        
        dp[cur][1] += dp[nxt][0];
        path[cur][1].insert(path[cur][1].end(), path[nxt][0].begin(), path[nxt][0].end());
    }
    
    dp[cur][1] += w[cur];
    path[cur][1].push_back(cur);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> w[i];
    for(int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1, 0);
    if(dp[1][0] < dp[1][1]) {
        cout << dp[1][1] << '\n';
        sort(path[1][1].begin(), path[1][1].end());
        for(int i : path[1][1]) cout << i << ' ';
    }
    else {
        cout << dp[1][0] << '\n';
        sort(path[1][0].begin(), path[1][0].end());
        for(int i : path[1][0]) cout << i << ' ';
    }
    return 0;
}