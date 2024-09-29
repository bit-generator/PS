#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int K, V, E, u, v;
vector<int> graph[20001];
int visit[20001];
bool isBipartite;

void dfs(int x, int step) {
    for (int nxt : graph[x]) {
        if (visit[nxt] == 0) {
            visit[nxt] = step * -1;
            dfs(nxt, step * -1);

            if (!isBipartite) return;
        }
        else if (visit[nxt] == step) {
            isBipartite = false;
            return;
        }
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;
    while (K--) {
        cin >> V >> E;
        for (int i = 0; i <= 20000; i++) {
            graph[i].clear();
        }
        memset(visit, 0, sizeof(int) * (V + 1));
        isBipartite = true;

        while (E--) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        if (V == 1) {
            cout << "NO\n";
            continue;
        }

        for (int i = 1; i <= V; i++) {
            if (visit[i] != 0) continue;

            visit[i] = 1;
            dfs(i, 1);
        }

        if (isBipartite) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}