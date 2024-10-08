#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, u, v;
vector<int> tree[1000001];
int dp[1000001][2];

void dfs(int cur, int prv) {
	dp[cur][1] = 1;
	for (int nxt : tree[cur]) {
		if (nxt == prv) continue;
		dfs(nxt, cur);
		dp[cur][0] += dp[nxt][1];
		dp[cur][1] += min(dp[nxt][0], dp[nxt][1]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(1, 0);
	cout << min(dp[1][0], dp[1][1]);
	return 0;
}