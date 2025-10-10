#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b;
vector<int> graph[10001];
int w[10001];
int dp[10001][2];
vector<int> path;
bool check[10001];

void dfs(int cur, int prv) {
    for(int nxt : graph[cur]) {
        if(nxt == prv) continue;
        dfs(nxt, cur);
        
        if(dp[nxt][0] < dp[nxt][1]) {
            dp[cur][0] += dp[nxt][1];
        }
        else {
            dp[cur][0] += dp[nxt][0];
        }
        
        dp[cur][1] += dp[nxt][0];
    }
    
    dp[cur][1] += w[cur];
}

void getPath(int cur, int prv) {
    if(dp[cur][0] < dp[cur][1] && !check[prv]) {
        path.push_back(cur);
        check[cur] = true;
    }
    
    for(int nxt : graph[cur]) {
        if(nxt == prv) continue;
        getPath(nxt, cur);
    }
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
    getPath(1, 0);
    sort(path.begin(), path.end());
    
    cout << max(dp[1][0], dp[1][1]) << '\n';
    for(int i : path) cout << i << ' ';
    return 0;
}