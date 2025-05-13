#include <iostream>
#include <unordered_map>
using namespace std;

long long N;
int P, Q, X, Y;
unordered_map<long long, long long> dp;

long long solve(long long n) {
    if(dp.find(n) != dp.end()) {
        return dp[n];
    }
    
    if(n <= 0) return 1;
    dp[n] = solve(n / P - X) + solve(n / Q - Y);
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> P >> Q >> X >> Y;
    cout << solve(N);
    return 0;
}