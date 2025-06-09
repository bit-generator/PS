#include <iostream>
using namespace std;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    if(n <= k + 60) {
        cout << n * 1500;
    }
    else {
        cout << (k + 60) * 1500 + (n - k - 60) * 3000;
    }
    
    return 0;
}