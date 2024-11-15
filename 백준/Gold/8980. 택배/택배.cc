#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int N, C, M, U, V, W, ans;
tuple<int, int, int> arr[10000];
int capacity[2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C >> M;
    for (int i = 0; i < M; i++) {
        cin >> U >> V >> W;
        arr[i] = { V, U, W };
    }

    sort(arr, arr + M);
    fill(capacity, capacity + N + 1, C);

    for(int i = 0; i < M; i++) {
        int U, V, W;
        tie(V, U, W) = arr[i];
        
        int val = W;
        for(int j = U; j < V; j++) {
            val = min(val, capacity[j]);
        }
        
        for(int j = U; j < V; j++) {
            capacity[j] -= val;
        }
        
        ans += val;
    }

    cout << ans;
    return 0;
}