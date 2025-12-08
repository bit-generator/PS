#include <iostream>
#include <algorithm>
using namespace std;

int N, L, H, ans;
pair<int, int> arr[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + N);

    int left = 0, i = 1;
    int leftH = arr[0].second;
    while (i < N) {
        while (i < N && leftH > arr[i].second) ++i;
        if (i >= N) continue;

        ans += ((arr[i].first - arr[left].first) * leftH);
        left = i;
        leftH = arr[i].second;
        ++i;
    }
    ans += leftH;

    int right = N - 1;
    i = N - 2;
    int rightH = arr[N - 1].second;
    while (left <= i) {
        while (left <= i && rightH > arr[i].second) --i;
        if (left > i) continue;

        ans += ((arr[right].first - arr[i].first) * rightH);
        right = i;
        rightH = arr[i].second;
        --i;
    }

    cout << ans;
    return 0;
}