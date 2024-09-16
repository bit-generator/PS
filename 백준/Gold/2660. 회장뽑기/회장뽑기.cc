#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, A, B, minScore = 50000;
vector<int> graph[51];
vector<int> candidate;
int visit[51];

int bfs(int x) {
    queue<int> q;
    memset(visit + 1, -1, sizeof(int) * N);

    q.push(x);
    visit[x] = 0;
    int score = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        score = visit[cur];

        for (int nxt : graph[cur]) {
            if (visit[nxt] != -1) continue;
            q.push(nxt);
            visit[nxt] = visit[cur] + 1;
        }
    }

    return score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    while (true) {
        cin >> A >> B;
        if (A == -1 && B == -1) break;

        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    for (int i = 1; i <= N; i++) {
        int score = bfs(i);
        if (minScore > score) {
            minScore = score;
            candidate.clear();
            candidate.push_back(i);
        }
        else if (minScore == score) {
            candidate.push_back(i);
        }
    }

    cout << minScore << ' ' << candidate.size() << '\n';
    for (int i : candidate) {
        cout << i << ' ';
    }
    return 0;
}