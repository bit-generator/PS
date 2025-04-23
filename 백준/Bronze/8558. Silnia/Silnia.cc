#include <iostream>
using namespace std;

int n, ans = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        ans = (ans * i) % 10;
    }
    
    cout << ans;
    return 0;
}