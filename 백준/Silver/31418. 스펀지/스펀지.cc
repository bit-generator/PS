#include <iostream>
#include <algorithm>
using namespace std;

int W, H, K, T, x, y;
long long ans = 1;
constexpr int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> W >> H >> K >> T;
    for(int i = 0; i < K; ++i) {
        cin >> x >> y;
        int a = min(T, x - 1) + min(T, W - x) + 1;
        int b = min(T, y - 1) + min(T, H - y) + 1;
        long long cnt = ((long long)a * b) % MOD;
        ans = (ans * cnt) % MOD;
    }
    
    cout << ans;
    return 0;
}