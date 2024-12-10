#include <iostream>
using namespace std;

int N, K, A, B;
int start[1000001], fin[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    while (N--) {
        cin >> A >> B;
        ++start[A];
        ++fin[B];
    }

    int first = 0, last = 0;
    int sum1 = 0, sum2 = 0, inc1 = 0, inc2 = 0;
    for (last = 0; last <= 1000000; ++last) {
        sum2 += inc2;

        while (first <= 1000000 && sum2 - sum1 > K) {
            inc1 += (start[first] - fin[first]);
            ++first;
            sum1 += inc1;
        }

        if (sum2 - sum1 == K) {
            cout << first << ' ' << last;
            return 0;
        }

        inc2 += (start[last] - fin[last]);
    }

    cout << "0 0";
    return 0;
}