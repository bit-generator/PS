#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int arr[2000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    sort(arr, arr + N);
    
    for(int i = 0; i < N; i++) {
        int start = 0, last = N - 1;
        
        while(start < last) {
            if(start == i) {
                start++;
                continue;
            }
            else if(last == i) {
                last--;
                continue;
            }
            
            int sum = arr[start] + arr[last];
            if(sum < arr[i]) {
                start++;
            }
            else if(sum > arr[i]) {
                last--;
            }
            else {
                ans++;
                break;
            }
        }
    }
    
    cout << ans;
    return 0;
}