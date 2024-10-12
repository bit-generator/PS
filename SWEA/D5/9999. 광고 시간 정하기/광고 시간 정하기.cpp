#include <iostream>
#include <algorithm>
using namespace std;

int T, L, N, ans;
pair<int, int> ads[100000];
int totalAds[100000];

int upperBound(int x) {
	int ret = N;
	int start = 0, last = N - 1;
	while (start <= last) {
		int mid = (start + last) / 2;
		if (ads[mid].second > x) {
			ret = mid;
			last = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> L >> N;
		for (int i = 0; i < N; i++) {
			cin >> ads[i].first >> ads[i].second;
			if (i == 0) totalAds[i] = ads[i].second - ads[i].first;
			else totalAds[i] = totalAds[i - 1] + (ads[i].second - ads[i].first);
		}
		ans = 0;

		for (int i = 0; i < N; i++) {
			int len = ads[i].first + L;
			int endIdx = upperBound(len);
			int sum = totalAds[endIdx - 1];

			if (i != 0) {
				sum -= totalAds[i - 1];
			}

			if (endIdx != N && len > ads[endIdx].first) {
				sum += (len - ads[endIdx].first);
			}

			ans = max(ans, sum);
		}

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}
