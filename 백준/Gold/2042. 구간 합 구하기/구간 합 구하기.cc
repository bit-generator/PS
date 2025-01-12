#include <iostream>
using namespace std;

constexpr size_t SIZE = 1'000'000;
long long segtree[4 * SIZE];
long long arr[SIZE];
int N, M, K, a, b;
long long c;

long long init(int start, int last, int node) {
    if(start == last) return segtree[node] = arr[start];
    int mid = (start + last) / 2;
    return segtree[node] = init(start, mid, node * 2) + init(mid + 1, last, node * 2 + 1);
}

long long sum(int start, int last, int node, int l, int r) {
    if(l > last || r < start) return 0;
    if(l <= start && last <= r) return segtree[node];
    int mid = (start + last) / 2;
    return sum(start, mid, node * 2, l, r) + sum(mid + 1, last, node * 2 + 1, l, r);
}

void update(int start, int last, int node, int idx, long long diff) {
    if(idx < start || idx > last) return;
    segtree[node] += diff;
    if(start == last) return;
    int mid = (start + last) / 2;
    update(start, mid, node * 2, idx, diff);
    update(mid + 1, last, node * 2 + 1, idx, diff);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> K;
    for(int i = 0; i < N; ++i) cin >> arr[i];
    
    init(0, N - 1, 1);
    
    for(int i = 0; i < M + K; ++i) {
        cin >> a >> b >> c;
        if(a == 1) {
            update(0, N - 1, 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;
        }
        else {
            cout << sum(0, N - 1, 1, b - 1, (int)c - 1) << '\n';
        }
    }
    
    return 0;
}