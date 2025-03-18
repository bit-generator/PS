#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][1001];
int sum[1001][1001];
int human[1001][1001];
int m, n, a, b, ans = 1'000'000'000;

int isHuman(int x, int y, int ret) {
    if (arr[x][y] == -1) return ret;
    return 0;
}

int isNotHuman(int x, int y, int ret) {
    if (arr[x][y] != -1) return ret;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + isNotHuman(i, j, arr[i][j]) - sum[i - 1][j - 1];
            human[i][j] = human[i][j - 1] + human[i - 1][j] + isHuman(i, j, 1) - human[i - 1][j - 1];

            if (i >= b && j >= a
                && !(human[i][j] - human[i - b][j] - human[i][j - a] + human[i - b][j - a])) {
                ans = min(ans, sum[i][j] - sum[i - b][j] - sum[i][j - a] + sum[i - b][j - a]);
            }
        }
    }

    cout << ans;
    return 0;
}