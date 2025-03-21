#include <iostream>
using namespace std;

long long N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    cout << (((N * (N + 1)) >> 1) * 5 - (((N - 1) * (N - 1)) + ((N - 1) << 1))) % 45678;
    return 0;
}