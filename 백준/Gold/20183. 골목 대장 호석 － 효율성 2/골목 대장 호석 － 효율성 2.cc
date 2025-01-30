#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using Pair = pair<int, int>;

constexpr long long INF = (long long)92e17;
int N, M, A, B, C, u, v, w, ans = -1;
vector<pair<int, int>> graph[100001];
long long dist[100001];

void dijkstra(int target) {
    priority_queue<Pair, vector<Pair>, greater<>> pq;
    fill(dist, dist + N + 1, INF);
    dist[A] = 0;
    pq.emplace(0, A);
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < cost) continue;
        
        for(auto p : graph[cur]) {
            int nxt = p.first;
            int ncost = p.second + cost;
            if(p.second > target || ncost > C) continue;
            
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
    
    cin >> N >> M >> A >> B >> C;
    while(M--) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    
    int start = 1, last = 1'000'000'000;
    while(start <= last) {
        int mid = (start + last) / 2;
        dijkstra(mid);
        if(dist[B] != INF) {
            ans = mid;
            last = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    
    cout << ans;
    return 0;
}