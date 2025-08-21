#include <iostream>
using namespace std;

int N;
long long ans;
int arr[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    
    int cnt = 0;
    for(int i = 1; i <= N; ++i) {
        if(arr[i] > arr[i - 1]) {
            ++cnt;
        }
        else {
            cnt = 1;
        }
        
        ans += cnt;
    }
    
    cout << ans;
    return 0;
}