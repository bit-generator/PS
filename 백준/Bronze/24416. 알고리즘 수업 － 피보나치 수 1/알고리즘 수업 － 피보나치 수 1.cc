#include <iostream>
using namespace std;

int n, ans1, ans2;
int dp[41];

int fib(int x) {
    if(x == 1 || x == 2) {
        ++ans1;
        return 1;
    }
    else return fib(x - 1) + fib(x - 2);
}

void fibonacci(int x) {
    dp[1] = 1; dp[2] = 1;
    for(int i = 3; i <= x; ++i) {
        ++ans2;
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    fib(n);
    fibonacci(n);
    cout << ans1 << ' ' << ans2;
    return 0;
}