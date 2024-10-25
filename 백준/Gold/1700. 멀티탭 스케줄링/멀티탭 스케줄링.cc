#include <iostream>
#include <set>
using namespace std;

int N, K, ans;
int order[100];
set<int> s;

int getLast(int idx, int n) {
    for (int i = idx; i <= K; i++) {
        if (i == K || order[i] == n) return i;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> order[i];
    }

    for (int i = 0; i < K; i++) {
        if (s.find(order[i]) != s.end()) continue;

        if (s.size() < N) {
            s.insert(order[i]);
        }
        else {
            int maxLast = 0;
            int maxIdx = 0;
            for (int n : s) {
                int last = getLast(i + 1, n);
				if (last > maxLast) {
					maxLast = last;
					maxIdx = n;
				}
            }

            s.erase(maxIdx);
            s.insert(order[i]);
            ans++;
        }
    }

    cout << ans;
    return 0;
}