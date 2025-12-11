#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#define INF    1'000'000'000
using namespace std;
using pii = pair<int, int>;

int N, D, a, b, c;
unordered_map<int, int> graph[10001];
set<int> s;
int dist[10001];

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<>> pq;
    fill(dist, dist + D + 1, INF);
    dist[0] = 0;
    pq.emplace(0, 0);
    
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
    
    cin >> N >> D;
    while(N--) {
        cin >> a >> b >> c;
        if(b - a <= c) continue;
        if(a > D || b > D) continue;
        s.insert(a);
        s.insert(b);
        if(graph[a].find(b) == graph[a].end() || graph[a][b] > c) {
            graph[a][b] = c;
        }
    }
    s.insert(0);
    s.insert(D);
    
    auto it = s.begin();
    int prv = *(it++);
    for( ; it != s.end(); ++it) {
        int cur = (*it);
        if(graph[prv].find(cur) == graph[prv].end() || graph[prv][cur] > cur - prv) {
            graph[prv][cur] = cur - prv;
        }
        
        prv = cur;
    }
    
    dijkstra();
    cout << dist[D];
    return 0;
}