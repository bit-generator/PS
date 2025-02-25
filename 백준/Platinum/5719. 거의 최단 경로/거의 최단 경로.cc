#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
using Pair = pair<int, int>;

constexpr size_t INF = 2'000'000'000;
int N, M, S, D, U, V, P;
vector<pair<int, int>> graph[500];
int dist[500];
vector<int> prv[500];
bool isPath[500][500];

void dijkstra() {
    priority_queue<Pair, vector<Pair>, greater<>> pq;
    pq.emplace(0, S);
    fill(dist, dist + N, INF);
    dist[S] = 0;

    for (int i = 0; i < N; ++i) prv[i].clear();

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (auto p : graph[cur]) {
            int nxt = p.first;
            int ncost = cost + p.second;
            if (isPath[cur][nxt]) continue;

            if (ncost < dist[nxt]) {
                dist[nxt] = ncost;
                pq.emplace(ncost, nxt);
                prv[nxt].clear();
                prv[nxt].push_back(cur);
            }
            else if (ncost == dist[nxt]) {
                prv[nxt].push_back(cur);
            }
        }
    }
}

void checkPath() {
    queue<int> q;
    q.push(D);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto nxt : prv[cur]) {
            if (isPath[nxt][cur]) continue;
            isPath[nxt][cur] = true;
            q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        cin >> S >> D;
        for (int i = 0; i < N; ++i) {
            graph[i].clear();
        }

        while (M--) {
            cin >> U >> V >> P;
            graph[U].emplace_back(V, P);
        }

        for (int i = 0; i < N; ++i) {
            memset(isPath[i], 0, N);
        }
        dijkstra();
        checkPath();
        dijkstra();
        if (dist[D] == INF) cout << -1 << '\n';
        else cout << dist[D] << '\n';
    }

    return 0;
}