#include <iostream>
using namespace std;

int M, N, ans, sum;
bool isNotPrime[10001] = {true, true};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> M >> N;
    for(int i = 2; i * i <= N; ++i) {
        if(isNotPrime[i]) continue;
        for(int j = i + i; j <= N; j += i) {
            isNotPrime[j] = true;
        }
    }
    
    for(int i = M; i <= N; ++i) {
        if(!isNotPrime[i]) {
            if(sum == 0) ans = i;
            sum += i;
        }
    }
    
    if(ans == 0) cout << -1;
    else cout << sum << '\n' << ans;
    return 0;
}