#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T, N, A, B, root, ans;
vector<int> graph[10001];
int depth[10001];
int parent[10001][14];
bool check[10001];

void dfs(int cur) {
    for (int nxt : graph[cur]) {
        depth[nxt] = depth[cur] + 1;
        parent[nxt][0] = cur;

        for (int i = 1; i < 14; ++i) {
            parent[nxt][i] = parent[parent[nxt][i - 1]][i - 1];
        }

        dfs(nxt);
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) {
        int tmp = x;
        x = y;
        y = tmp;
    }

    for (int i = 13; i >= 0; --i) {
        if (depth[parent[x][i]] < depth[y]) continue;
        x = parent[x][i];
    }

    if (x == y) return x;
    int ret;

    for (int i = 13; i >= 0; --i) {
        if (parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }

        ret = parent[x][i];
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            graph[i].clear();
        }
        memset(check, 0, sizeof(check));
        memset(depth, 0, sizeof(depth));
        memset(parent, 0, sizeof(parent));

        for (int i = 0; i < N - 1; ++i) {
            cin >> A >> B;
            graph[A].push_back(B);
            check[B] = true;
        }
        
        for(int i = 1; i <= N; ++i) {
            if(!check[i]) {
                root = i;
                break;
            }
        }

        depth[root] = 1;
        dfs(root);
        cin >> A >> B;
        cout << lca(A, B) << '\n';
    }

    return 0;
}