#include <iostream>
#include <algorithm>
using namespace std;

int N, L, ans;
int arr[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> L;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    
    int start = 0, last = 0;
    while(last < N) {
        if(arr[last] - arr[start] + 1 <= L) {
            last++;
        }
        else {
            ans++;
            start = last;
        }
    }
    
    cout << ans + 1;
    return 0;
}