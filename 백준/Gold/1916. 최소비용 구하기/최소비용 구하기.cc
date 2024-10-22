#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
using Pair = pair<int, int>;

int N, M, A, B, C, src, dest;
vector<Pair> graph[1001];
int dist[1001];
priority_queue<Pair, vector<Pair>, greater<>> pq;

void dijkstra(int x) {
    fill(dist + 1, dist + N + 1, 21e8);
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(M--) {
        cin >> A >> B >> C;
        graph[A].emplace_back(B, C);
    }
    
    cin >> src >> dest;
    dijkstra(src);
    cout << dist[dest];
    return 0;
}