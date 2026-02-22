#include <iostream>
#include <set>
using namespace std;

int N, M, R, u, v, orderCnt;
set<int, greater<>> graph[100001];
int order[100001];

void dfs(int cur) {
    order[cur] = ++orderCnt;
    
    for(int nxt : graph[cur]) {
        if(order[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> R;
    while(M--) {
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    
    dfs(R);
    for(int i = 1; i <= N; ++i) {
        cout << order[i] << '\n';
    }
    return 0;
}