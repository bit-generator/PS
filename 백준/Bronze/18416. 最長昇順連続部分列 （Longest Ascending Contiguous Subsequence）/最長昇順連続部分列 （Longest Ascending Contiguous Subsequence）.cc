#include <iostream>
#include <algorithm>
using namespace std;

int N, cnt = 1, ans = 1;
int arr[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> arr[i];
    
    
    for(int i = 1; i < N; ++i) {
        if(arr[i - 1] <= arr[i]) {
            ++cnt;
            ans = max(ans, cnt);
        }
        else cnt = 1;
    }
    
    cout << ans;
    return 0;
}