#include <iostream>
using namespace std;

int N, K, M = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    for(int i = 0; i < N - 1; ++i) M <<= 1;
    cout << K / M;
    return 0;
}