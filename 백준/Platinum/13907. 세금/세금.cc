#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
using Tuple = tuple<long long, int, int>;

constexpr long long INF = 1'000'000'000'000'000'000;
int N, M, K, S, D, a, b, w, p;
long long ans = INF;
vector<pair<int, int>> graph[1001];
long long dist[1001];
long long pathCnt[1001];
long long dp[1000];

void dijkstra() {
    priority_queue<Tuple, vector<Tuple>, greater<>> pq;
    fill(dist, dist + 1001, INF);
    fill(pathCnt, pathCnt + 1001, INF);
    fill(dp, dp + 1000, INF);
    dist[S] = 0;
    pq.emplace(0, 0, S);

    while (!pq.empty()) {
        long long cost;
        int cur, cnt;
        tie(cost, cnt, cur) = pq.top();
        pq.pop();

        if (cost < dist[cur] || cnt < pathCnt[cur]) {
            dist[cur] = cost;
            pathCnt[cur] = cnt;

            if (cur == D) {
                dp[cnt] = min(dp[cnt], cost);
                continue;
            }

            for (auto pr : graph[cur]) {
                int nxt = pr.first;
                long long ncost = pr.second + cost;
                int ncnt = cnt + 1;
                if (ncnt >= 1000) continue;

                if (ncost < dist[nxt] || ncnt < pathCnt[nxt]) {
                    pq.emplace(ncost, ncnt, nxt);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K >> S >> D;
    while (M--) {
        cin >> a >> b >> w;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }

    dijkstra();

    for (int i = 0; i < N; ++i) {
        if (dp[i] != INF && dp[i] < ans) ans = dp[i];
    }
    cout << ans << '\n';

    for (int i = 1; i <= K; ++i) {
        cin >> p;
        ans = INF;
        for (int j = 1; j < N; ++j) {
            if (dp[j] == INF) continue;
            if((dp[j] += j * p) < ans) ans = dp[j];
        }
        cout << ans << '\n';
    }

    return 0;
}