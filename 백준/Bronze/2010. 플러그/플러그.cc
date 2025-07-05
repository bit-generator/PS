#include <iostream>
using namespace std;

int N, M, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> M;
        ans += M;
    }
    
    cout << ans - (N - 1);
    return 0;
}