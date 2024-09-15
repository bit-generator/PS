#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int T, N, P;
long long ans;
int depth[100001];
int LCA[100001][18];

void init(vector<vector<int>>& graph) {
    queue<pair<int, int>> q;
    q.emplace(1, 0);
    
    while (!q.empty()) {
        int cur = q.front().first;
        int prv = q.front().second;
        q.pop();

        for (int nxt : graph[cur]) {
            if (nxt == prv) continue;

            for (int i = 1; i < 18; i++) {
                LCA[nxt][i] = LCA[LCA[nxt][i - 1]][i - 1];
            }

            depth[nxt] = depth[cur] + 1;
            q.emplace(nxt, cur);
        }
    }
}

int getDistance(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    int ret = 0;

    if (depth[a] != depth[b]) {
        for (int i = 17; i >= 0; i--) {
            if (depth[a] - (1 << i) >= depth[b]) {
                a = LCA[a][i];
                ret += (1 << i);
            }
        }
    }
    
    if (a == b) return ret;

    for (int i = 17; i >= 0; i--) {
        if (LCA[a][i] != LCA[b][i]) {
            a = LCA[a][i];
            b = LCA[b][i];
            ret += (2 * (1 << i));
        }
    }
    
    ret += 2;
    return ret;
}

void bfs(vector<vector<int>>& graph) {
    queue<pair<int, int>> q;
    q.emplace(1, 0);
    int prvNode = 1;
    
    while (!q.empty()) {
        int cur = q.front().first;
        int prev = q.front().second;
        q.pop();

        for (int nxt : graph[cur]) {
            if (nxt == prev) continue;

            ans += getDistance(prvNode, nxt);
            q.emplace(nxt, cur);
            prvNode = nxt;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;

        vector<vector<int>> graph(100001);
        ans = 0;

        for (int i = 2; i <= N; i++) {
            cin >> P;
            LCA[i][0] = P;
            graph[i].push_back(P);
            graph[P].push_back(i);
        }

        init(graph);
        bfs(graph);

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}