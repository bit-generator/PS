#include <iostream>
using namespace std;

int H, W, N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> H >> W >> N >> M;
    cout << ((H - 1) / (N + 1) + 1) * ((W - 1) / (M + 1) + 1);
    return 0;
}