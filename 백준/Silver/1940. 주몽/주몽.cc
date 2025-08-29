#include <iostream>
using namespace std;

int N, M, K, ans;
bool h[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        cin >> K;
        if(M - K <= 0 || M >= 200000) continue;
        if(!h[K]) {
            h[M - K] = true;
        }
        else {
            ++ans;
            h[K] = false;
        }
    }
    
    cout << ans;
    return 0;
}