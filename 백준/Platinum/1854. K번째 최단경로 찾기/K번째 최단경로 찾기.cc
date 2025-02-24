#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
using Pair = pair<int, int>;

constexpr size_t INF = 2'000'000'000;
int n, m, k, a, b, c;
vector<pair<int, int>> graph[1001];
priority_queue<int> dist[1001];

void dijkstra() {
    priority_queue<Pair, vector<Pair>, greater<>> pq;
    for(int i = 2; i <= n; ++i) dist[i].push(INF);
    dist[1].push(0);
    pq.emplace(0, 1);
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for(auto p : graph[cur]) {
            int nxt = p.first;
            int ncost = cost + p.second;
            
            if(dist[nxt].size() < k) {
                dist[nxt].push(ncost);
                pq.emplace(ncost, nxt);
            }
            else if(ncost < dist[nxt].top()) {
                dist[nxt].push(ncost);
                if(dist[nxt].size() > k) dist[nxt].pop();
                pq.emplace(ncost, nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> k;
    while(m--) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }
    
    dijkstra();
    
    for(int i = 1; i <= n; ++i) {
        if(dist[i].size() < k || dist[i].top() == INF) {
            cout << -1 << '\n';
        }
        else {
            cout << dist[i].top() << '\n';
        }
    }
    
    return 0;
}