#include <iostream>
#include <algorithm>
#define MOD    1'000'000
#define PERIOD    15'000'000
using namespace std;

long long n;
int dp[PERIOD];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    dp[1] = 1;
    int bnd = n % PERIOD;
    for(int i = 2; i <= bnd; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    
    cout << dp[bnd];
    return 0;
}