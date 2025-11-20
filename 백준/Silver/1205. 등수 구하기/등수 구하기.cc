#include <iostream>
#include <algorithm>
using namespace std;

int N, M, P;
int arr[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> P;
    for(int i = 0; i < N; ++i) cin >> arr[i];
    int ans = lower_bound(arr, arr + N, M, greater<>()) - arr;
    int tmp = upper_bound(arr, arr + N, M, greater<>()) - arr;
    if(tmp >= P) cout << -1;
    else cout << ans + 1;
    return 0;
}