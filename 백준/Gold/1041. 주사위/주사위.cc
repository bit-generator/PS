#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[6];
long long side1 = 51, side2 = 101, side3 = 151;
int AF = 0b100001, BE = 0b10010, CD = 0b1100;
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < 6; ++i) {
        cin >> arr[i];
        side1 = min(side1, arr[i]);
    }

    if (N == 1) {
        int mx = 0;
        for (int i = 0; i < 6; ++i) {
            ans += arr[i];
            mx = max(mx, (int)arr[i]);
        }

        cout << ans - mx;
        return 0;
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 6; ++j) {
            int mask = (1 << i) | (1 << j);
            if ((mask & AF) == AF || (mask & BE) == BE || (mask & CD) == CD) continue;
            side2 = min(side2, arr[i] + arr[j]);

            for (int k = j + 1; k < 6; ++k) {
                mask |= (1 << k);
                if ((mask & AF) == AF || (mask & BE) == BE || (mask & CD) == CD) {
                    mask &= ~(1 << k);
                    continue;
                }

                side3 = min(side3, arr[i] + arr[j] + arr[k]);
                mask &= ~(1 << k);
            }
        }
    }

    ans += (side3 * 4 + side2 * 4);
    if (N >= 3) {
        ans += (side2 * 8 * (N - 2) + side1 * 4 * (N - 2));
        ans += (side1 * 5 * (N - 2) * (N - 2));
    }

    cout << ans;
    return 0;
}