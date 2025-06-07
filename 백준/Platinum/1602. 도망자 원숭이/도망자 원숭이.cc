#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N, M, Q, a, b, d, S, T;
pair<int, int> times[501];
int originTimes[501];
int graph[501][501];
int maxNode[501][501];

auto getMaxNode = [](int n1, int n2) {
    return (originTimes[n1] >= originTimes[n2]) ? n1 : n2;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> times[i].first;
        originTimes[i] = times[i].first;
        times[i].second = i;
    }

    while (M--) {
        cin >> a >> b >> d;
        int mx = getMaxNode(a, b);
        graph[a][b] = d;
        graph[b][a] = d;
        maxNode[a][b] = mx;
        maxNode[b][a] = mx;
    }
    sort(times + 1, times + N + 1);

    for (int l = 1; l <= N; ++l) {
        int k = times[l].second;

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (i == j || !graph[i][k] || !graph[k][j]) continue;

                if (!graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    maxNode[i][j] = getMaxNode(maxNode[i][k], maxNode[k][j]);
                }
                else {
                    int mx = getMaxNode(getMaxNode(maxNode[i][k], maxNode[k][j]), maxNode[i][j]);
                    int e1 = graph[i][j] + originTimes[maxNode[i][j]];
                    int e2 = graph[i][k] + graph[k][j] + originTimes[mx];

                    if (e1 > e2) {
                        graph[i][j] = e2 - originTimes[mx];
                        maxNode[i][j] = mx;
                    }
                }
            }
        }
    }

    while (Q--) {
        cin >> S >> T;
        if (!graph[S][T]) cout << -1 << '\n';
        else cout << graph[S][T] + originTimes[maxNode[S][T]] << '\n';
    }

    return 0;
}