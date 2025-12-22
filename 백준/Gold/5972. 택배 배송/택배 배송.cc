#include <iostream>
#include <utility>
#include <queue>
#include <unordered_map>
#include <algorithm>
#define INF    1'000'000'000
using namespace std;
using pii = pair<int, int>;

int N, M, A, B, C;
unordered_map<int, int> graph[50001];
priority_queue<pii, vector<pii>, greater<>> pq;
int dist[50001];

void dijkstra() {
    fill(dist + 1, dist + N + 1, INF);
    dist[1] = 0;
    pq.emplace(0, 1);
    
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
    
    cin >> N >> M;
    while(M--) {
        cin >> A >> B >> C;
        if(graph[A].find(B) == graph[A].end()) graph[A].emplace(B, C);
        else graph[A][B] = min(graph[A][B], C);
        if(graph[B].find(A) == graph[B].end()) graph[B].emplace(A, C);
        else graph[B][A] = min(graph[B][A], C);
    }
    
    dijkstra();
    cout << dist[N];
    return 0;
}