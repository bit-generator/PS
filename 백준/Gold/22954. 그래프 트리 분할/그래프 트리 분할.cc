#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <utility>
#include <cstring>
using namespace std;
using vumii = vector<unordered_map<int, int>>;

int N, M, u, v, treeCnt;
vector<unordered_map<int, int>> graph(100001), newgraph(100001);
bool visit[100001], isLeaf[100001];
priority_queue<int, vector<int>, greater<>> pq[2][2];

void bfs(vumii& grp, vumii& newgrp, int src, int idx) {
    queue<int> q;
    q.push(src);
    visit[src] = true;
    pq[idx][0].push(src);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        int cnt = 0;
        
        for(const auto& p : grp[cur]) {
            int nxt = p.first;
            int edge = p.second;
            if(visit[nxt]) continue;
            
            q.push(nxt);
            visit[nxt] = true;
            ++cnt;
            pq[idx][0].push(nxt);
            pq[idx][1].push(edge);
            newgrp[cur][nxt] = edge;
            newgrp[nxt][cur] = edge;
        }
        
        if(!cnt) isLeaf[cur] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 1; i <= M; ++i) {
        cin >> u >> v;
        graph[u][v] = i;
        graph[v][u] = i;
    }
    
    if(N <= 2) {
        cout << -1;
        return 0;
    }
    
    for(int i = 1; i <= N; ++i) {
        if(visit[i]) continue;
        if(treeCnt >= 2) {
            cout << -1;
            return 0;
        }
        
        bfs(graph, newgraph, i, treeCnt++);
    }
    
    if(treeCnt == 2 && pq[0][0].size() == pq[1][0].size()) {
        cout << -1;
        return 0;
    }
    
    if(treeCnt == 1) {
        for(int i = 1; i <= N; ++i) {
            if(isLeaf[i]) {
                int node = (newgraph[i].begin())->first;
                newgraph[node].erase(i);
                newgraph[i].erase(node);
                while(!pq[0][0].empty()) pq[0][0].pop();
                while(!pq[0][1].empty()) pq[0][1].pop();
                memset(visit, 0, sizeof(visit));
                bfs(newgraph, graph, i, 0);
                bfs(newgraph, graph, node, 1);
                break;
            }
        }
    }
    
    cout << pq[0][0].size() << ' ' << pq[1][0].size() << '\n';
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            while(!pq[i][j].empty()) {
                cout << pq[i][j].top() << ' ';
                pq[i][j].pop();
            }
            cout << '\n';
        }
    }
    
    return 0;
}