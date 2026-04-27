#include <iostream>
#include <unordered_map>
using namespace std;

int N, u, v, d;
unordered_map<int, int> graph[300001];
long long dist[300001];
int subnodes[300001];

void dfs(int cur, int prv) {
    subnodes[cur] = 1;
    
    for(auto& p : graph[cur]) {
        int nxt = p.first;
        if(nxt == prv) continue;
        dfs(nxt, cur);
        subnodes[cur] += subnodes[nxt];
    }
    
    dist[1] += (subnodes[cur] * graph[prv][cur]);
}

void dfs2(int cur, int prv) {
    for(auto& p : graph[cur]) {
        int nxt = p.first;
        int cost = p.second;
        if(nxt == prv) continue;
        
        dist[nxt] = dist[cur] - (cost * subnodes[nxt]) + (cost * (N - subnodes[nxt]));
        dfs2(nxt, cur);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N - 1; ++i) {
        cin >> u >> v >> d;
        graph[u].emplace(v, d);
        graph[v].emplace(u, d);
    }
    
    dfs(1, 0);
    dfs2(1, 0);
    for(int i = 1; i <= N; ++i) {
        cout << dist[i] << '\n';
    }
    
    return 0;
}