#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int T, N, M, ans;
string A, B;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;

		ans = 0;
		unordered_set<string> us;

		for (int i = 0; i < N; i++) {
			cin >> A;
			us.insert(A);
		}

		for (int i = 0; i < M; i++) {
			cin >> B;
			if (us.find(B) != us.end()) ans++;
		}
		
		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}