#include <iostream>
#include <algorithm>
using namespace std;

constexpr size_t MAX_SIZE = 100001;
constexpr size_t MAX_VAL = 1'000'000'001;
int N, M, a, b, c;
int A[MAX_SIZE];
int tree[MAX_SIZE * 4 + 5];

int init(int start, int last, int node) {
    if(start == last) return tree[node] = start;
    int mid = (start + last) / 2;
    int idx1 = init(start, mid, node * 2);
    int idx2 = init(mid + 1, last, node * 2 + 1);
    if(A[idx1] == A[idx2]) {
        return tree[node] = min(idx1, idx2);
    }
    else {
        return tree[node] = (A[idx1] < A[idx2] ? idx1 : idx2);
    }
}

int update(int start, int last, int node, int idx) {
    if(idx < start || last < idx || start == last) return tree[node];
    
    int mid = (start + last) / 2;
    int idx1 = update(start, mid, node * 2, idx);
    int idx2 = update(mid + 1, last, node * 2 + 1, idx);
    if(A[idx1] == A[idx2]) {
        return tree[node] = min(idx1, idx2);
    }
    else {
        return tree[node] = (A[idx1] < A[idx2] ? idx1 : idx2);
    }
}

int query(int start, int last, int node, int l, int r) {
    if(r < start || last < l) return 0;
    if(l <= start && last <= r) return tree[node];
    int mid = (start + last) / 2;
    int idx1 = query(start, mid, node * 2, l, r);
    int idx2 = query(mid + 1, last, node * 2 + 1, l, r);
    if(A[idx1] == A[idx2]) {
        return min(idx1, idx2);
    }
    else {
        return (A[idx1] < A[idx2] ? idx1 : idx2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> A[i];
    init(1, N, 1);
    A[0] = MAX_VAL;
    
    cin >> M;
    while(M--) {
        cin >> a >> b >> c;
        if(a == 1) {
            A[b] = c;
            update(1, N, 1, b);
        }
        else {
            cout << query(1, N, 1, b, c) << '\n';
        }
    }
    
    return 0;
}