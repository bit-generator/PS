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
vector<int> order;

void init(vector<vector<int>>& graph) {
    queue<int> q;
    q.push(1);
    order.clear();
    ans = 0;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        order.push_back(cur);

        for (int nxt : graph[cur]) {
            for (int i = 1; i < 18; i++) {
                LCA[nxt][i] = LCA[LCA[nxt][i - 1]][i - 1];
            }

            depth[nxt] = depth[cur] + 1;
            q.push(nxt);
        }
    }
}

int getLCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    if (depth[a] != depth[b]) {
        for (int i = 17; i >= 0; i--) {
            if (depth[LCA[a][i]] >= depth[b]) {
                a = LCA[a][i];
            }
        }
    }
    
    if (a == b) return a;

    int ret = 0;

    for (int i = 17; i >= 0; i--) {
        if (LCA[a][i] != LCA[b][i]) {
            a = LCA[a][i];
            b = LCA[b][i];
        }

        ret = LCA[a][i];
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;

        vector<vector<int>> graph(100001);

        for (int i = 2; i <= N; i++) {
            cin >> P;
            LCA[i][0] = P;
            graph[P].push_back(i);
        }

        init(graph);
        
        for (int i = 1; i < order.size(); i++) {
            ans += (depth[order[i - 1]] + depth[order[i]] - 2 * depth[getLCA(order[i - 1], order[i])]);
        }

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}