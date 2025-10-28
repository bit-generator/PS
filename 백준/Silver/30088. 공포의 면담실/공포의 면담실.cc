#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int arr[1000];
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> M;
        while (M--) {
            cin >> K;
            arr[i] += K;
        }
    }

    sort(arr, arr + N);
    for (int i = 0; i < N; ++i) {
        ans += (arr[i] * (N - i));
    }

    cout << ans;
    return 0;
}