#include <iostream>
using namespace std;

constexpr size_t MAX_SIZE = 1025;
int N, M, W, X1, Y1, X2, Y2, C;
int tree[MAX_SIZE * 4][MAX_SIZE * 4];
int arr[MAX_SIZE][MAX_SIZE];

int init_row(int col, int start_c, int last_c, int start, int last, int node) {
    if (start == last) {
        if(start_c == last_c) return tree[node][col] = arr[start][start_c];
        else return tree[node][col] = tree[node][col * 2] + tree[node][col * 2 + 1];
    }
    
    int mid = (start + last) / 2;
    return tree[node][col] = init_row(col, start_c, last_c, start, mid, node * 2)
        + init_row(col, start_c, last_c, mid + 1, last, node * 2 + 1);
}

void init(int start, int last, int node) {
    if (start != last) {
        int mid = (start + last) / 2;
        init(start, mid, node * 2);
        init(mid + 1, last, node * 2 + 1);
    }
    
    init_row(node, start, last, 1, N, 1);
}

int update_row(int row, int col, int start_c, int last_c, int start, int last, int node, int val) {
    if (row < start || last < row) return tree[node][col];
    if (start == last) {
        if(start_c == last_c) return tree[node][col] = val;
        else return tree[node][col] = tree[node][col * 2] + tree[node][col * 2 + 1];
    }

    int mid = (start + last) / 2;
    return tree[node][col] = update_row(row, col, start_c, last_c, start, mid, node * 2, val)
        + update_row(row, col, start_c, last_c, mid + 1, last, node * 2 + 1, val);
}

void update(int row, int col, int start, int last, int node, int val) {
    if (col < start || last < col) return;
    if (start != last) {
        int mid = (start + last) / 2;
        update(row, col, start, mid, node * 2, val);
        update(row, col, mid + 1, last, node * 2 + 1, val);
    }

    update_row(row, node, start, last, 1, N, 1, val);
}

int sum_row(int col, int start, int last, int node, int l, int r) {
    if (r < start || last < l) return 0;
    if (l <= start && last <= r) return tree[node][col];

    int mid = (start + last) / 2;
    return sum_row(col, start, mid, node * 2, l, r)
        + sum_row(col, mid + 1, last, node * 2 + 1, l, r);
}

int sum(int start, int last, int node, int lx, int rx, int ly, int ry) {
    if (ry < start || last < ly) return 0;
    if (ly <= start && last <= ry) return sum_row(node, 1, N, 1, lx, rx);

    int mid = (start + last) / 2;
    return sum(start, mid, node * 2, lx, rx, ly, ry)
        + sum(mid + 1, last, node * 2 + 1, lx, rx, ly, ry);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> arr[i][j];
        }
    }

    init(1, N, 1);

    while (M--) {
        cin >> W;
        if (W) {
            cin >> X1 >> Y1 >> X2 >> Y2;
            cout << sum(1, N, 1, X1, X2, Y1, Y2) << '\n';
        }
        else {
            cin >> X1 >> Y1 >> C;
            update(X1, Y1, 1, N, 1, C);
        }
    }

    return 0;
}