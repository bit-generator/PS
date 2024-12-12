#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M, K, u, v, w, supply, ans;
bool power[1001];
int parent[1001];
vector<tuple<int, int, int>> edges;

int Find(int x) {
    if (parent[x] == x) return x;
    return x = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    while (K--) {
        cin >> u;
        power[u] = true;
        ++supply;
    }

    while (M--) {
        cin >> u >> v >> w;
        edges.emplace_back(w, u, v);
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= N; ++i) parent[i] = i;
    int i = 0;
    while (supply < N && i < edges.size()) {
        int cost, a, b;
        tie(cost, a, b) = edges[i++];
        int pa = Find(a), pb = Find(b);
        if (pa == pb || power[pa] && power[pb]) continue;

        if (power[pa] || power[pb]) {
            power[pa] = true;
            power[pb] = true;
            ++supply;
        }

        Union(a, b);
        ans += cost;
    }

    cout << ans;
    return 0;
}