#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int T, N, Q, x;
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		cout << '#' << tc << ' ';

		priority_queue<int> pq;

		while (N--) {
			cin >> Q;
			if (Q == 1) {
				cin >> x;
				pq.push(x);
			}
			else {
				cout << (!pq.empty() ? pq.top() : -1) << ' ';
				if (!pq.empty()) pq.pop();
			}
		}
		
		cout << '\n';
	}

	return 0;
}