#include <iostream>
#include <queue>
using namespace std;
using MaxPQ = priority_queue<int>;
using MinPQ = priority_queue<int, vector<int>, greater<>>;

int T, N, A, X, Y, ans;
int dp[1001][1001];

void enqueue(int x, MaxPQ& maxpq, MinPQ& minpq) {
	if (x < A) {
		if (maxpq.size() > minpq.size()) {
			maxpq.push(x);
			minpq.push(A);
			A = maxpq.top();
			maxpq.pop();
		}
		else {
			maxpq.push(x);
		}
	}
	else {
		if (maxpq.size() < minpq.size()) {
			minpq.push(x);
			maxpq.push(A);
			A = minpq.top();
			minpq.pop();
		}
		else {
			minpq.push(x);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> A;

		MaxPQ maxpq;
		MinPQ minpq;
		ans = 0;

		while (N--) {
			cin >> X >> Y;
			enqueue(X, maxpq, minpq);
			enqueue(Y, maxpq, minpq);
			ans = (ans + A) % 20171109;
		}
		
		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}