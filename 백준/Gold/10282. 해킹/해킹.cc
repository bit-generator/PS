#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define INF    1'000'000'000
using namespace std;
using Pair = pair<int, int>;

int T, n, d, c, a, b, s, infected, maxDist;
vector<pair<int, int>> graph[10001];
int dist[10001];

void dijkstra() {
    fill(dist + 1, dist + n + 1, INF);
    
    priority_queue<Pair, vector<Pair>, greater<>> pq;
    pq.emplace(0, c);
    dist[c] = 0;
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < cost) continue;
        
        for(const auto& p : graph[cur]) {
            int nxt = p.first;
            int ncost = p.second + cost;
            
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
    
    cin >> T;
    while(T--) {
        cin >> n >> d >> c;
        for(int i = 1; i <= n; ++i) {
            graph[i].clear();
        }
        infected = 0;
        maxDist = 0;
        
        while(d--) {
            cin >> a >> b >> s;
            graph[b].emplace_back(a, s);
        }
        
        dijkstra();
        for(int i = 1; i <= n; ++i) {
            if(dist[i] == INF) continue;
            ++infected;
            maxDist = max(maxDist, dist[i]);
        }
        
        cout << infected << ' ' << maxDist << '\n';
    }
    
    return 0;
}