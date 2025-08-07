#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#define INF    1'000'000'000
using namespace std;
using Tuple = tuple<int, int, int>;

int T, N, M, K, u, v, c, d, ans = INF;
vector<Tuple> graph[101];
int dist[101][10001];

void dijkstra() {
    priority_queue<Tuple, vector<Tuple>, greater<>> pq;
    for(int i = 2; i <= N; ++i) {
        fill(dist[i], dist[i] + 10001, INF);
    }
    
    pq.emplace(0, 0, 1);
    
    while(!pq.empty()) {
        int cdist, cost, cur;
        tie(cdist, cost, cur) = pq.top();
        pq.pop();
        
        if(dist[cur][cost] < cdist) continue;
        
        for(const auto& tp : graph[cur]) {
            int nxt, ncost, ndist;
            tie(ndist, ncost, nxt) = tp;
            ncost += cost;
            if(ncost > M) continue;
            
            ndist += cdist;
            
            if(ndist < dist[nxt][ncost]) {
                for(int i = ncost; i <= M; ++i) {
                    if(dist[nxt][i] <= ndist) break;
                    dist[nxt][i] = ndist;
                }
                
                pq.emplace(ndist, ncost, nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> N >> M >> K;
        while(K--) {
            cin >> u >> v >> c >> d;
            graph[u].emplace_back(d, c, v);
        }
        
        for(int i = 1; i <= N; ++i) {
            sort(graph[i].begin(), graph[i].end());
        }
        
        dijkstra();
        for(int i = 0; i <= 10000; ++i) {
            ans = min(ans, dist[N][i]);
        }
        
        if(ans == INF) cout << "Poor KCM";
        else cout << ans;
    }
    
    return 0;
}