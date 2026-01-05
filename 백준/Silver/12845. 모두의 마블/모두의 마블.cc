#include <iostream>
#include <numeric>
using namespace std;

int n, maxValue, maxIdx;
int L[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> L[i];
        if(maxValue < L[i]) {
            maxValue = L[i];
            maxIdx = i;
        }
    }
    
    if(n == 1) cout << 0;
    else cout << accumulate(L, L + n, 0) + maxValue * (n - 2);
    return 0;
}