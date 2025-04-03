#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
#define INF    21e8
using namespace std;
using Tuple = tuple<int, int, int>;

int N, M, a, b, c, ans = INF;
int price[2501];
vector<pair<int, int>> graph[2501];
int dist[2501][2501];

void dijkstra() {
    priority_queue<Tuple, vector<Tuple>, greater<>> pq;
    for (int i = 1; i <= N; ++i) {
        fill(dist[i] + 1, dist[i] + N + 1, INF);
    }
    pq.emplace(0, 1, 1);
    dist[1][1] = 0;

    while (!pq.empty()) {
        int cur, ref, cost;
        tie(cost, cur, ref) = pq.top();
        pq.pop();

        if (dist[cur][ref] < cost) continue;
        if (price[cur] < price[ref]) ref = cur;

        for (const auto& p : graph[cur]) {
            int nxt = p.first;
            int ncost = p.second * price[ref] + cost;

            if (ncost < dist[nxt][ref]) {
                dist[nxt][ref] = ncost;
                pq.emplace(ncost, nxt, ref);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> price[i];
    while (M--) {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    dijkstra();
    for (int i = 1; i <= N; ++i) {
        ans = min(ans, dist[N][i]);
    }

    cout << ans;
    return 0;
}