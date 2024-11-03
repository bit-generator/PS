#include <iostream>
#include <algorithm>
using namespace std;

int T;
long long N, base, ans;
int dp[5] = { 0, 1, 1, 2, 2 };

long long solve(long long n) {
    if (n <= 4) return dp[n];
    
    long long base = 5, ans = 2;
    while(base <= n) {
        ans *= 2;
        base += ans;
    }
    
    if(n < base - ans / 2) {
        return base - ans - ans / 2;
    }
    else {
        return n - ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N;
        if (N <= 4) {
            cout << dp[N] << '\n';
            continue;
        }
        
        base = 5, ans = 3;
        while(base * 2 - 1 <= N) {
            base = base * 2 - 1;
            ans = ans * 2 - 1;
        }
        
        ans = ans + solve(N - base + 1) - 1;
        cout << ans << '\n';
    }

    return 0;
}