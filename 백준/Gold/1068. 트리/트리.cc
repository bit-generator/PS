#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, P, R, A, ans;
vector<int> tree[50];
bool visit[50];

void bfs() {
    queue<int> q;
    q.push(R);
    visit[R] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        bool haveChild = false;

        for (int nxt : tree[cur]) {
            if (visit[nxt]) continue;
            q.push(nxt);
            visit[nxt] = true;
            haveChild = true;
        }

        if (!haveChild) ans++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P;
        if (P == -1) {
            R = i;
        }
        else {
            tree[P].push_back(i);
            tree[i].push_back(P);
        }
    }

    cin >> A;
    visit[A] = true;

    if (R != A) bfs();

    cout << ans;
    return 0;
}