#include <iostream>
using namespace std;

constexpr size_t MAX_SIZE = 2'000'005;
int segtree[MAX_SIZE * 4];
int N, T, X;

void update(int node, int s, int e, int idx, int val) {
    if(idx < s || idx > e) return;
    if(s == e) {
        segtree[node] += val;
        return;
    }
    
    int mid = (s + e) >> 1;
    update(node << 1, s, mid, idx, val);
    update(node << 1 | 1, mid + 1, e, idx, val);
    segtree[node] = segtree[node << 1] + segtree[node << 1 | 1];
}

void insert(int x) {
    update(1, 1, MAX_SIZE, x, 1);
}

int get(int node, int s, int e, int k) {
    segtree[node] -= 1;
    if(s == e) return s;
    int l = segtree[node << 1];
    int mid = (s + e) >> 1;
    if(k <= l) {
        return get(node << 1, s, mid, k);
    }
    else {
        return get(node << 1 | 1, mid + 1, e, k - l);
    }
}

int query(int x) {
    return get(1, 1, MAX_SIZE, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    while(N--) {
        cin >> T >> X;
        if(T == 1) {
            insert(X);
        }
        else {
            cout << query(X) << '\n';
        }
    }
    
    return 0;
}