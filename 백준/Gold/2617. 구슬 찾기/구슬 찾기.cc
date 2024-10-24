#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M, A, B, ans;
vector<int> graph[100], graph_r[100];
bool visit[100], visit_r[100];

int dfs(int cur) {
    int sum = 0;
    for (int nxt : graph[cur]) {
        if (visit[nxt]) continue;
        visit[nxt] = true;
        sum += (dfs(nxt) + 1);
    }

    return sum;
}

int dfs_r(int cur) {
    int sum = 0;
    for (int nxt : graph_r[cur]) {
        if (visit_r[nxt]) continue;
        visit_r[nxt] = true;
        sum += (dfs_r(nxt) + 1);
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    while (M--) {
        cin >> A >> B;
        graph[A].push_back(B);
        graph_r[B].push_back(A);
    }

    for (int i = 1; i <= N; i++) {
        memset(visit, 0, 100);
        memset(visit_r, 0, 100);
        visit[i] = true;
        int cnt = dfs(i);
        visit_r[i] = true;
        int cnt_r = dfs_r(i);

        if (cnt > N / 2 || cnt_r > N / 2) ans++;
    }

    cout << ans;
    return 0;
}