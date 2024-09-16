#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T, len1, len2;
string s1, s2;
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> s1 >> s2;
		len1 = s1.length();
		len2 = s2.length();

		for (int i = 1; i <= len1; i++) {
			for (int j = 1; j <= len2; j++) {
				if (s1[i - 1] == s2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		cout << '#' << tc << ' ' << dp[len1][len2] << '\n';
	}

	return 0;
}