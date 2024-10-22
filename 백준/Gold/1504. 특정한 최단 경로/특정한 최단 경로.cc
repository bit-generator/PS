#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
using Pair = pair<int, int>;

int N, E, a, b, c, v1, v2;
constexpr int INF = 21e7;
vector<Pair> graph[801];
int dist1[801], dist2[801];
priority_queue<Pair, vector<Pair>, greater<>> pq;

void dijkstra(int x, int dist[]) {
    fill(dist + 1, dist + N + 1, INF);
    dist[x] = 0;
    pq.emplace(0, x);
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(cost != dist[cur]) continue;
        
        for(auto p : graph[cur]) {
            int ncost = cost + p.second;
            int nxt = p.first;
            if(ncost < dist[nxt]) {
                dist[nxt] = ncost;
                pq.emplace(ncost, nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> E;
    while(E--) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    
    cin >> v1 >> v2;
    dijkstra(v1, dist1);
    dijkstra(v2, dist2);
    
    int distV = dist1[v2];
    int ans = min(dist1[1] + dist2[N] + distV, dist2[1] + dist1[N] + distV);
    if(ans >= INF) cout << -1;
    else cout << ans;
    
    return 0;
}