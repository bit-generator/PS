#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    if (N == 0) {
        cout << 0;
        return 0;
    }

    while (N) {
        if (N % (-2) < 0) {
            N = N / (-2) + 1;
            v.push_back(1);
        }
        else {
            v.push_back(N % (-2));
            N /= (-2);
        }
    }

    for (int i = v.size() - 1; i >= 0; --i) {
        cout << v[i];
    }
    return 0;
}