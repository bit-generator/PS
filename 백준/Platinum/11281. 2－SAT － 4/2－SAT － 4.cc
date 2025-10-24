#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <cstring>
#define OFFSET    100000
using namespace std;

int N, M, A, B, idCnt;
vector<int> graph[200001];
unordered_set<int> newgraph[200001];
vector<int> st;
vector<int> SCC[200001];
int id[200001], parent[200001], indegree[200001], ans[200001];
bool fin[200001], realparent[200001], visit[200001];
queue<int> q;

int dfs(int cur) {
    id[cur] = ++idCnt;
    st.push_back(cur);
    
    int p = id[cur];
    for(int nxt : graph[cur]) {
        if(id[nxt] == 0) p = min(p, dfs(nxt));
        else if(!fin[nxt]) p = min(p, id[nxt]);
    }
    
    if(p == id[cur]) {
        realparent[cur] = true;
        
        while(!st.empty()) {
            int tmp = st.back();
            st.pop_back();
            
            parent[tmp] = cur;
            SCC[cur].push_back(tmp);
            fin[tmp] = true;
            if(tmp == cur) break;
        }
    }
    
    return p;
}

void topologicalSort() {
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        visit[cur] = true;
        for(int scc : SCC[cur]) {
            int rev = (scc - OFFSET) * (-1) + OFFSET;
            if(ans[scc] == -1) {
                ans[scc] = 0;
                ans[rev] = 1;
            }
        }
        
        for(int nxt : newgraph[cur]) {
            if(visit[nxt]) continue;
            if(--indegree[nxt] == 0) q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        cin >> A >> B;
        graph[A * (-1) + OFFSET].push_back(B + OFFSET);
        graph[B * (-1) + OFFSET].push_back(A + OFFSET);
    }
    
    for(int i = N * (-1) + OFFSET; i <= N + OFFSET; ++i) {
        if(fin[i]) continue;
        dfs(i);
    }
    
    for(int i = 1; i <= N; ++i) {
        if(parent[i * (-1) + OFFSET] == parent[i + OFFSET]) {
            cout << 0;
            return 0;
        }
    }
    
    for(int i = N * (-1) + OFFSET; i <= N + OFFSET; ++i) {
        for(int j : graph[i]) {
            int a = parent[i];
            int b = parent[j];
            if(a == b || newgraph[a].find(b) != newgraph[a].end()) continue;
            newgraph[a].insert(b);
            ++indegree[b];
        }
    }
    
    for(int i = N * (-1) + OFFSET; i <= N + OFFSET; ++i) {
        if(!indegree[i] && realparent[i]) q.push(i);
    }
    
    memset(ans, -1, sizeof(ans));
    topologicalSort();
    
    cout << 1 << '\n';
    for(int i = 1; i <= N; ++i) {
        cout << ans[i + OFFSET] << ' ';
    }
    
    return 0;
}