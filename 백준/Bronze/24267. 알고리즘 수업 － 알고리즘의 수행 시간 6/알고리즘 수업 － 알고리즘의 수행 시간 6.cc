#include <iostream>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    cout << (long long)n * (n - 1) * (n - 2) / 6 << '\n' << 3;
    return 0;
}