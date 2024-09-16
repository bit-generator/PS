#include <iostream>
#include <algorithm>
using namespace std;

int T, N, K;
int V[100], C[100];
int dp[1001][100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> V[i] >> C[i];
		}

		for (int i = 1; i <= K; i++) {
			if (i < V[0]) dp[i][0] = 0;
			else dp[i][0] = C[0];
		}

		for (int i = 1; i < N; i++) {
			for (int j = 1; j <= K; j++) {
				if (j - V[i] < 0) dp[j][i] = dp[j][i - 1];
				else dp[j][i] = max(dp[j][i - 1], dp[j - V[i]][i - 1] + C[i]);
			}
		}

		cout << '#' << tc << ' ' << dp[K][N - 1] << '\n';
	}

	return 0;
}