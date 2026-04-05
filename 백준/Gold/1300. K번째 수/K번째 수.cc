#include <iostream>
#include <algorithm>
using namespace std;

long long N, k, target, ans;

long long solve(long long target) {
    long long cnt = 0;
    for (int i = 1; i <= N; ++i) {
        cnt += min(N, target / i);
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> k;

    long long start = 1, last = N * N;
    while (start <= last) {
        long long mid = (start + last) / 2;
        if (solve(mid) >= k) {
            ans = mid;
            last = mid - 1;
        }
        else start = mid + 1;
    }

    cout << ans;
    return 0;
}