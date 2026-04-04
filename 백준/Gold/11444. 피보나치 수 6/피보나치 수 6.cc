#include <iostream>
#include <array>
using namespace std;
using arr22 = array<array<long long, 2>, 2>;

long long n;
arr22 M = {{ {1, 1}, {1, 0} }};
constexpr int MOD = 1'000'000'007;

arr22 times(arr22 A, arr22 B) {
    arr22 ret{};
    
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            for(int k = 0; k < 2; ++k) {
                ret[i][j] += ((A[i][k] * B[k][j]) % MOD);
            }
            
            ret[i][j] %= MOD;
        }
    }
    
    return ret;
}

arr22 pow(arr22 A, long long x) {
    if(x == 1) return A;
    
    arr22 ret = pow(A, x / 2);
    ret = times(ret, ret);
    
    if(x % 2) return times(ret, A);
    else return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    if(n == 1) {
        cout << 1;
        return 0;
    }
    
    arr22 fibo = pow(M, n - 1);
    cout << fibo[0][0];
    return 0;
}