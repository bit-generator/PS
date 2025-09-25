#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

long long N, X, Y, power;
int K, Q, depth;
long long bound[60];

int solve() {
    int dist = 0;
    if (X > Y) swap(X, Y);
    int depthX = lower_bound(bound, bound + depth, X) - bound;
    int depthY = lower_bound(bound, bound + depth, Y) - bound;

    long long childX = X - 1;
    long long childY = Y - 1;
    if (depthX > 0) childX -= bound[depthX - 1];
    if (depthY > 0) childY -= bound[depthY - 1];

    while (depthX != depthY) {
        childY /= K;
        --depthY;
        ++dist;
    }

    while (childX != childY) {
        childX /= K; childY /= K;
        dist += 2;
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> Q;
    if (K == 1) {
        while (Q--) {
            cin >> X >> Y;
            cout << abs(X - Y) << '\n';
        }
    }
    else {
        bound[0] = 1;
        power = 1;
        for (depth = 1; bound[depth - 1] < N; ++depth) {
            power *= K;
            bound[depth] = bound[depth - 1] + power;
        }

        while (Q--) {
            cin >> X >> Y;
            cout << solve() << '\n';
        }
    }

    return 0;
}