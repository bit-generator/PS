#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using Pair = pair<long long, int>;

constexpr long long INF = 10e15;
int N, M, K, U, V, C;
vector<pair<int, int>> graph[100001];
priority_queue<Pair, vector<Pair>, greater<>> pq;
long long dist[100001];

void dijkstra(int x) {
    fill(dist, dist + N + 1, INF);
    dist[x] = 0;
    pq.emplace(0, x);
    
    while(!pq.empty()) {
        long long cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < cost) continue;
        
        for(auto p : graph[cur]) {
            int nxt = p.first;
            long long ncost = cost + p.second;
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
    
    cin >> N >> M >> K;
    while(M--) {
        cin >> U >> V >> C;
        graph[V].emplace_back(U, C);
    }
    
    while(K--) {
        cin >> U;
        graph[0].emplace_back(U, 0);
    }
    
    dijkstra(0);
    
    int farCity = 100001;
    long long ans = -1;
    for(int i = 1; i <= N; ++i) {
        if(dist[i] > ans) {
            ans = dist[i];
            farCity = i;
        }
    }
    
    cout << farCity << '\n' << ans;
    return 0;
}