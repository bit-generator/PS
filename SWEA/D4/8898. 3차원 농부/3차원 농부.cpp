#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int T, N, M, c1, c2, minDiff, minCnt;
int z1[500000], z2[500000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> c1 >> c2;
		for (int i = 0; i < N; i++) cin >> z1[i];
		for (int i = 0; i < M; i++) cin >> z2[i];

		sort(z2, z2 + M);
		minDiff = 21e8;

		for (int i = 0; i < N; i++) {
			auto it = lower_bound(z2, z2 + M, z1[i]);
			int cnt = 0, diff = 21e8;
			if (it != z2 + M) {
				cnt = 1;
				diff = *it - z1[i];
			}

			if (it != z2) {
				it--;
                if(z1[i] - *it < diff) {
                    diff = z1[i] - *it;
                    cnt = 1;
                }
                else if(z1[i] - *it == diff) {
                    cnt = 2;
                }
			}

			if (diff < minDiff) {
				minDiff = diff;
				minCnt = cnt;
			}
			else if (diff == minDiff) {
				minCnt += cnt;
			}
		}

		cout << '#' << tc << ' ' << minDiff + abs(c2 - c1) << ' ' << minCnt << '\n';
	}

	return 0;
}
