#include <iostream>
using namespace std;

int T, A, B, C, K;

int pow(int cnt) {
	long long twos = 2;
	long long ret = 1;

	while (cnt > 0) {
		if (cnt % 2 == 1) {
			ret = (ret * twos) % C;
		}

		twos = (twos * twos) % C;
		cnt /= 2;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> A >> B >> K;
		C = A + B;
		long long res = ((long long)A * pow(K)) % C;
		cout << '#' << tc << ' ';
		if (res > C / 2) cout << C - res;
		else cout << res;
		cout << '\n';
	}

	return 0;
}