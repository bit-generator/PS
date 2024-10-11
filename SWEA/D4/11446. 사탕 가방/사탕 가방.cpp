#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
long long M, maxVal, ans;
long long A[100];

bool solve(long long target) {
	if (target == 0) {
		return true;
	}
	long long sum = 0;

	for (int i = 0; i < N; i++) {
		sum += (A[i] / target);
	}

	return sum >= M;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;
		maxVal = 0;
		ans = 0;
		
		for (int i = 0; i < N; i++) {
			cin >> A[i];
			maxVal = max(A[i], maxVal);
		}

		long long start = 0, last = maxVal;
		while (start <= last) {
			long long mid = (start + last) / 2;
			if (solve(mid)) {
				ans = mid;
				start = mid + 1;
			}
			else {
				last = mid - 1;
			}
		}

		cout << '#' << tc << ' ' << ans << '\n';
	}
	return 0;
}