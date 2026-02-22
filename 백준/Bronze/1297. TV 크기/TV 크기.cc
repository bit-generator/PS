#include <iostream>
#include <cmath>
using namespace std;

int D, H, W;

inline static int square(int x) { return x * x; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> D >> H >> W;
    double ansH = (double)square(D) * square(H) / (square(H) + square(W));
    double ansW = (double)square(D) * square(W) / (square(H) + square(W));
    cout << (int)sqrt(ansH) << ' ' << (int)sqrt(ansW);
    return 0;
}