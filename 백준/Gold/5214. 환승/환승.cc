#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int N, K, M, A;
vector<int> tube[1000];
vector<int> station[100001];
bool visitTube[1000], visitStn[100001];

int bfs() {
	queue<pair<int, int>> q;
	q.emplace(1, 1);
	visitStn[1] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int score = q.front().second;
		q.pop();

		for (auto nxtTube : station[cur]) {
			if (visitTube[nxtTube]) continue;
			visitTube[nxtTube] = true;

			for (auto nxt : tube[nxtTube]) {
				if (visitStn[nxt]) continue;
				visitStn[nxt] = true;

				if (nxt == N) {
					return score + 1;
				}

				q.emplace(nxt, score + 1);
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> A;
			tube[i].emplace_back(A);
			station[A].emplace_back(i);
		}
	}

	if (N == 1) cout << 1;
	else cout << bfs();
	return 0;
}