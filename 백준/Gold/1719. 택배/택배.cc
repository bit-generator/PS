#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a, b, c;
int graph[201][201];
int path[201][201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
        path[a][b] = b;
        path[b][a] = a;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) continue;
                if (!graph[i][k] || !graph[k][j]) continue;
                if (!graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    path[i][j] = path[i][k];
                    path[j][i] = path[j][k];
                }
                else if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    path[i][j] = path[i][k];
                    path[j][i] = path[j][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (path[i][j]) cout << path[i][j];
            else cout << '-';
            cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}