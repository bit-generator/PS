#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 1;
int boxes[1000];
int dp[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> boxes[i];
    
    for(int i = 0; i < n; ++i) {
        dp[i] = 1;
        for(int j = 0; j < i; ++j) {
            if(boxes[j] < boxes[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }
    
    cout << ans;
    return 0;
}