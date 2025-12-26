#include <iostream>
using namespace std;

int N, K, P, X, ans;
int bits[10] = { 0b111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110,
               0b1101101, 0b1111101, 0b111, 0b1111111, 0b1101111 };

inline int pow10(int x) {
    int ret = 1;
    while (x--) ret *= 10;
    return ret;
}

void backtrack(int cnt, int seg, int num, int sum) {
    if (cnt == K) {
        if (sum == 0 || seg == P) return;
        ++ans;
        return;
    }

    int digit = num % 10;

    for (int i = 0; i < 10; ++i) {
        int exor = bits[digit] ^ bits[i];
        int bitcnt = 0;
        int tens = i * pow10(cnt);

        for (int j = 0; j < 7; ++j) {
            if (exor & (1 << j)) ++bitcnt;
        }

        if (seg - bitcnt < 0) continue;
        if (sum + tens > N) continue;
        backtrack(cnt + 1, seg - bitcnt, num / 10, sum + tens);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> P >> X;
    backtrack(0, P, X, 0);
    cout << ans;
    return 0;
}