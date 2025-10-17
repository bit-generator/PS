#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
using pii = pair<int, int>;

int V, E, A, B;
vector<int> graph[10001], reversed[10001];
vector<int> st;
priority_queue<int, vector<int>, greater<>> scc[10000];
priority_queue<pii, vector<pii>, greater<>> pq;
int scc_cnt = 0;
bool visit[10001];

void dfs(int cur) {
    visit[cur] = true;
    
    for(int nxt : graph[cur]) {
        if(visit[nxt]) continue;
        dfs(nxt);
    }
    
    st.push_back(cur);
}

void revdfs(int cur) {
    visit[cur] = true;
    scc[scc_cnt].push(cur);
    
    for(int nxt : reversed[cur]) {
        if(visit[nxt]) continue;
        revdfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> V >> E;
    while(E--) {
        cin >> A >> B;
        graph[A].push_back(B);
        reversed[B].push_back(A);
    }
    
    for(int i = 1; i <= V; ++i) {
        if(visit[i]) continue;
        dfs(i);
    }
    
    memset(visit, 0, sizeof(visit));
    while(!st.empty()) {
        int cur = st.back();
        st.pop_back();
        if(visit[cur]) continue;
        
        revdfs(cur);
        pq.emplace(scc[scc_cnt].top(), scc_cnt);
        ++scc_cnt;
    }
    
    cout << scc_cnt << '\n';
    while(!pq.empty()) {
        int idx = pq.top().second;
        pq.pop();
        
        while(!scc[idx].empty()) {
            cout << scc[idx].top() << ' ';
            scc[idx].pop();
        }
        
        cout << -1 << '\n';
    }
    
    return 0;
}