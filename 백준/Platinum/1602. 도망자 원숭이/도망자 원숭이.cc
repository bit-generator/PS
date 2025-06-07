#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

constexpr size_t INF = 1'000'000'000;
int N, M, Q, a, b, d, S, T;
pair<int, int> times[501];
int originTimes[501];
int graph[501][501];
int maxValue[501][501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> times[i].first;
        originTimes[i] = times[i].first;
        times[i].second = i;
    }

    for (int i = 1; i <= N; ++i) {
        fill(graph[i] + 1, graph[i] + N + 1, INF);
        graph[i][i] = 0;
    }

    while (M--) {
        cin >> a >> b >> d;
        int mx = (times[a].first > times[b].first) ? times[a].first : times[b].first;
        graph[a][b] = d;
        graph[b][a] = d;
        maxValue[a][b] = mx;
        maxValue[b][a] = mx;
    }
    sort(times + 1, times + N + 1);

    for (int l = 1; l <= N; ++l) {
        int k = times[l].second;

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                int mx = max(maxValue[i][k], maxValue[k][j]);
                int e1 = graph[i][j] + maxValue[i][j];
                int e2 = graph[i][k] + graph[k][j] + mx;

                if (e1 > e2) {
                    graph[i][j] = e2 - mx;
                    maxValue[i][j] = mx;
                }
            }
        }
    }

    while (Q--) {
        cin >> S >> T;
        if (graph[S][T] == INF) cout << -1 << '\n';
        else cout << graph[S][T] + maxValue[S][T] << '\n';
    }

    return 0;
}