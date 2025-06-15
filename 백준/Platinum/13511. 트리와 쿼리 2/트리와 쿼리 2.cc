#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, M, u, v, cmd, w, k;
long long pathCost;
vector<pair<int, int>> graph[100001];
int depth[100001];
int parent[100001][17];
long long price[100001][17];

void dfs(int cur, int prv) {
    for(const auto& p : graph[cur]) {
        int nxt = p.first;
        int cost = p.second;
        if(nxt == prv) continue;
        
        depth[nxt] = depth[cur] + 1;
        parent[nxt][0] = cur;
        price[nxt][0] = cost;
        
        for(int i = 1; i < 17; ++i) {
            parent[nxt][i] = parent[parent[nxt][i - 1]][i - 1];
            price[nxt][i] = price[nxt][i - 1] + price[parent[nxt][i - 1]][i - 1];
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
    
    pathCost = 0;
    
    for(int i = 16; i >= 0; --i) {
        if(depth[parent[x][i]] < depth[y]) continue;
        pathCost += price[x][i];
        x = parent[x][i];
    }
    
    if(x == y) return x;
    int ret;
    
    for(int i = 16; i >= 0; --i) {
        if(parent[x][i] != parent[y][i]) {
            pathCost += (price[x][i] + price[y][i]);
            x = parent[x][i];
            y = parent[y][i];
        }
        
        ret = parent[x][i];
    }
    
    pathCost += (price[x][0] + price[y][0]);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N - 1; ++i) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    
    depth[1] = 1;
    dfs(1, 0);
    
    cin >> M;
    while(M--) {
        cin >> cmd;
        if(cmd == 1) {
            cin >> u >> v;
            lca(u, v);
            cout << pathCost << '\n';
        }
        else {
            cin >> u >> v >> k;
            int mid = lca(u, v);
            int ans;
            if(--k <= depth[u] - depth[mid]) {
                ans = u;
                for(int i = 16; i >= 0; --i) {
                    if((1 << i) > k) continue;
                    k -= (1 << i);
                    ans = parent[ans][i];
                }
            }
            else {
                ans = v;
                k = (depth[u] - depth[mid]) + (depth[v] - depth[mid]) - k;
                for(int i = 16; i >= 0; --i) {
                    if((1 << i) > k) continue;
                    k -= (1 << i);
                    ans = parent[ans][i];
                }
            }
            
            cout << ans << '\n';
        }
    }
    
    return 0;
}