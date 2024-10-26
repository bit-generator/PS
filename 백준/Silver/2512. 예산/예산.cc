#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans;
int budget[10000];
int prefix[10000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; i++) cin >> budget[i];
    cin >> M;
    
    sort(budget, budget + N);
    for(int i = 0; i < N; i++) {
        if(i == 0) prefix[i] = budget[i];
        else prefix[i] = budget[i] + prefix[i - 1];
    }
    
    if(prefix[N - 1] <= M) {
        cout << budget[N - 1];
        return 0;
    }
    
    int start = 1, last = M;
    while(start <= last) {
        int mid = (start + last) / 2;
        int idx = upper_bound(budget, budget + N, mid) - budget;
        int sum = (N - idx) * mid;
        if(idx > 0) sum += prefix[idx - 1];
        
        if(sum == M) {
            ans = mid;
            break;
        }
        else if(sum > M) {
            last = mid - 1;
        }
        else {
            ans = mid;
            start = mid + 1;
        }
    }
    
    cout << ans;
    return 0;
}