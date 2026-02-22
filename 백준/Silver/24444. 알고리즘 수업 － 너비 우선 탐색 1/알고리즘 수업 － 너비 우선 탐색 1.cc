#include <iostream>
#include <set>
#include <queue>
using namespace std;

int N, M, R, u, v, orderCnt;
set<int> graph[100001];
int order[100001];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    order[src] = ++orderCnt;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int nxt : graph[cur]) {
            if(order[nxt]) continue;
            q.push(nxt);
            order[nxt] = ++orderCnt;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> R;
    while (M--) {
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    bfs(R);
    for (int i = 1; i <= N; ++i) {
        cout << order[i] << '\n';
    }
    return 0;
}