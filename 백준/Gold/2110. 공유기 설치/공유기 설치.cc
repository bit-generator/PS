#include <iostream>
#include <algorithm>
using namespace std;

int N, C, ans;
int arr[200000];

bool solve(int target) {
	int start = 0, last = 1;
	int cnt = 1;

	while (last < N) {
		if (arr[last] - arr[start] >= target) {
			cnt++;
			start = last;
		}

		last++;
	}

	return cnt >= C;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> C;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	int start = 1, last = arr[N - 1] - arr[0];
	while (start <= last) {
		int mid = (start + last) / 2;
		if (solve(mid)) {
			ans = mid;
			start = mid + 1;
		}
		else {
			last = mid - 1;
		}
	}

	cout << ans;
	return 0;
}