#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using Tuple = tuple<long long, int, int>;

constexpr long long INF = 1'000'000'000'000'000'000;
int N, M, K, a, b, c;
vector<pair<int, int>> graph[10001];
long long dist[10001][21];
long long ans;

void dijkstra() {
    priority_queue<Tuple, vector<Tuple>, greater<>> pq;
    for(int i = 2; i <= N; ++i) {
        fill(dist[i], dist[i] + K + 1, INF);
    }
    pq.emplace(0, 1, 0);
    
    while(!pq.empty()) {
        long long cost;
        int cur, paved;
        tie(cost, cur, paved) = pq.top();
        pq.pop();
        
        if(dist[cur][paved] < cost) continue;
        
        for(auto p : graph[cur]) {
            int nxt = p.first;
            
            if(paved < K && cost < dist[nxt][paved + 1]) {
                dist[nxt][paved + 1] = cost;
                pq.emplace(cost, nxt, paved + 1);
            }
            
            if(cost + p.second < dist[nxt][paved]) {
                dist[nxt][paved] = cost + p.second;
                pq.emplace(cost + p.second, nxt, paved);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> K;
    while(M--) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    
    dijkstra();
    ans = dist[N][0];
    for(int i = 1; i <= K; ++i) {
        if(dist[N][i] < ans) ans = dist[N][i];
    }
    
    cout << ans;
    return 0;
}