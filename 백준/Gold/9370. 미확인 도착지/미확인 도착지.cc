#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#define INF    1'000'000'000
using namespace std;
using Pair = pair<int, int>;

int T, n, m, t, s, g, h, a, b, d, X;
vector<pair<int, int>> graph[2001];
int dist1[2001], dist2[2001];
priority_queue<int, vector<int>, greater<>> dest;

void dijkstra(int x, int dist[]) {
    fill(dist + 1, dist + n + 1, INF);
    priority_queue<Pair, vector<Pair>, greater<>> pq;
    pq.emplace(0, x);
    dist[x] = 0;
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < cost) continue;
        for(const auto& p : graph[cur]) {
            int nxt = p.first;
            int ncost = cost + p.second;
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
        cin >> n >> m >> t >> s >> g >> h;
        for(int i = 1; i <= n; ++i) {
            graph[i].clear();
        }
        
        while(m--) {
            cin >> a >> b >> d;
            graph[a].emplace_back(b, d);
            graph[b].emplace_back(a, d);
        }
        
        while(t--) {
            cin >> X;
            dest.push(X);
        }
        
        dijkstra(s, dist1);
        int cen = g;
        if(dist1[g] < dist1[h]) {
            dijkstra(h, dist2);
            cen = h;
        }
        else {
            dijkstra(g, dist2);
        }
        
        while(!dest.empty()) {
            int tmp = dest.top();
            dest.pop();

            if(dist1[cen] + dist2[tmp] == dist1[tmp]) {
                cout << tmp << ' ';
            }
        }
        cout << '\n';
    }
    
    return 0;
}