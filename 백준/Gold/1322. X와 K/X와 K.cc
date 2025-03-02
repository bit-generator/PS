#include <iostream>
using namespace std;

int K;
long long X, Y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> X >> K;
    for (int i = 0; i < 32; ++i) {
        int idx = 0;
        while (X & (1LL << idx)) ++idx;
        X |= (1LL << idx);
        Y |= (((K & (1LL << i)) >> i) << idx);
    }

    cout << Y;
    return 0;
}