#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, diff = 2'000'000'001, ans1, ans2;
int arr[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);
    
    int start = 0, last = N - 1;
    while(start < last) {
        int tmp = abs(arr[start] + arr[last]);
        if(tmp < diff) {
            diff = tmp;
            ans1 = arr[start];
            ans2 = arr[last];
        }
        
        if(arr[start] + arr[last] < 0) {
            ++start;
        }
        else {
            --last;
        }
    }
    
    cout << ans1 << ' ' << ans2;
    return 0;
}