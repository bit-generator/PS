#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
using namespace std;
using Pair = pair<int, int>;
using Tuple = tuple<int, int, int>;

int N, M, ans = 21e8;
int arr[1000][1000];
priority_queue<Tuple, vector<Tuple>, greater<>> minpq;
priority_queue<int> maxpq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		sort(arr[i], arr[i] + M);
		minpq.emplace(arr[i][0], i, 0);
		maxpq.push(arr[i][0]);
	}

	while (true) {
		int mx = maxpq.top();
		int mn, r, c;
		tie(mn, r, c) = minpq.top();
		ans = min(ans, mx - mn);
		c++;

		if (c >= M) break;
		minpq.pop();
		minpq.emplace(arr[r][c], r, c);
		maxpq.push(arr[r][c]);
	}

	cout << ans;
	return 0;
}