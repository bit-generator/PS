#include <iostream>
using namespace std;

int N, K, cnt, ans = -1;
int arr[500000], tmp[500000];

void merge(int p, int q, int r) {
    int i = p, j = q + 1, t = 0;
    while(i <= q && j <= r) {
        if(arr[i] <= arr[j]) {
            tmp[t++] = arr[i++];
        }
        else {
            tmp[t++] = arr[j++];
        }
    }
    
    while(i <= q) tmp[t++] = arr[i++];
    while(j <= r) tmp[t++] = arr[j++];
    i = p, t = 0;
    while(i <= r) {
        int num = tmp[t];
        arr[i++] = tmp[t++];
        if(++cnt == K) {
            ans = num;
        }
    }
}

void merge_sort(int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        merge_sort(p, q);
        merge_sort(q + 1, r);
        merge(p, q, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    for(int i = 0; i < N; ++i) cin >> arr[i];
    
    merge_sort(0, N - 1);
    cout << ans;
    return 0;
}