#include <iostream>
#include <algorithm>
using namespace std;

int N, M, mx, ans;
int A[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> M;
        ++A[M];
        mx = max(mx, M);
    }
    
    for(int i = mx; i > 0; --i) {
        if(A[i] >= 2) ans += 2;
        else ans += A[i];
    }
    
    cout << ans;
    return 0;
}