#include <iostream>
#include <algorithm>
using namespace std;

int N, M, L, ans;
int servArea[50];

int find(int target) {
    int cur = 0, tmpM = M;
    int servIdx = 0;

    while (servIdx < N) {
        while (servArea[servIdx] - cur > target) {
            cur += target;
            tmpM--;
        }

        cur = servArea[servIdx];
        servIdx++;
    }

    while (L - cur > target) {
        cur += target;
        tmpM--;
    }

    return tmpM;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> L;
    for (int i = 0; i < N; i++) cin >> servArea[i];
    sort(servArea, servArea + N);

    int start = 1, last = L - 2;
    while (start <= last) {
        int mid = (start + last) / 2;
        int res = find(mid);
        if (res < 0) {
            start = mid + 1;
        }
        else {
            ans = mid;
            last = mid - 1;
        }
    }

    cout << ans;
    return 0;
}