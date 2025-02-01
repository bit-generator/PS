#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
using Pair = pair<long long, int>;

constexpr long long INF = 92e17;
int N, M, A, B;
vector<pair<int, int>> graph[100001];
long long dist[100001];

void dijkstra() {
    priority_queue<Pair, vector<Pair>, greater<>> pq;
    fill(dist, dist + 100001, INF);
    dist[1] = 0;
    pq.emplace(0, 1);
    
    while(!pq.empty()) {
        long long cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < cost) continue;
        for(auto p : graph[cur]) {
            int nxt = p.first;
            long long ncost = cost / M * M + p.second;
            ncost += (ncost < cost ? M : 0);
            
            if(ncost + 1 < dist[nxt]) {
                dist[nxt] = ncost + 1;
                pq.emplace(ncost + 1, nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        cin >> A >> B;
        graph[A].emplace_back(B, i);
        graph[B].emplace_back(A, i);
    }
    
    dijkstra();
    cout << dist[N];
    return 0;
}