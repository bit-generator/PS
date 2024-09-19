#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M, A, B, maxCnt;
vector<int> graph[10001];
vector<int> ans;
bool visit[10001];

int bfs(int x) {
    queue<int> q;
    memset(visit, 0, sizeof(bool) * (N + 1));
    q.push(x);
    visit[x] = true;
    int cnt = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur]) {
            if (visit[nxt]) continue;
            q.push(nxt);
            visit[nxt] = true;
            cnt++;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    while (M--) {
        cin >> A >> B;
        graph[B].push_back(A);
    }

    for (int i = 1; i <= N; i++) {
        int cnt = bfs(i);
        if (maxCnt < cnt) {
            maxCnt = cnt;
            ans.clear();
            ans.push_back(i);
        }
        else if (maxCnt == cnt) {
            ans.push_back(i);
        }
    }

    for (int x : ans) cout << x << ' ';
    return 0;
}