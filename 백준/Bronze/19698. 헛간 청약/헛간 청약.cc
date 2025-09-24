#include <iostream>
using namespace std;

int N, W, H, L;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> W >> H >> L;
    if((W / L) * (H / L) >= N) cout << N;
    else cout << (W / L) * (H / L);
    return 0;
}