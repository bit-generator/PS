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
long long dist[1001][1000];

void dijkstra() {
    priority_queue<Tuple, vector<Tuple>, greater<>> pq;
    for (int i = 1; i <= N; ++i) {
        fill(dist[i], dist[i] + 1000, INF);
    }
    dist[S][0] = 0;
    pq.emplace(0, S, 0);

    while (!pq.empty()) {
        long long cost;
        int cur, cnt;
        tie(cost, cur, cnt) = pq.top();
        pq.pop();

        if (dist[cur][cnt] < cost) continue;

        for (auto pr : graph[cur]) {
            int nxt = pr.first;
            long long ncost = pr.second + cost;
            int ncnt = cnt + 1;
            if(ncnt >= 1000) continue;

            if (ncost < dist[nxt][ncnt]) {
                dist[nxt][ncnt] = ncost;
                pq.emplace(ncost, nxt, ncnt);
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
        if (dist[D][i] < ans) ans = dist[D][i];
    }
    cout << ans << '\n';

    for (int i = 1; i <= K; ++i) {
        cin >> p;
        ans = INF;
        for (int j = 1; j < N; ++j) dist[D][j] += j * p;
        for (int j = 0; j < N; ++j) if (dist[D][j] < ans) ans = dist[D][j];
        cout << ans << '\n';
    }

    return 0;
}