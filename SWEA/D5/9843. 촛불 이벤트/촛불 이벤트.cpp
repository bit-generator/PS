#include <iostream>
#define SUM(X)	(((X) * ((X) + 1)) / 2)
using namespace std;

int T, ans;
long long N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		long long start = 0, last = 10e9;
		ans = -1;

		while (start <= last) {
			long long mid = (start + last) / 2;
			long long sum = SUM(mid);
			if (sum == N) {
				ans = mid;
				break;
			}
			else if (sum < N) {
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