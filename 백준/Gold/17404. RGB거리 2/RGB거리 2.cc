#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000][3];
int dp[1000][3][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            dp[1][i][j] = arr[0][i] + arr[1][j];
        }
    }
    
    if (N >= 3) {
        for (int i = 0; i < 3; ++i) {
            dp[2][i][i] = min(dp[1][i][(i + 1) % 3], dp[1][i][(i + 2) % 3]) + arr[2][i];
            dp[2][i][(i + 1) % 3] = dp[1][i][(i + 2) % 3] + arr[2][(i + 1) % 3];
            dp[2][i][(i + 2) % 3] = dp[1][i][(i + 1) % 3] + arr[2][(i + 2) % 3];
        }

		for (int i = 3; i < N; ++i) {
			for (int j = 0; j < 3; ++j) {
				dp[i][j][0] = min(dp[i - 1][j][1], dp[i - 1][j][2]) + arr[i][0];
				dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + arr[i][1];
				dp[i][j][2] = min(dp[i - 1][j][0], dp[i - 1][j][1]) + arr[i][2];
			}
		}
    }

    cout << min({ dp[N - 1][0][1], dp[N - 1][0][2], dp[N - 1][1][0],
                dp[N - 1][1][2], dp[N - 1][2][0], dp[N - 1][2][1] });
    return 0;
}