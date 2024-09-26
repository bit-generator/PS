#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
long long zeroValue = 31e8;
int arr[5000];
int ans[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N);

	for (int i = 0; i < N - 2; i++) {
		int start = i + 1, last = N - 1;

		while (start < last) {
			long long sum = (long long)arr[i] + arr[start] + arr[last];
			if (abs(sum) < zeroValue) {
				ans[0] = arr[i];
				ans[1] = arr[start];
				ans[2] = arr[last];
				zeroValue = abs(sum);
			}

			if (sum == 0) {
				break;
			}
			else if (sum > 0) {
				last--;
			}
			else {
				start++;
			}
		}
	}
	
	for (int i = 0; i < 3; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}