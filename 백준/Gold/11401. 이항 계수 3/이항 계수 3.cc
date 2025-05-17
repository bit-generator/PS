#include <iostream>
#define MOD    1'000'000'007
using namespace std;

int N, K;
long long ans = 1, dv = 1;

long long pow(long long d, int x) {
    if(x == 1) return d;
    long long tmp = pow(d, x / 2);
    if(x % 2) {
        return ((tmp * tmp) % MOD * d) % MOD;
    }
    else {
        return (tmp * tmp) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    for(int i = K + 1; i <= N; ++i) ans = (ans * i) % MOD;
    for(int i = 1; i <= N - K; ++i) dv = (dv * i) % MOD;
    
    ans = (ans * pow(dv, MOD - 2)) % MOD;
    cout << ans;
    return 0;
}