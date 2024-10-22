#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
using Pair = pair<int, int>;

int N, M, X, A, B, T, ans;
constexpr int INF = 21e8;
vector<Pair> graph[1001], graph_r[1001];
int dist[1001], dist_r[1001];
priority_queue<Pair, vector<Pair>, greater<>> pq;

void dijkstra(int x) {
    fill(dist + 1, dist + N + 1, INF);
    dist[x] = 0;
    pq.emplace(0, x);
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] != cost) continue;
        
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

void dijkstra_r(int x) {
    fill(dist_r + 1, dist_r + N + 1, INF);
    dist_r[x] = 0;
    pq.emplace(0, x);
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist_r[cur] != cost) continue;
        
        for(auto p : graph_r[cur]) {
            int ncost = cost + p.second;
            int nxt = p.first;
            
            if(ncost < dist_r[nxt]) {
                dist_r[nxt] = ncost;
                pq.emplace(ncost, nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> X;
    while(M--) {
        cin >> A >> B >> T;
        graph[A].emplace_back(B, T);
        graph_r[B].emplace_back(A, T);
    }
    
    dijkstra(X);
    dijkstra_r(X);
    
    for(int i = 1; i <= N; i++) {
        ans = max(ans, dist[i] + dist_r[i]);
    }
    
    cout << ans;
    return 0;
}