#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

int N, C, M, U, V, W, ans;
tuple<int, int, int> arr[10001];
queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C >> M;
    for (int i = 0; i < M; i++) {
        cin >> U >> V >> W;
        arr[i] = { V, U, W };
    }

    sort(arr, arr + M);

    int idx = 0;
    int load = 0, leftover = 0;

    for (int cur = 1; cur <= N; ++cur) {
        while (!q.empty() && q.front().first <= cur) {
            ans += q.front().second;
            load -= q.front().second;
            q.pop();
        }

        while (get<1>(arr[idx]) < cur) ++idx;
		while (idx < M && load < C) {
			if (load + get<2>(arr[idx]) <= C) {
				load += get<2>(arr[idx]);
				q.emplace(get<0>(arr[idx]), get<2>(arr[idx]));
				++idx;
			}
			else {
				get<2>(arr[idx]) = load + get<2>(arr[idx]) - C;
				q.emplace(get<0>(arr[idx]), C - load);
				load = C;
			}
		}
    }

    cout << ans;
    return 0;
}