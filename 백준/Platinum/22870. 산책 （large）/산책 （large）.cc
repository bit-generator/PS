#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
using Pair = pair<int, int>;

constexpr size_t INF = 2'100'000'000;
int N, M, A, B, C, S, E, ans;
vector<Pair> graph[200001];
int dist[200001];
int prv[200001];
bool shortest[200001];

void dijkstra() {
    priority_queue<Pair, vector<Pair>, greater<>> pq;
    fill(dist, dist + N + 1, INF);
    dist[E] = 0;
    pq.emplace(0, E);
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < cost) continue;
        
        for(auto p : graph[cur]) {
            int nxt = p.first;
            int ncost = p.second + cost;
            if(shortest[nxt]) continue;
            
            if(ncost < dist[nxt]) {
                dist[nxt] = ncost;
                prv[nxt] = cur;
                pq.emplace(ncost, nxt);
            }
            else if(ncost == dist[nxt]) {
                prv[nxt] = min(prv[nxt], cur);
            }
        }
    }
}

void checkPath() {
    int cur = S;
    while(cur != E) {
        shortest[prv[cur]] = true;
        cur = prv[cur];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(M--) {
        cin >> A >> B >> C;
        graph[A].emplace_back(B, C);
        graph[B].emplace_back(A, C);
    }
    
    cin >> S >> E;
    
    fill(prv, prv + N + 1, INF);
    dijkstra();
    ans += dist[S];
    checkPath();
    dijkstra();
    ans += dist[S];
    
    cout << ans;
    return 0;
}