#include <iostream>
using namespace std;

constexpr size_t MOD = 1'000'000'007;
int N, M, K, a, b, c;
int arr[1'000'000];
int segtree[2'000'000];

void init() {
    for (int i = 0; i < N; ++i) {
        segtree[i + N] = arr[i];
    }

    for (int i = N - 1; i >= 0; --i) {
        segtree[i] = ((long long)segtree[i << 1] * segtree[i << 1 | 1]) % MOD;
    }
}

void update(int idx, int value) {
    segtree[idx += N] = value;

    while (idx >>= 1) {
        segtree[idx] = ((long long)segtree[idx << 1] * segtree[idx << 1 | 1]) % MOD;
    }
}

int query(int l, int r) {
    int ret = 1;
    for (l += N, r += N; l != r; l >>= 1, r >>= 1) {
        if (l & 1) ret = ((long long)ret * segtree[l++]) % MOD;
        if (r & 1) ret = ((long long)ret * segtree[--r]) % MOD;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    init();

    for (int i = 0; i < M + K; ++i) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(b - 1, c);
        }
        else {
            cout << query(b - 1, c) << '\n';
        }
    }

    return 0;
}