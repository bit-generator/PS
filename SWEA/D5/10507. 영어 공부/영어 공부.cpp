#include <iostream>
#include <cstring>
using namespace std;

int T, n, p, d, dayEnd, ans;
bool days[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> p;
		memset(days, 0, sizeof(bool) * 1000001);

		for (int i = 0; i < n; i++) {
			cin >> d;
			days[d] = 1;
			if (i == n - 1) dayEnd = d;
		}

		int start = 1, last = 1;
		ans = p + 1;

		while (last <= dayEnd) {
			if (days[last] == 0) {
				if (p == 0) {
					ans = ans < last - start ? last - start : ans;
					if (days[start++] == 0) p++;
				}
				else {
					p--;
					last++;
				}
			}
			else {
				last++;
                ans = ans < last - start ? last - start : ans;
			}
		}

		cout << '#' << tc << ' ' << ans << '\n';
	}
	
	return 0;
}