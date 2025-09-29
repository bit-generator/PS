#include <iostream>
using namespace std;

int N, M, K, ans;
bool cnt[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(M--) {
        cin >> K;
        for(int i = K; i <= N; i += K) {
            cnt[i] = true;
        }
    }
    
    for(int i = 1; i <= N; ++i) {
        if(cnt[i]) ans += i;
    }
    
    cout << ans;
    return 0;
}