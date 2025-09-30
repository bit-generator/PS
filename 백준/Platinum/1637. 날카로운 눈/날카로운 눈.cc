#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long start = 1, last, ans;
long long seq[20000][3];

long long getSum(long long target) {
    long long sum = 0;
    
    for(int i = 0; i < N; ++i) {
        if(target < seq[i][0]) continue;
        sum += ((min(seq[i][1], target) - seq[i][0]) / seq[i][2] + 1);
    }
    
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> seq[i][0] >> seq[i][1] >> seq[i][2];
        last = max(last, seq[i][1]);
    }
    
    while(start <= last) {
        long long mid = (start + last) >> 1;
        if(getSum(mid) % 2) {
            last = mid - 1;
            ans = mid;
        }
        else {
            start = mid + 1;
        }
    }
    
    if(ans == 0) cout << "NOTHING";
    else cout << ans << ' ' << getSum(ans) - getSum(ans - 1);
    return 0;
}